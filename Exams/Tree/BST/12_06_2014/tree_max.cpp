#include <iostream>
#include <vector>

using namespace std;

struct Node{
    Node* p;
    Node* left;
    Node* right;
    int key;

    Node(int key): key(key), p(nullptr), left(nullptr), right(nullptr){}
    Node(int key, Node* p, Node* left, Node* right): key(key), p(p), left(left), right(right){}
    Node(): key(-1), p(nullptr), left(nullptr), right(nullptr){}
};

struct Tree
{   
    Node* root;

    Tree(): root(nullptr){}
    Tree(Node* root): root(root){}
};

Node* createBSTree_aux(vector<int> arr, int inf, int sup, Node* father){
    if(inf>sup){
        return nullptr;
    }else{
        int med=(inf+sup)/2;
        Node* r=new Node(arr.at(med));
        r->p=father;
        r->left=createBSTree_aux(arr,inf, med-1, r);
        r->right=createBSTree_aux(arr,med+1, sup,r);
        return r;
    }
}
/**
 * @brief Create a BSTree ott object, Complexity: Theta(nlogn)
 * 
 * @param arr 
 * @return Tree* 
 */
Tree createBSTree_ott(vector<int> arr){
    Tree tree;
    Node* elem;
    tree.root=createBSTree_aux(arr, 0, arr.size()-1,elem);
    return tree;
}

void preorder_see(Node* v){
    if(v){
        cout<<v->key<<endl;
        preorder_see(v->left);
        preorder_see(v->right);
    }
}

/**
 * @brief Complexity: Theta(h) where h is the height of the tree
 * 
 * @param v 
 */
Node* tree_maximum(Node* v){
    while(v->right){
        v = v->right;
    }
    return v;
}
/**
 * @brief Complexity: Theta(h) where h is the height of the tree
 * 
 * @param v 
 */
Node* tree_minimum(Node* v){
    while(v->left){
        v = v->left;
    }
    return v;
}

int main(){
    vector<int> arr;
    int dim;
    cout<<"Dim: ";
    cin>>dim;

    for(int i=0; i<dim;i++){
        int tmp;
        cout<<"Elem "<<i+1<<" : ";
        cin>>tmp;
        arr.push_back(tmp);
    }

    Tree tree=createBSTree_ott(arr);
    preorder_see(tree.root);
    
    cout<<"Maximum Number: "<<tree_maximum(tree.root)->key<<endl;
    cout<<"Minimum Number: "<<tree_minimum(tree.root)->key<<endl;

    return 0;
}