#include "../SortArray.hpp"
#include <random>
#include <iostream>

using namespace std;

/**
 * @brief Swaps two elements in the array.
 * 
 * @tparam T 
 * @param arr Reference to the array
 * @param i Index of the first element
 * @param j Index of the second element
 */
template<typename T>
void swap(vector<T>& arr, int i, int j){
    T tmp = arr.at(i);
    arr.at(i) = arr.at(j);
    arr.at(j) = tmp;
}

/**
 * @brief Partitions the array around a pivot (last element),
 *        placing smaller elements to the left, and larger to the right.
 *        Complexity: Θ(n)
 * 
 * @tparam T 
 * @param arr Array to partition
 * @param p Start index
 * @param r End index
 * @return int Index of the pivot after partition
 */
template<typename T>
int partition(vector<T>& arr, int p, int r){
    T x = arr.at(r); // pivot
    int i = p - 1;
    for (size_t j = p; j < r; j++) {
        if (arr.at(j) <= x) {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, r);
    return i + 1;
}

/**
 * @brief Performs partitioning with a randomly chosen pivot
 *        for better average-case performance.
 * 
 * @tparam T 
 * @param arr Array to partition
 * @param p Start index
 * @param r End index
 * @return int Index of the pivot after partition
 */
template<typename T>
int random_partition(vector<T>& arr, int p, int r){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(p, r);
    int i = distrib(gen);
    swap(arr, i, r); // move random pivot to end
    return partition(arr, p, r);
}

/**
 * @brief Recursive QuickSort using a randomized pivot.
 * 
 * @tparam T 
 * @param arr Array to sort
 * @param p Start index
 * @param r End index
 * 
 * @details
 * Complexity:  
 *  - Worst Case: Θ(n²)  
 *  - Average Case: O(n log n)  
 *  - Best Case: Θ(n log n)
 */
template<typename T>
void random_quickSort(vector<T>& arr, int p, int r){
    if (p < r) {
        int q = random_partition(arr, p, r);
        random_quickSort(arr, p, q - 1);
        random_quickSort(arr, q + 1, r);
    }
}

/**
 * @brief Main function to demonstrate the randomized QuickSort.
 * 
 * @return int 
 */
int main(){
    Sort<int> sort;
    sort.printArr();

    cout << "------ Test ------" << endl;
    random_quickSort(sort.arr, 0, sort.arr.size() - 1);
    sort.printArr(); 

    return 0;
}