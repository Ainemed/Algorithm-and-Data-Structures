#include <iostream>
#include <vector>
using namespace std;

void merge3(vector<int>& arr, int p, int q1, int q2, int r) {
    int n1 = q1 - p + 1;
    int n2 = q2 - q1;
    int n3 = r - q2;

    int maxVal = arr[p];
    for (int i = p + 1; i <= r; i++) {
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }

    vector<int> tmp1, tmp2, tmp3;
    for (int i = 0; i < n1; i++) tmp1.push_back(arr[p + i]);
    for (int i = 0; i < n2; i++) tmp2.push_back(arr[q1 + i]);
    for (int i = 0; i < n3; i++) tmp3.push_back(arr[q2 + i]);

    tmp1.push_back(maxVal + 1);
    tmp2.push_back(maxVal + 1);
    tmp3.push_back(maxVal + 1);

    int i = 0, j = 0, l = 0;
    for (int k = p; k <= r; k++) {
        if (tmp1[i] <= tmp2[j] && tmp1[i] <= tmp3[l]) {
            arr[k] = tmp1[i++];
        } else if (tmp2[j] <= tmp1[i] && tmp2[j] <= tmp3[l]) {
            arr[k] = tmp2[j++];
        } else {
            arr[k] = tmp3[l++];
        }
    }
}

void mergeSort3(vector<int>& arr, int p, int r) {
    if (p < r) {
        int third = (r - p + 1) / 3;
        int q1 = p + third - 1;
        int q2 = q1 + third;

        // Aggiusta se q2 supera r
        if (q2 >= r) q2 = r - 1;

        mergeSort3(arr, p, q1);
        mergeSort3(arr, q1 + 1, q2);
        mergeSort3(arr, q2 + 1, r);

        merge3(arr, p, q1 + 1, q2 + 1, r);
    }
}

int main() {
    int dim;
    cout << "Dim: ";
    cin >> dim;
    vector<int> arr;

    for (int i = 0; i < dim; i++) {
        int tmp;
        cout << "Elem " << i + 1 << " : ";
        cin >> tmp;
        arr.push_back(tmp);
    }

    mergeSort3(arr, 0, arr.size() - 1);

    cout << "Array ordinato:\n";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}