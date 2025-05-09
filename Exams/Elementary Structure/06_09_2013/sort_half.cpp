#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int>& arr, int p, int r, int type){
    for(int i=p+1; i<=r; i++){
        int tmp = arr.at(i);
        int j=i-1;
        if(type==0){
            while(j>=p && tmp<arr.at(j)){
                arr.at(j+1)=arr.at(j);
                j--;
            }
        }else{
            while(j>=p && tmp>arr.at(j)){
                arr.at(j+1)=arr.at(j);
                j--;
            }
        }
        arr.at(j+1)=tmp;
    }
}

void merge(vector<int>& arr, int p, int q, int r, int type){
    int n1 = q-p+1;
    int n2 = r-q;

    int inf = arr.at(p);

    vector<int> tmp1, tmp2;
    for(int i=0; i<n1; i++){
        if(type==0 && arr.at(p+i)>inf){
            inf = arr.at(p+i);
        }else if(type==1 && arr.at(p+i)<inf){
            inf = arr.at(p+i);
        }
        tmp1.push_back(arr.at(p+i));
    }
    for(int i=0; i<n2; i++){
        if(type==0 && arr.at(q+i+1)>inf){
            inf = arr.at(q+i+1);
        }else if(type==1 && arr.at(q+i+1)<inf){
            inf = arr.at(q+i+1);
        }
        tmp2.push_back(arr.at(q+i+1));
    }
    if(type==0){
        inf++;
    }else{
        inf--;
    }
    tmp1.push_back(inf);
    tmp2.push_back(inf);

    int i=0, j=0;
    for(int k=p; k<=r;k++){
        if(type==0 && tmp1.at(i)<=tmp2.at(j)){
            arr.at(k)=tmp1.at(i);
            i++;
        }else if(type==0 && tmp1.at(i)>tmp2.at(j)){
            arr.at(k)=tmp2.at(j);
            j++;
        }else if(type==1 && tmp1.at(i)>= tmp2.at(j)){
            arr.at(k)=tmp1.at(i);
            i++;
        }else{
            arr.at(k)= tmp2.at(j);
            j++;
        }
    }
}

void mergeSort(vector<int>& arr, int p, int r, int j, int type){
    int dim = arr.size()-j;
    if(dim>=5 && dim<=25){
        insertionSort(arr, p, r, type);
    }else{
        int med = (p+r)/2, q=med;
        mergeSort(arr, p, med, j, type);
        mergeSort(arr, med+1, r, j, type);
        merge(arr, p, q, r, type);
    }
}

void sort_half(vector<int>& arr, int j){
    
    mergeSort(arr,0,j,j,0);
    mergeSort(arr,j+1,arr.size()-1,j,1);
}


int main(){

    vector<int> arr;
    int dim;
    cout << "Dim: ";
    cin >> dim;
    int j;
    cout<<"J: ";
    cin>>j;

    for (int i = 0; i < dim; ++i) {
        int tmp;
        cout << "Elem " << i + 1 << " : ";
        cin >> tmp;
        arr.push_back(tmp);
    }
    
    sort_half(arr,j);

    for(int i=0; i<arr.size();i++){
        if(i==0){
            cout<<"-- Ascending --"<<endl;
        }else if(i==j){
            cout<<"-- Descending --"<<endl;
        }
        cout<<arr.at(i)<<endl;
    }

    return 0;
}