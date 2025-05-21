#include <iostream>
using namespace std;

struct Node {
    Node* left;
    Node* right;
    int key;

    Node(): key(-1), left(nullptr), right(nullptr) {}
    Node(int key): key(key), left(nullptr), right(nullptr) {}
    Node(int key, Node* left, Node* right): key(key), left(left), right(right) {}
};

typedef Node* PNode;

void sottrazione_alberi(PNode r1, PNode r2) {
    if (r1 && r2) {
        r1->key -= r2->key;
        sottrazione_alberi(r1->left, r2->left);
        sottrazione_alberi(r1->right, r2->right);
    }
}

void stampa_preorder(PNode root) {
    if (root) {
        cout << root->key << " ";
        stampa_preorder(root->left);
        stampa_preorder(root->right);
    }
}

int main() {
    // Costruzione albero T1 (esempio da traccia)
    PNode t1_5 = new Node(5);
    PNode t1_6 = new Node(6);
    PNode t1_7 = new Node(7);
    PNode t1_8 = new Node(8);
    PNode t1_3 = new Node(3, t1_5, t1_6);
    PNode t1_4 = new Node(4, t1_7, t1_8);
    PNode t1_1 = new Node(1, t1_3, t1_4);  // radice T1

    // Costruzione albero T2 (stessa struttura, chiavi diverse)
    PNode t2_2 = new Node(2);
    PNode t2_3a = new Node(3);
    PNode t2_5 = new Node(5);
    PNode t2_4a = new Node(4);
    PNode t2_7 = new Node(7, t2_2, t2_3a);
    PNode t2_10 = new Node(10, t2_5, t2_4a);
    PNode t2_0 = new Node(0, t2_7, t2_10);  // radice T2

    // Esecuzione sottrazione
    sottrazione_alberi(t1_1, t2_0);

    // Stampa preorder dell’albero T1 modificato
    cout << "T1 dopo la sottrazione (preorder): ";
    stampa_preorder(t1_1);
    cout << endl;

    return 0;
}