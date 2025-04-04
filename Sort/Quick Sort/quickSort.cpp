#include "../SortArray.hpp"


template<typename T>
int partition(vector<T>& arr, int p, int r){
    T x = arr.at(r);
    int i = p-1;
    for (size_t j = p; j < r; j++)
    {
        if(arr.at(j) <= x){
            i++;
            cout<<arr.at(j)<<endl;
            T tmp = arr.at(i);
            arr.at(i) = arr.at(j);
            arr.at(j)=tmp;
        }
    }
    T tmp = arr.at(i+1);
    arr.at(i+1) = arr.at(r);
    arr.at(r)=tmp;

    return i+1;
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
void quickSort(vector<T>& arr, int p, int r){
    if(p<r){
        int q = partition(arr,p,r);
        quickSort(arr,p,q-1);
        quickSort(arr,q+1,r);
    }
}



int main(){

    Sort<int> sort;
    sort.printArr();
    
    cout<<"------ Test ------"<<endl;
    quickSort(sort.arr, 0, sort.arr.size()-1);
    sort.printArr(); 

    return 0;
}