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
typedef Node* PNode;
struct Tree
{   
    PNode root;

    Tree(): root(nullptr){}
    Tree(PNode root): root(root){}
};
typedef Tree* PTree;


PNode createBSTree_aux(vector<int> arr, int p, int r, PNode father){
    if(p<=r){
        int med = (p+r)/2;
        PNode elem=new Node(arr.at(med));
        elem->p=father;
        elem->left=createBSTree_aux(arr, p, med-1, elem);
        elem->right= createBSTree_aux(arr, med+1, r, elem);
        return elem;
    }
    return nullptr;
}

PTree createBSTree(vector<int> arr){
    PTree tree = new Tree();
    PNode elem=nullptr;
    tree->root=createBSTree_aux(arr,0, arr.size()-1, elem);
    return tree;
}

void preorderSee(PNode v){
    if(v){
        cout<<v->key<<endl;
        preorderSee(v->left);
        preorderSee(v->right);
    }
}

void createArr(PNode t, vector<int>& arr){
    if(t){
        arr.push_back(t->key);
        createArr(t->left,arr);
        createArr(t->right,arr);
    }
}

void insertionSort(vector<int>& arr){
    for(int i=1; i<arr.size();i++){
        int tmp = arr.at(i);
        int j=i-1;
        while(j>=0 && tmp<arr.at(j)){
            arr.at(j+1)=arr.at(j);
            j--;
        }
        arr.at(j+1)=tmp;
    }
}
int max_fun(int x, int y){
    if(x>y){
        return x;
    }else{
        return y;
    }
}
void merge(vector<int>& arr, int p, int q, int r){
    int n1 = q-p+1;
    int n2 = r-q;

    int max = arr.at(p);

    vector<int> tmp1, tmp2;

    for(int i=0; i<n1; i++){
        max = max_fun(arr.at(p+i),max);
        tmp1.push_back(arr.at(p+i));
    }
    for(int i=0; i<n2; i++){
        max = max_fun(arr.at(q+i+1),max);
        tmp2.push_back(arr.at(q+i+1));
    }

    tmp1.push_back(max+1);
    tmp2.push_back(max+2);

    int i=0, j=0;
    for(int k=p; k<=r;k++){
        if(tmp1.at(i)<=tmp2.at(j)){
            arr.at(k)=tmp1.at(i);
            i++;
        }else{
            arr.at(k)=tmp2.at(j);
            j++;
        }
    }

}

void mergeSort(vector<int>& arr, int p, int r){
    if(arr.size()>=5 && arr.size()<=25){
        insertionSort(arr);
    }else{
        if(p<r){
            int med=(p+r)/2, q=med;
            mergeSort(arr, p, med);
            mergeSort(arr, med+1, r);
            merge(arr,p,q,r);
        }
    }
}

PTree MergeBST_aux(PNode t1, PNode t2){
    vector<int> arr;
    createArr(t1,arr);
    createArr(t2,arr);
    mergeSort(arr, 0, arr.size()-1);

    return createBSTree(arr);

}

PTree MergeBST(PTree t1, PTree t2){
    if(t1 && t2){
        return MergeBST_aux(t1->root,t2->root);
    }else if(t1){
        return t1;
    }else{
        return t2;
    }
}

void transplantBST(PTree t, PNode u, PNode v){
    if(!u->p){
        t->root=v;
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
PNode minBST(PNode v){
    while(v->left)v=v->left;
    return v;
}

void deleteBST(PTree t, PNode z){
    if(!z->left){
        transplantBST(t,z,z->right);
    }else{
        if(!z->right){
            transplantBST(t,z,z->left);
        }else{
            PNode elemMin = minBST(z->right);
            if(elemMin->p != z){
                elemMin->right=z->right;
                z->right->p=elemMin;
            }
            transplantBST(t,z,elemMin);
            elemMin->left=z->left;
            elemMin->left->p=elemMin;
        }
    }
}

PTree MergeBST2(PTree T1, PTree T2) {
    if (!T1) return T2;
    if (!T2) return T1;

    // Trova il massimo in T1
    PNode maxNode = T1->root;
    while (maxNode->right) maxNode = maxNode->right;

    // Rimuovi maxNode da T1 (per non duplicare) e usalo come nuova radice
    deleteBST(T1,maxNode);


    PTree merged = new Tree();
    merged->root = maxNode;
    maxNode->left = T1->root;
    maxNode->right = T2->root;

    return merged;
}


int main(){
    int dim;
    cout<<"Dim: ";
    cin>>dim;
    vector<int> arr;

    for (size_t i = 0; i < dim; i++)
    {
        int tmp=0;
        cout<<"Elem "<<i+1<<" : ";
        cin>>tmp;
        arr.push_back(tmp);
    }
    PTree tree = createBSTree(arr);
    preorderSee(tree->root);
    

    return 0;
}