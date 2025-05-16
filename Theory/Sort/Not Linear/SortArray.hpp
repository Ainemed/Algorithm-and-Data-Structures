#ifndef SORTARRAY_HPP
#define SORTARRAY_HPP

#include <iostream>
#include <list>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

template<typename T>
struct Sort{
    vector<T> arr;

    Sort();
    Sort(vector<T> arr);
    void printArr();
};





#include "SortArray.tpp"

#endif