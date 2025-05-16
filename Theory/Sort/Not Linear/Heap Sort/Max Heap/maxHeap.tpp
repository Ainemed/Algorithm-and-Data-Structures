#include "maxHeap.hpp"

/**
 * @brief Swap two values.
 * 
 * @tparam T Type of elements.
 * @param a First element.
 * @param b Second element.
 */
template<typename T>
void maxHeap<T>::swap(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
}

/**
 * @brief Return the maximum element of the max-heap without removing it.
 * 
 * In a max-heap, the largest element is always at the root (index 0).
 * 
 * Time Complexity: O(1)
 * 
 * @tparam T Type of elements in the heap.
 * @return T The maximum element (i.e., the root of the heap).
 * @throws std::underflow_error If the heap is empty.
 */
template<typename T>
T maxHeap<T>::heap_maximum() {
    if (heap_size <= 0) {
        throw underflow_error("Heap underflow");
    }
    return heap.at(0);
}


/**
 * @brief Maintain the max_heap propriety at index i.
 * 
 * Time Complexity: O(log n), where n is the number of elements in the heap.
 * 
 * @tparam T Type of elements in the heap.
 * @param i Index to apply max_heapify.
 */
template<typename T>
void maxHeap<T>::max_heapify(int i){
    int l = left(i);
    int r = right(i);
    int max;

    if (l <= heap_size && heap.at(l) < heap.at(i)) {
        max = l;
    } else {
        max = i;
    }

    if (r <= heap_size && heap.at(r) < heap.at(max)) {
        max = r;
    }

    if (i != max) {
        swap(heap.at(i), heap.at(max));
        max_heapify(max);
    }
}

/**
 * @brief Build a max-heap from the current heap vector.
 * 
 * Time Complexity: O(n), where n is the number of elements in the heap.
 * This is due to the fact that heapify is called in a bottom-up manner.
 * 
 * @tparam T Type of elements in the heap.
 */
template<typename T>
void maxHeap<T>::build_max_heap() {
    heap_size = heap.size() - 1;
    for (int i = floor(heap_size / 2); i >= 0; i--) {
        max_heapify(i);
    }
}

/**
 * @brief Apply heap sort to the internal vector.
 * 
 * Time Complexity: O(n log n), where n is the number of elements in the heap.
 * 
 * @tparam T Type of elements in the heap.
 */
template<typename T>
void maxHeap<T>::sort() {
    build_max_heap();
    for (int i = heap.size() - 1; i >= 1; i--) {
        swap(heap.at(0), heap.at(i));
        heap_size--;
        max_heapify(0);
    }
}

/**
 * @brief Extract the maximum element from the heap (i.e., the root).
 * 
 * Time Complexity: O(log n)
 * 
 * @return T The maximum element in the heap.
 */
template<typename T>
T maxHeap<T>::heap_extract(){
    if(heap_size<0){
        throw underflow_error("Heap underflow");
    }
    T max = heap.at(0);
    heap.at(0) = heap.at(heap_size-1);
    heap.pop_back();
    heap_size --;
    max_heapify(0);
    return max;
}

/**
 * @brief Increases the value of an element at index i and restores the max-heap property.
 * 
 * If the new key is greater than the current key, it moves the element up the heap
 * until the max-heap property is restored.
 * 
 * Time Complexity: O(log n)
 * 
 * @tparam T Type of elements in the heap.
 * @param i Index of the element to be increased.
 * @param key New key value to assign at index i.
 * @throws std::underflow_error If the new key is smaller than the current key.
 */
template<typename T>
void maxHeap<T>::heap_increase_key(int i, T key) {
    if (key < heap.at(i)) {
        throw underflow_error("New key is smaller than current key");
    }

    heap.at(i) = key;

    while (i > 0 && heap.at(parent(i)) < heap.at(i)) {
        swap(heap.at(i), heap.at(parent(i)));
        i = parent(i);
    }
}



/**
 * @brief Insert a new key into the max-heap and maintain heap property.
 * 
 * A placeholder value (smallest possible) is first inserted,
 * then increased to the desired key using `heap_increase_key`.
 * 
 * Time Complexity: O(log n)
 * 
 * @tparam T Type of elements in the heap.
 * @param key Value to insert into the heap.
 */
template<typename T>
void maxHeap<T>::max_heap_insert(T key) {
    heap_size++;
    heap.push_back(-1); // Add a dummy value
    heap_increase_key(heap_size - 1, key); // Increase to correct value
}

