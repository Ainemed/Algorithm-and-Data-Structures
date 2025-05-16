#ifndef HEAP_SORT_HPP
#define HEAP_SORT_HPP

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

template<typename T>
struct heapSort {
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
    void max_heapify(int i);
    void build_max_heap();
    void sort();
};

#include "heapSort.tpp"

#endif // HEAP_SORT_HPP
