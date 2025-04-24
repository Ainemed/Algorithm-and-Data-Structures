#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Performs Counting Sort on an input array arrA and stores the sorted result in arrB.
 * 
 * Counting Sort is a non-comparison based sorting algorithm that assumes input values are in the range [0, k].
 * It runs in O(n + k) time and is efficient when k is not significantly larger than n.
 * 
 * @tparam T Integer type (must be convertible to int for indexing)
 * @param arrA Input array of integers (values in [0, k])
 * @param arrB Output array that will contain the sorted elements
 * @param n The size of the arrA
 * @param k Maximum possible value in arrA
 */
template<typename T>
void countingSort(vector<T> arrA, vector<T>& arrB, int n, int k){
    arrB.resize(n);                  // Ensure output vector has correct size
    vector<int> count(k + 1, 0);     // Count array C initialized to 0

    // Count occurrences
    for (int j = 0; j < n; j++) {
        count[arrA[j]]++;
    }

    // Prefix sums (cumulative count)
    for (int i = 1; i <= k; i++) {
        count[i] += count[i - 1];
    }

    // Build output array (go backwards to make sort stable)
    for (int j = n - 1; j >= 0; j--) {
        arrB[count[arrA[j]] - 1] = arrA[j];
        count[arrA[j]]--;
    }
}

int main(){

    vector<int> vecA, vecB;
    int dim, max=0;
    cout<<"Set the Dimension: ";
    cin>>dim;

    for(int i=0;i<dim;i++){
        int tmp;
        cout<<"Elem "<<i+1<<" : ";
        cin>>tmp;
        vecA.push_back(tmp);
        if(max<tmp){
            max=tmp;
        }
    }

    for(int i=0; i<vecA.size();i++){
        cout<<vecA.at(i)<<endl;
    }

    countingSort(vecA,vecB,vecA.size(),max);
    cout<<"--------------"<<endl;
    for(int i=0; i<vecB.size();i++){
        cout<<vecB.at(i)<<endl;
    }
    

    return 0;
}
