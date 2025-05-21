#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int>& arr){
    for(int i=1; i<arr.size();i++){
        int tmp = arr.at(i);
        int j=i-1;
        while(j>=0 && tmp<arr.at(j)){
            arr.at(j+1)=arr.at(j);
            j--;
        }
        arr.at(j+1)=tmp;
    }
}

int max_aus(int x, int y){
    if(x>y){
        return x;
    }else{
        return y;
    }
}

void merge(vector<int>& arr, int p, int q, int r){
    int n1 = q-p+1;
    int n2 = r-q;

    int max = arr.at(p);
    vector<int> tmp1, tmp2;

    for(int i=0; i<n1; i++){
        max = max_aus(arr.at(p+i),max);
        tmp1.push_back(arr.at(p+i));
    }
    for(int i=0; i<n2; i++){
        max = max_aus(arr.at(q+i+1),max);
        tmp2.push_back(arr.at(q+i+1));
    }

    tmp1.push_back(max+1);
    tmp2.push_back(max+2);

    int i=0, j=0;
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
            int med=(p+r)/2, q=med;
            mergeSort(arr, p, med);
            mergeSort(arr, med+1, r);
            merge(arr, p, q, r);
        }
    }
}

bool count_val(vector<int> arr, int c){
    mergeSort(arr, 0, arr.size()-1);
    vector<int> tmp;
    int count=1;
    for(int i=0; i<arr.size()-1; i++){
        if(arr.at(i)==arr.at(i+1)){
            count++;
        }else{
            tmp.push_back(count);
            count=1;
        }
    }

    mergeSort(tmp, 0, tmp.size()-1);

    int elem=1;
    int i=0;
    bool m=false;
    while(i<tmp.size()-1 && !m){
        if(tmp.at(i)==tmp.at(i+1)){
            elem++;
        }else{
            elem=1;
        }
        if(elem==c){
            m=true;
        }
        i++;
    }
    return m;
}


int main(){

    int dim;
    cout<<"Dim: ";
    cin>>dim;
    int c;
    cout<<"C: ";
    cin>>c;
    vector<int> arr;

    for (size_t i = 0; i < dim; i++)
    {
        int tmp=0;
        cout<<"Elem "<<i+1<<" : ";
        cin>>tmp;
        arr.push_back(tmp);
    }

    bool m = count_val(arr, c);

    if(m){
        cout<<"True"<<endl;
    }else{
        cout<<"False"<<endl;
    }

    return 0;
}