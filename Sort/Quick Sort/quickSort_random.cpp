#include "../SortArray.hpp"
#include <random>
template<typename T>
void swap(vector<T>& arr, int i, int j){
    T tmp = arr.at(i);
    arr.at(i) = arr.at(j);
    arr.at(j)=tmp;
}

template<typename T>
int partition(vector<T>& arr, int p, int r){
    T x = arr.at(r);
    int i = p-1;
    for (size_t j = p; j < r; j++)
    {
        if(arr.at(j) <= x){
            i++;
            swap(arr,i,j);
        }
    }
    swap(arr, i+1, r);
    return i+1;
}

template<typename T>
int random_partition(vector<T>& arr, int p, int r){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(p,r);

    int i = distrib(gen);

    swap(arr, i, r);

    return partition(arr, p, r);

    return 0;
}

template<typename T>
/**
 * @brief Complexity:  
 *          - Worst Case: Θ(n^2)
 *          - Average Case:  O(n log n)
 *          - Best Case:  Θ(n)
 * 
 * @param arr 
 * @param p 
 * @param r 
 */
void random_quickSort(vector<T>& arr, int p, int r){
    if(p<r){
        int q = random_partition(arr,p,r);
        random_quickSort(arr,p,q-1);
        random_quickSort(arr,q+1,r);
    }
}



int main(){
    
    Sort<int> sort;
    sort.printArr();
    
    cout<<"------ Test ------"<<endl;
    random_quickSort(sort.arr, 0, sort.arr.size()-1);
    sort.printArr(); 
    
    

    return 0;
}