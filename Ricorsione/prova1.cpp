#include <iostream>

using namespace std;

void createArr(int arr[], int dim){
    cout<<"---Create Array---"<<endl;
    for(int i=0;i<dim;i++){
        int tmp;
        cin>>tmp;
        arr[i]=tmp;
    }
}

void printArr(int arr[], int dim){
    cout <<"---Print Array---"<<endl;
    for(int i=0; i<dim; i++){
        cout<<arr[i]<<endl;
    }
}
/**
 * @brief Count the number of odd numbers in the array
 * 
 * @param arr 
 * @param dim 
 * @return int 
 */
int countOdd(int arr[], int dim){
    if(dim==0){
        return 0;
    }else{
        if(arr[dim-1]%2==0){
            return countOdd(arr,dim-1)+1;
        }else{
            return countOdd(arr,dim-1);
        }
    }
}

int main(){
    
    int dim=10, arr[10];
    
    createArr(arr,dim);
    cout<<"Odd Number: "<<countOdd(arr,dim);
    printArr(arr,dim);

    return 0;
}