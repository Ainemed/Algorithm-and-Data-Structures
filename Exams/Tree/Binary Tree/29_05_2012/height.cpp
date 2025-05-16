#include <iostream>
using namespace std;


struct Node{
    int key;
    Node* left_child;
    Node* right_sib;

    Node(): key(-1), left_child(nullptr), right_sib(nullptr){}
    Node(int key): key(key), left_child(nullptr), right_sib(nullptr){}
    Node(int key, Node* left_child, Node* right_sib): key(key), left_child(left_child), right_sib(right_sib){}
};

struct Tree{
    Node* root;

    Tree(): root(nullptr){}
    Tree(Node* root): root(root){}
};
int height(Node* r) {
    if (!r) return 0;

    int childHeight = height(r->left_child);
    int siblingHeight = height(r->right_sib);

    return max(1 + childHeight, siblingHeight);
}

int main() {
    // Costruzione esempio:
    //
    //         1
    //       / | \
    //      2  3  4
    //     /
    //    5
    //   /
    //  6

    Node* n6 = new Node(6);
    Node* n5 = new Node(5, n6, nullptr);
    Node* n2 = new Node(2, n5, nullptr);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    n2->right_sib = n3;
    n3->right_sib = n4;

    Node* n1 = new Node(1, n2, nullptr);
    Tree tree(n1);

    cout << "Altezza dell’albero: " << height(tree.root) << endl;

    return 0;
}