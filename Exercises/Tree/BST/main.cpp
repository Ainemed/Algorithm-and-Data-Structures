#include <iostream>
#include <vector>

using namespace std;


struct Node{
    int info;
    Node* p;
    Node* left;
    Node* right;

    Node(): info(0), p(nullptr), left(nullptr), right(nullptr){}
    Node(int info): info(info), p(nullptr), left(nullptr), right(nullptr){}
    Node(int info, Node* p, Node* left, Node* right): info(info), p(p), left(left), right(right){}
    
};
typedef Node* PNode;

struct Tree{
    PNode root;
    
    Tree(PNode root):root(root){}
};
typedef Tree* PTree;

PNode createBST_aux(vector<int> arr, int inf, int sup, PNode elem){
    if(inf>sup){
        return nullptr;
    }else{
        int med=(inf+sup)/2;
        PNode tmp= new Node(arr.at(med));
        tmp->p=elem;
        tmp->left= createBST_aux(arr,inf,med-1,tmp);
        tmp->right=createBST_aux(arr, med+1, sup,tmp);
        return tmp;
    }
}

PTree createBST(vector<int> arr){//Theta(log n)
    PTree tree;
    PNode elem;
    tree->root = createBST_aux(arr, 0, arr.size()-1,elem);
    return tree;
}

void preorder(PNode v){//Theta(n)
    if(v){
        cout<<v->info<<endl;
        preorder(v->left);
        preorder(v->right);
    }
}

void postorder(PNode v){//Theta(n)
    if(v){
        postorder(v->left);
        postorder(v->right);
        cout<<v->info<<endl;
    }
}

void symmetric(PNode v){//Theta(n)
    if(v){
        symmetric(v->left);
        cout<<v->info<<endl;
        symmetric(v->right);
    }
} 

void transplant(PTree tree, PNode u, PNode v){//O(1)
    if(!u->p){
        tree->root=v;
    }else{
        if(u==u->p->left){
            u->p->left=v;
        }else{
            u->p->right=v;
        }
    }
    if(v){
        v->p=u->p;
    }
}

PNode minNode(PNode v){//O(log n)
    while(v->left){
        v=v->left;
    }
    return v;
}

void deleteBST(PTree tree, PNode z){ // O(log n)
    if(!z->left){
        transplant(tree,z,z->right);
    }else{
        if(!z->right){
            transplant(tree,z,z->left);
        }else{
            PNode min = minNode(z->right);
            if(min->p != z){
                transplant(tree,z,z->right);
                min->right=z->right;
                z->right->p=min;
            }
            transplant(tree,z,min);
            min->left=z->left;
            min->left->p=min;
        }
    }
}

void insert(PTree tree, PNode z){ // O(log n)
    PNode y,x;
    x = tree->root;
    while(x){
        y=x;
        if(z->info < x->info){
            x = x->left;
        }else{
            x = x->right;
        }
    }
    z->p=y;
    if(!y){
        tree->root=z;
    }else{
        if(z->info <y->info){
            y->left=z;
        }else{
            y->right=z;
        }
    }
}

PNode maxNode(PNode z){
    while(z->right){
        z = z->right;
    }
    return z;
}

PNode predecessor(PNode z){
    if(z->left){
        return maxNode(z->left);
    }else{
        PNode y = z->p;
        while(y && z==y->left){
            z = y;
            y = y->p;
        }
        return y;
    }   
}

PNode successor(PNode z){
    if(z->right){
        return minNode(z->right);
    }else{
        PNode y=z->p;
        while(y && z==y->right){
            z=y;
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
    for(int i=0; i<dim;i++){
        int tmp;
        cout<<"Elem "<<i+1<<" : ";
        cin>>tmp;
        arr.push_back(tmp);   
    }
    PTree tree=createBST(arr);
    symmetric(tree->root);
    cout<<"--------"<<endl;
    PNode ins=new Node(9);
    insert(tree,ins);
    symmetric(tree->root);

    return 0;   
}