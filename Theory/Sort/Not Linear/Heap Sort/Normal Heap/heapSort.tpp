#include "heapSort.hpp"

/**
 * @brief Swap two values.
 * 
 * @tparam T Type of elements.
 * @param a First element.
 * @param b Second element.
 */
template<typename T>
void heapSort<T>::swap(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
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
void heapSort<T>::max_heapify(int i) {
    int l = left(i);
    int r = right(i);
    int max;

    if (l <= heap_size && heap.at(l) > heap.at(i)) {
        max = l;
    } else {
        max = i;
    }

    if (r <= heap_size && heap.at(r) > heap.at(max)) {
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
void heapSort<T>::build_max_heap() {
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
void heapSort<T>::sort() {
    build_max_heap();
    for (int i = heap.size() - 1; i >= 1; i--) {
        swap(heap.at(0), heap.at(i));
        heap_size--;
        max_heapify(0);
    }
}

