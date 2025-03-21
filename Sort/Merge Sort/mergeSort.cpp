#include <iostream>

using namespace std;

void createArray(vector<int>& arr){
    int dim;
    cout<<"Set the Size: ";
    cin>>dim;
    cout<<"---------------"<<endl;
    for (size_t i = 0; i < dim; i++)
    {
        int elem=0;
        cout<<"Elem "<<i+1<<" : ";
        cin>>elem;
        arr.push_back(elem);
        
    }
}

void printArr(vector<int> arr){
    cout<<"----- Print Array -----"<<endl;
    for (size_t i = 0; i < arr.size(); i++)
    {
        cout<<arr.at(i)<<endl;
    }
    
}

void merge(vector<int>& arr, int p, int q, int r){
    int n1 = q - p + 1;
    int n2 = r - q;

    vector<int> tmp1, tmp2;

    int max=0;
    cout<<"tmp1: "<<endl;
    for(int i=0; i<=n1;i++){
        if(arr.at(abs(p+i-1))>max){
            max = arr.at(abs(p+i-1));
        }
        cout<<arr.at(abs(p+i-1))<<endl;
        tmp1.push_back(arr.at(p+i-1));
    }
    cout<<"tmp2: "<<endl;
    for(int i=0; i<=n2;i++){
        if(arr.at(q+i) > max){
            max = arr.at(q+i);
        }
        cout<<arr.at(q+i)<<endl;
        tmp2.push_back(arr.at(q+i));
    }

    tmp1.push_back(max+1);
    tmp2.push_back(max+1);

    int i=0, j=0;

    for(int k=p; k<r; k++){
        if(tmp1.at(i) <= tmp2.at(j)){
            arr.at(k)=tmp1.at(i);
            i++;
        }else{
            arr.at(k)=tmp2.at(j);
            j++;
        }
    }
}

void mergeSort(vector<int>& arr, int p, int r){
    if(p<r){
        int med = (p+r)/2, q=med;
        mergeSort(arr, p, med);
        mergeSort(arr, med+1, r);
        merge(arr,p,q,r);
    }
}


int main(){
    vector<int> arr;
    createArray(arr);
    printArr(arr);
    
    mergeSort(arr,0,arr.size());
    printArr(arr);
    cout<<"------ Test ------"<<endl;
    cout<<5/2<<endl;

    

    return 0;
}