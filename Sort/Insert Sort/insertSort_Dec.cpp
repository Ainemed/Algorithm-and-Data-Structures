#include "../SortArray.hpp"
/**
 * @brief Incremental Algorithm of Sorting, Complexity: Θ(n^2)
 * 
 * @param arr 
 */
void insertionSort_dec(vector<int>& arr){
    for (size_t i = 1; i < arr.size(); i++)
    {
        int tmp = arr.at(i); // 1
        int j = i-1; // 0 <-
        while (j >= 0 && tmp > arr.at(j))
        {
            arr.at(j+1) = arr.at(j);
            j--;
        }
        arr.at(j+1)=tmp;
        
    }
}


void insertionSort_RicAux_dec(vector<int>& arr, int i, int tmp){
    if(i<=arr.size()-1){
        int j = i-1;
        while (j >= 0 && tmp > arr.at(j))
        {
            arr.at(j+1) = arr.at(j);
            j--;
        }
        arr.at(j+1)=tmp;
        if(i!=arr.size()-1){
            insertionSort_RicAux_dec(arr, i+1, arr.at(i+1));
        }
    }
}


void insertionSort_Ric_dec(vector<int>& arr){
    if(arr.size()>1){
        insertionSort_RicAux_dec(arr,1, arr.at(1));
    }
}

int main(){
    Sort<int> sort;
    
    sort.printArr();
    cout<<"-----------"<<endl;
    insertionSort_Ric_dec(sort.arr);
    
    sort.printArr();

    

    return 0;
}