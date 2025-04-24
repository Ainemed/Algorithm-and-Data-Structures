#include "heapSort.hpp"

int main(){
    heapSort<int> heapS;

    int dim;
    cout << "Set the Dimension: ";
    cin >> dim;

    for (int i = 0; i < dim; i++) {
        int tmp;
        cout << "Elem " << i + 1 << " : ";
        cin >> tmp;
        heapS.heap.push_back(tmp);
    }

    heapS.sort(); // Chiamata al metodo sort() dell'oggetto heapS

    cout << "-------------" << endl;
    for (size_t i = 0; i < heapS.heap.size(); i++) {
        cout << heapS.heap.at(i) << endl;
    }

    cout << "------ Test ------" << endl;

    return 0;
}