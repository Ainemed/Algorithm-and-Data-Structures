#include <iostream>
#include <vector>

using namespace std;

// Funzione ricorsiva di tipo divide-et-impera per trovare j
int find_j(const vector<int>& v, int low, int high) {
    int n = v.size();
    if (low >= high) return -1;

    int mid = (low + high) / 2;

    // Verifica se mid è il punto di transizione
    if (mid < n - 1 && v[mid] < v[mid + 1] && (mid == 0 || v[mid - 1] > v[mid])) {
        return mid;
    }
    // Se sinistra è ancora decrescente, cerca a destra
    else if (mid > 0 && v[mid - 1] > v[mid]) {
        return find_j(v, mid + 1, high);
    }
    // Altrimenti cerca a sinistra
    else {
        return find_j(v, low, mid);
    }
}

int main() {
    vector<int> v;
    int n;
    
    cout << "Inserisci la dimensione dell'array: ";
    cin >> n;

    cout << "Inserisci " << n << " numeri distinti:\n";
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    int j = find_j(v, 0, v.size() - 1);

    if (j != -1) {
        cout << "La posizione j è: " << j << endl;
        cout << "v[j] = " << v[j] << ", v[j+1] = " << v[j+1] << endl;
    } else {
        cout << "Nessuna posizione j trovata.\n";
    }

    return 0;
}