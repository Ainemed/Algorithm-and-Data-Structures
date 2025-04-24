#ifndef MAX_HEAP_HPP
#define MAX_HEAP_HPP

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

template<typename T>
struct maxHeap {
    vector<T> heap;
    int heap_size = 0;

    /**
     * @brief Return the parent index of the node at index i.
     * 
     * @param i Index of the node.
     * @return int Index of the parent node.
     */
    int parent(int i) { return floor(i / 2); }

    /**
     * @brief Return the index of the left child of the node at index i.
     * 
     * @param i Index of the node.
     * @return int Index of the left child.
     */
    int left(int i) { return 2 * i; }

    /**
     * @brief Return the index of the right child of the node at index i.
     * 
     * @param i Index of the node.
     * @return int Index of the right child.
     */
    int right(int i) { return 2 * i + 1; }

    void swap(T& a, T& b);
    
    T heap_maximum();
    void max_heapify(int i);
    void build_max_heap();
    void sort();

    T heap_extract();
    void heap_increase_key(int i, T key);
    void max_heap_insert(T key);

};

#include "maxHeap.tpp"

#endif // MAX_HEAP_HPP
