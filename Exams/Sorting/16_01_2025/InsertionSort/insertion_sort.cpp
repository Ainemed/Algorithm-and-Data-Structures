#include <iostream>
#include <vector>

using namespace std;

void recursiveInsertionSort(vector<int>& arr, int n) {
    if (n <= 1)
        return;

    // Ordina ricorsivamente A[0..n-2]
    recursiveInsertionSort(arr, n - 1);

    // Inserisce A[n-1] nel sottovettore ordinato
    int tmp = arr[n - 1];
    int j = n - 2;

    while (j >= 0 && arr[j] > tmp) {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = tmp;
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
    recursiveInsertionSort(arr, arr.size());

    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr.at(i)<<endl;
    }
    

    
}