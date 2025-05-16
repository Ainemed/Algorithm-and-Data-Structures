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
 * @brief Incremental sorting algorithm (Insertion Sort), used for small subarrays.
 *        Complexity: Θ(n^2)
 * 
 * @tparam T 
 * @param arr Array to sort
 * @param p Start index
 * @param r End index
 */
template<typename T>
void insertion_sort(vector<T>& arr, int p, int r) {
    for (int i = p + 1; i <= r; ++i) {
        T key = arr[i];
        int j = i - 1;
        while (j >= p && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

/**
 * @brief Classic partition function used in QuickSort.
 *        Chooses last element as pivot and partitions the array.
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
    for (int j = p; j < r; j++) {
        if (arr.at(j) <= x) {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, r);
    return i + 1;
}

/**
 * @brief Randomized partition: selects a random pivot for better average-case performance.
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

// Threshold under which insertion sort is used
const int M = 16;

/**
 * @brief Optimized QuickSort using randomized pivot and insertion sort threshold.
 *        Complexity:
 *          - Worst case: Θ(n^2)
 *          - Average case: O(n log n)
 *          - Best case: Θ(n log n)
 * 
 * @tparam T 
 * @param arr Array to sort
 * @param p Start index
 * @param r End index
 */
template<typename T>
void optimized_quickSort(vector<T>& arr, int p, int r){
    if (r - p <= M) {
        return; // will be handled by final insertion sort
    }
    if (p < r) {
        int q = random_partition(arr, p, r);
        optimized_quickSort(arr, p, q - 1);
        optimized_quickSort(arr, q + 1, r);
    }
}

/**
 * @brief Wrapper for optimized QuickSort: applies QuickSort and then insertion sort.
 *        This guarantees better performance for small or nearly sorted arrays.
 * 
 * @tparam T 
 * @param arr Array to sort
 */
template<typename T>
void optimized_quickSort_wrapper(vector<T>& arr) {
    optimized_quickSort(arr, 0, arr.size() - 1);
    insertion_sort(arr, 0, arr.size() - 1);
}

/**
 * @brief Main test function: creates and sorts an array using the optimized quicksort.
 * 
 * @return int 
 */
int main(){
    Sort<int> sort;
    sort.printArr();

    cout << "------ Test ------" << endl;
    optimized_quickSort_wrapper(sort.arr);
    sort.printArr(); 
    
    return 0;
}