#include "minHeap.hpp"

/**
 * @brief Maintains the min-heap property starting from index i downward.
 * 
 * @tparam T Type of elements in the min-heap
 * @param i Index from which to start heapifying
 * 
 * @details Compares the current node with its children and swaps with the smallest,
 * then recursively calls itself to maintain the min-heap property.
 * 
 * @complexity O(log n)
 */
template<typename T>
void MinHeap<T>::min_heapify(int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;

    if (l < heap_size && heap[l] < heap[i]) smallest = l;
    if (r < heap_size && heap[r] < heap[smallest]) smallest = r;

    if (smallest != i) {
        swap(heap[i], heap[smallest]);
        min_heapify(smallest);
    }
}

/**
 * @brief Inserts a new key into the min-heap.
 * 
 * @tparam T Type of elements in the min-heap
 * @param key Value to insert
 * 
 * @details Adds a temporary large value and then calls decrease_key to fix it.
 * 
 * @post The key is inserted while preserving the min-heap property.
 * @complexity O(log n)
 */
template<typename T>
void MinHeap<T>::insert(T key) {
    heap_size++;
    heap.push_back(heap.at(heap_size - 1) + 1); // Temporary large value
    decrease_key(heap_size - 1, key); // Correct with actual value
}

/**
 * @brief Returns the minimum element without removing it.
 * 
 * @tparam T Type of elements in the min-heap
 * @return T The minimum value (root of the heap)
 * 
 * @throws std::underflow_error if the heap is empty
 * @complexity O(1)
 */
template<typename T>
T MinHeap<T>::minimum() const {
    if (heap_size <= 0) {
        throw std::underflow_error("Heap is empty");
    }
    return heap[0];
}

/**
 * @brief Extracts and returns the minimum element from the heap.
 * 
 * @tparam T Type of elements in the min-heap
 * @return T The removed minimum value
 * 
 * @details Replaces the root with the last element, removes it, and restores the heap property.
 * 
 * @throws std::underflow_error if the heap is empty
 * @complexity O(log n)
 */
template<typename T>
T MinHeap<T>::extract_min() {
    if (heap_size <= 0) {
        throw std::underflow_error("Heap underflow");
    }

    T min = heap[0];
    heap[0] = heap[heap_size - 1];
    heap.pop_back();
    heap_size--;
    min_heapify(0);
    return min;
}

/**
 * @brief Decreases the value of the key at index i to a new lower value.
 * 
 * @tparam T Type of elements in the min-heap
 * @param i Index of the node to update
 * @param new_key New value for the key, must be less than or equal to the current value
 * 
 * @throws std::out_of_range if the index is invalid
 * @throws std::invalid_argument if the new key is greater than the current key
 * 
 * @details Updates the key and bubbles it up to restore the min-heap property.
 * @complexity O(log n)
 */
template<typename T>
void MinHeap<T>::decrease_key(int i, T new_key) {
    if (i >= heap_size || i < 0) {
        throw std::out_of_range("Index out of heap bounds");
    }
    if (new_key > heap[i]) {
        throw std::invalid_argument("New key is greater than current key");
    }

    heap[i] = new_key;
    while (i > 0 && heap[parent(i)] > heap[i]) {
        swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }
}
