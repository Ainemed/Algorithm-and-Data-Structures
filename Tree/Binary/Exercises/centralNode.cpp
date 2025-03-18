#include "../BinaryTree.hpp"
template <typename T>
int countCentreAux(Node<T>* u, int sum, int& numf) {
    int nodic, nodisx, numfsx, nodidx, numfdx;
    if (!u) {
        numf = 0;
        return 0;
    }
    if (!u->left && !u->right) {
        numf = 1;
        return 0;
    } else {
        nodisx = countCentreAux(u->left, sum + u->key, numfsx);
        nodidx = countCentreAux(u->right, sum + u->key, numfdx);
        numf = numfsx + numfdx;
        nodic = nodisx + nodidx;
        cout << u->key << endl;
    }
    return (numf == sum + u->key) ? nodic + 1 : nodic;
}

template <typename T>
int countCentre(Node<T>* u) {
    int numf;
    return countCentreAux(u, 0, numf);
}

int main(){
    Node<int> num1(0),num2(2),num3(3),num4(1),num5(-1);
    Tree<int> treeInt(&num1);

    num1.left=&num2;
    num1.right=&num3;

    num2.p=&num1;
    num2.left=&num4;
    num2.right=&num5;

    num3.p=&num1;
    num4.p=&num2;
    num5.p=&num2;

    fatherTree(treeInt.root);
    preorder_seeDFS_Ric(treeInt.root);
    cout<<"-----"<<endl;
    cout<<"Nodi Centrali: "<<countCentre(treeInt.root)<<endl;
    return 0;
}