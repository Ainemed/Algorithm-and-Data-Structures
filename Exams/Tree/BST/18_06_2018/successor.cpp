#include <iostream>
#include <vector>

using namespace std;

struct Node{
    Node* p;
    Node* left;
    Node* right;
    int key;

    Node(): key(-1), p(nullptr), left(nullptr), right(nullptr){}
    Node(int key): key(key), p(nullptr), left(nullptr), right(nullptr){}
    Node(int key, Node* p, Node* left, Node* right): key(-1), p(p), left(left), right(right){}
};

struct Tree
{
    Node* root;

    Tree(): root(nullptr){}
    Tree(Node* root): root(root){}  
};

Node* createBST_aux(vector<int> arr, int inf, int sup, Node* father){
    if(inf>sup){
        return nullptr;
    }else{
        int med=(inf+sup)/2;
        Node* r=new Node(arr.at(med));
        r->p= father;
        r->left= createBST_aux(arr, inf, med-1, r);
        r->right= createBST_aux(arr, med+1, sup, r);
        return r;
    }
}

/**
 * @brief Create a BST ott object, Complexity : Theta(nlogn)
 * 
 * @param arr 
 * @return Tree 
 */
Tree createBST_ott(vector<int> arr){
    Tree tree;
    Node* elem;
    tree.root=createBST_aux(arr, 0, arr.size()-1, elem);
    return tree;
}

void preorder_see(Node* v){
    if(v){
        cout<<v->key<<endl;
        preorder_see(v->left);
        preorder_see(v->right);
    }
}

Node* minumumBST(Node* v){
    while (v->left)
    {
        v=v->left;
    }
    return v;
    
}

Node* successorBST(Node* x){
    if(x->right){
        return minumumBST(x);
    }else{
        Node* y=x->p;
        while (y && x==y->right)
        {
            x=y;
            y=y->p;
        }
        return y;
        
    }
}


int main(){
    vector<int> arr;
    int dim;
    cout<<"Dim: ";
    cin>>dim;

    for (size_t i = 0; i < dim; i++)
    {
        int tmp;
        cout<<"Elem "<<i+1<<" : ";
        cin>>tmp;
        arr.push_back(tmp);
    }

    Tree tree = createBST_ott(arr);

    cout<<"Successor : "<<successorBST(tree.root)->key<<endl;

    return 0;
}