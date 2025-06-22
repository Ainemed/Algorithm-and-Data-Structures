#include <iostream>
#include <vector>

using namespace std;

struct Heap{
    vector<int> arr;
    int heap_size;

    Heap():heap_size(0){}
    Heap(vector<int> arr, int heap_size): heap_size(heap_size), arr(arr){}
};

int left(int i){
    return i*2+1;
}
int right(int i){
    return i*2+2;
}
void swap(int& i, int& j){
    int tmp=i;
    i=j;
    j=tmp;
}
void max_heapify(vector<int>& arr, int i){
    int l = left(i);
    int r = right(i);
    int max=i;

    if(l<arr.size() && arr.at(l)>arr.at(i)){
        max=l;
    }else{
        max = i;
    }
    if(r<arr.size() && arr.at(r)>arr.at(max)){
        max=r;
    }
    if(i!=max){
        swap(arr.at(i), arr.at(max));
        max_heapify(arr,max);
    }
}
void printArr(vector<int> arr){
    cout<<"< ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr.at(i)<<", ";
    }
    cout<<" >"<<endl;
}

void build_max_heap(vector<int>& arr){
    for(int i=floor(arr.size()/2); i>=0;i--){
        max_heapify(arr, i);
        cout<<"- "<<i<<" :"<<endl;
        printArr(arr);
    }
}

int main(){
    
    int dim;
    cout<<"Dim: ";
    cin>>dim;

    vector<int> arr;
    for (int i = 0; i < dim; i++)
    {
        int tmp;
        cout<<"Elem "<<i+1<<" : ";
        cin>>tmp;
        arr.push_back(tmp);
    }
    Heap heap;
    build_max_heap(arr);

    printArr(arr);
    
    

    return 0;
}