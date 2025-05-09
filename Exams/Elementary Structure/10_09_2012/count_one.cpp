#include <iostream>
#include <vector>
using namespace std;



int count_ones(const vector<int>& arr) {
    int low = 0, high = arr.size() - 1;
    int first_one_index = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr.at(mid) == 1) {
            first_one_index = mid;
            high = mid - 1; // cerca a sinistra
        } else {
            low = mid + 1;
        }
    }

    if (first_one_index == -1) return 0; // nessun 1 trovato
    return arr.size() - first_one_index;
}






int main() {
    vector<int> arr;
    int dim;
    cout << "Dim: ";
    cin >> dim;

    for (int i = 0; i < dim; ++i) {
        int tmp;
        cout << "Elem " << i + 1 << " : ";
        cin >> tmp;
        arr.push_back(tmp);
    }

    cout << "Numero di 1: " << count_ones(arr) << endl;
    return 0;
}