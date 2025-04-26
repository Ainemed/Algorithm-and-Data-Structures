#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/**
 * @brief Extracts the digit at the i-th position (from right, 1-based) of x in base n.
 *
 * This function is used to isolate a specific digit of a number when represented
 * in a given base. For example, cifra(321, 10, 2) returns 2 (the "tens" digit).
 *
 * @param x The input number.
 * @param n The base (e.g., 10 for decimal).
 * @param i The digit position to extract (1-based, from right).
 * @return The digit at position i in base n.
 *
 * @complexity Time: O(log i) due to pow(), Space: O(1)
 */
int cifra(int x, int n, int i)
{
    return (x / static_cast<int>(pow(n, i - 1))) % n;
}

/**
 * @brief Performs Counting Sort on a vector of integers based on the i-th digit (in base k), in descending order.
 * 
 * This function is used as a stable subroutine by Radix Sort to sort based on individual digits,
 * from least to most significant digit. It differs from the ascending version by sorting
 * digits in reverse order.
 * 
 * @tparam T Integer type (must be compatible with arithmetic operations).
 * @param arr Input array to be sorted (modified in-place).
 * @param k Base used for digit extraction (e.g., 10 for decimal).
 * @param i Digit index to sort by (1-based, starting from least significant digit).
 *
 * @complexity Time: O(n + k), Space: O(n + k)
 */
template<typename T>
void countingSortDesc(vector<T>& arr, int k, int i)
{
    vector<T> arrB(arr.size());        // Output array
    vector<int> arrC(k, 0);            // Count array for digits [0, k-1]

    // Count occurrences of the i-th digit
    for (int j = 0; j < arr.size(); j++) {
        arrC.at(cifra(arr.at(j), k, i))++;
    }

    // Compute reverse cumulative count (descending order)
    for (int j = k - 2; j >= 0; j--) {  // ❗Fix: start at k - 2, go down to 0
        arrC.at(j) += arrC.at(j + 1);
    }

    // Build the output array in reverse order to ensure stability
    for (int j = arr.size() - 1; j >= 0; j--) {
        int c = cifra(arr.at(j), k, i);
        arrB.at(arrC.at(c) - 1) = arr.at(j);
        arrC.at(c)--;
    }

    // Copy sorted result back into original array
    arr = arrB;
}

/**
 * @brief Sorts a vector of integers using the Radix Sort algorithm in descending order.
 * 
 * Radix Sort processes the digits of each number starting from the least significant digit
 * to the most significant, using Counting Sort (descending version) as a stable sorting subroutine.
 * 
 * @tparam T Integer type (e.g., int, long).
 * @param arr Vector of integers to be sorted (modified in-place).
 * @param d Maximum number of digits in the largest number (in base k).
 * @param k Base used for digit extraction (e.g., 10 for decimal).
 *
 * @complexity Time: O(d * (n + k)), Space: O(n + k)
 */
template<typename T>
void radixSortDesc(vector<T>& arr, int d, int k)
{
    for (int i = 1; i <= d; i++) {
        countingSortDesc(arr, k, i);
    }
}



int count_digits(int n)
{
    int count=0;
    while(n>0){
        count++;
        n = n/10;
    }
    return count;
}

int main(){

    vector<int> arr;

    int dim;
    cout<<"Set the Dimension: ";
    cin>>dim;

    cout<<"Set the Number of Digits (d): ";
    int digits;
    cin>>digits;

    cout<<"Set the Max Possible Value (k): ";
    int k;
    cin>>k;

    int i=0, tmp=0;
    do{
        tmp=0;
        cout<<"Elem "<<i+1<<" : ";
        cin>>tmp;
        if(count_digits(tmp)==digits){
            arr.push_back(tmp);
            i++;
        }else{
            cout<<"The digits number is not correct, try again"<<endl;
        }
        
    }
    while(i<dim);
    cout<<"-------Stamp the Vector---------"<<endl;

    for (size_t i = 0; i < arr.size(); i++)
    {
        cout<<arr.at(i)<<endl;
    }
    cout<<"--------Radix Sort--------"<<endl;

    radixSortDesc(arr, digits, k);

    for (size_t i = 0; i < arr.size(); i++)
    {
        cout<<arr.at(i)<<endl;
    }
    
    
    

    return 0;
}