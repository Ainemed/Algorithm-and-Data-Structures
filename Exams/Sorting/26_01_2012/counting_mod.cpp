#include <iostream>

using namespace std;

void swap(vector<int>& arr, int i, int j){
    int tmp = arr.at(i);
    arr.at(i)=arr.at(j);
    arr.at(j)=tmp;
}

int  partition(vector<int>& arr, int p, int r, int& high) {
    int pivot = arr.at(r);
    int low = p;
    int mid = p;
    high = r;

    while (mid <= high) {
        if (arr.at(mid) < pivot) {
            swap(arr, low, mid);
            low++;
            mid++;
        } else if (arr.at(mid) == pivot) {
            mid++;
        } else { // A[mid] > pivot
            swap(arr, mid, high);
            high--;
        }
    }

    return low; // A[p..low-1] < pivot, A[low..high] == pivot, A[high+1..r] > pivot
}
void quickSort(vector<int>& arr, int p, int r){
    if(p<r){
        int t=0, q= partition(arr, p, r, t);
        quickSort(arr,p, q-1);
        quickSort(arr,t+1,r);
    }
}

int main(){

    int dim;
    cout<<"Dim: ";
    cin>>dim;
    vector<int> arr;

    for (size_t i = 0; i < dim; i++)
    {
        int tmp=0;
        cout<<"Elem "<<i+1<<" : ";
        cin>>tmp;
        arr.push_back(tmp);
    }

    quickSort(arr,0, arr.size()-1);

    for (size_t i = 0; i < arr.size(); i++)
    {
        cout<<arr.at(i)<<endl;
    }
    
    


    return 0;
}