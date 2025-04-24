#include "maxHeap.hpp"

using namespace std;

int main() {
    maxHeap<int> maxHeap;

    int dim;
    cout << "Set the Dimension: ";
    cin >> dim;

    for (int i = 0; i < dim; i++) {
        int tmp;
        cout << "Elem " << i + 1 << " : ";
        cin >> tmp;
        maxHeap.max_heap_insert(tmp);
    }

    cout << "\nMaximum element: " << maxHeap.heap_maximum() << endl;

    cout << "\nExtracting elements in decreasing order:" << endl;
    while (maxHeap.heap_size > 0) {
        cout << maxHeap.heap_extract() << " ";
    }
    cout << endl;

    return 0;
}
