#include "../SortArray.hpp"

void merge(vector<int>& arr, int p, int q, int r){
    int n1 = q - p + 1;
    int n2 = r - q;

    vector<int> tmp1, tmp2;

    int max=arr.at(0);
    
    for(int i=0; i<n1;i++){
        if(arr.at(p+i)>max){
            max = arr.at(p+i);
        }
        
        tmp1.push_back(arr.at(p+i));
    }
    
    for(int i=0; i<n2;i++){
        if(arr.at(q+i+1) > max){
            max = arr.at(q+i+1);
        }
        
        tmp2.push_back(arr.at(q+i+1));
    }

    tmp1.push_back(max+1);
    tmp2.push_back(max+1);

    int i=0, j=0;

    for(int k=p; k<=r; k++){
        if(tmp1.at(i) <= tmp2.at(j)){
            arr.at(k)=tmp1.at(i);
            i++;
        }else{
            arr.at(k)=tmp2.at(j);
            j++;
        }
    }
}
void insertionSort(vector<int>& arr){
    for (size_t i = 1; i < arr.size(); i++)
    {
        int tmp = arr.at(i); // 1
        int j = i-1; // 0 <-
        while (j >= 0 && tmp < arr.at(j))
        {
            arr.at(j+1) = arr.at(j);
            j--;
        }
        arr.at(j+1)=tmp;
        
    }
}

void mergeSort(vector<int>& arr, int p, int r){
    if(arr.size()>=5 && arr.size()<=25){
            insertionSort(arr);
    }else{
        if(p<r){
            int med = (p+r)/2, q=med;
            mergeSort(arr, p, med);
            mergeSort(arr, med+1, r);
            merge(arr,p,q,r);
        }
    }
}


int main(){
    cout<<5/2<<endl;
    Sort<int> sort;
    
    sort.printArr();
    
    mergeSort(sort.arr,0,sort.arr.size()-1);
    sort.printArr();
    cout<<"------ Test ------"<<endl;
    

    return 0;
}