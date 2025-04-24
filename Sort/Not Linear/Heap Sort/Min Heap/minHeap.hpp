#ifndef MIN_HEAP_HPP
#define MIN_HEAP_HPP

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

template<typename T>
struct MinHeap {
    vector<T> heap;
    int heap_size = 0;

    
    void insert(T key);

    
    T minimum() const;

    
    T extract_min();

    
    void decrease_key(int i, T new_key);

private:
    int parent(int i) const { return (i - 1) / 2; }
    int left(int i) const { return 2 * i + 1; }
    int right(int i) const { return 2 * i + 2; }

    void min_heapify(int i);

    void swap(T& a, T& b) {
        T tmp = a;
        a = b;
        b = tmp;
    }
};

#include "minHeap.tpp"

#endif // MIN_HEAP_HPP
