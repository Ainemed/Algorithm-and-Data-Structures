#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int>& arr){
    for(int i=1; i<arr.size();i++){
        int tmp = arr.at(i);
        int j=i-1;
        while (j>=0 && tmp > arr.at(j))
        {
            arr.at(j+1)=arr.at(j);
            j--;
        }
        arr.at(j+1)=tmp;
    }
}

void merge(vector<int>& arr, int p, int q, int r){
    int n1 = q-p+1;
    int n2 = r-q;

    int max = arr.at(0);
    vector<int> tmp1, tmp2;

    for(int i=0; i<n1; i++){
        if(arr.at(p+i)> max){
            max = arr.at(p+i);
        }
        tmp1.push_back(arr.at(p+i));
    }
    for(int i=0; i<n2; i++){
        if(arr.at(q+i+1)> max){
            max = arr.at(q+i+1);
        }
        tmp2.push_back(arr.at(q+i+1));
    }
    tmp1.push_back(max+1);
    tmp2.push_back(max+2);
    
    int i=0,j=0;
    for(int k=p; k<=r; k++){
        if(tmp1.at(i)<=tmp2.at(j)){
            arr.at(k)=tmp1.at(i);
            i++;
        }else{
            arr.at(k)=tmp2.at(j);
            j++;
        }
    }
}

void mergeSort(vector<int>& arr, int p, int r){
    if(arr.size()>=5 && arr.size()<=25){
        insertionSort(arr);
    }else{
        if(p<r){
            int med = (p+r)/2, q=med;
            mergeSort(arr,p, med);
            mergeSort(arr, med+1,r);
            merge(arr,p,q,r);
        }
    }
}


int isKPresent(vector<int> arr, int k){
    mergeSort(arr, 0,arr.size()-1);
    int i=0;
    bool m=false;
    while(i<arr.size() && !m){
        int count =1;
        while(count+i<arr.size() && arr.at(i)== arr.at(count+i)){
            count++;
        }
        if(count==k){
            m=true;
        }
        i+=count;
    }
    if(m){
        return 1;
    }
    return 0;
}


int main(){
    vector<int> arr;
    int dim;
    cout<<"Dim: ";
    cin>>dim;
    int k;
    cout<<"K: ";
    cin>>k;
    for(int i=0;i<dim;i++){
        int tmp;
        cout<<"Elem "<<i+1<<" : ";
        cin>>tmp;
        arr.push_back(tmp);
    }
    
    int res = isKPresent(arr, k);
    if(res==1){
        cout<<"True"<<endl;
    }else{
        cout<<"False"<<endl;
    }

    return 0;
}