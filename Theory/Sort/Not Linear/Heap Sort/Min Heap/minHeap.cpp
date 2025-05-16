#include "minHeap.hpp"
#include <iostream>
using namespace std;

int main() {
    MinHeap<int> minHeap;

    int dim;
    cout << "Set the Dimension: ";
    cin >> dim;

    for (int i = 0; i < dim; i++) {
        int tmp;
        cout << "Elem " << i + 1 << " : ";
        cin >> tmp;
        minHeap.insert(tmp);
    }

    cout << "\nMinimum element: " << minHeap.minimum() << endl;

    cout << "\nExtracting elements in increasing order:" << endl;
    while (minHeap.heap_size > 0) {
        cout << minHeap.extract_min() << " ";
    }
    cout << endl;

    return 0;
}