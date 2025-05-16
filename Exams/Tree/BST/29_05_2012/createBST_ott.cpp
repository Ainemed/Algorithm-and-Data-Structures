#include <iostream>
#include <vector>

using namespace std;

struct Node{
    Node* left;
    Node* right;
    int key;

    Node(): key(-1), left(nullptr), right(nullptr) {}
    Node(int key): key(key), left(nullptr), right(nullptr) {}
    Node(int key, Node* left, Node* right): key(key), left(left), right(right) {}

};

struct BSTree{
    Node* root;

    BSTree(): root(nullptr){}
    BSTree(Node* root): root(root){}
};

bool isOrdered(vector<int> arr){
    bool m = true;
    int i=0;
    while(i<arr.size()-1 && m){
        if(arr.at(i)>arr.at(i+1)){
            m=false;
        }
        i++;
    }
    return m;
}

void insertionSort(vector<int>& arr){
    for(int i=1; i<arr.size();i++){
        int tmp=arr.at(i);
        int j=i-1;
        while(j>=0 && tmp < arr.at(j)){
            arr.at(j+1)=arr.at(j);
            j--;
        }
        arr.at(j+1)=tmp;
    }
}

void merge(vector<int>& arr, int p, int q, int r){
    int n1 = q-p+1;
    int n2=r-q;

    int max = arr.at(0);
    vector<int> tmp1, tmp2;

    for(int i=0; i<n1; i++){
        if(arr.at(p+i)>max){
            max=arr.at(p+i);
        }
        tmp1.push_back(arr.at(p+i));
    }
    for(int i=0; i<n2; i++){
        if(arr.at(q+i+1)>max){
            max= arr.at(q+i+1);
        }
        tmp2.push_back(arr.at(q+i+1));
    }

    tmp1.push_back(max+1);
    tmp2.push_back(max+2);

    int i=0, j=0;
    for(int k=p; k<=r; k++){
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
    if(arr.size()>=5 && arr.size()<= 25){
        insertionSort(arr);
    }else{
        if(p<r){
            int med=(r+p)/2, q=med;
            mergeSort(arr,p, med);
            mergeSort(arr, med+1, r);
            merge(arr, p, q, r);
        }
    }
}

Node* createBST_aux(vector<int> arr, int inf, int sup){
    if(inf>sup){
        return nullptr;
    }else{
        int med= (inf+sup)/2;
        Node* r = new Node(arr.at(med));
        r->left=createBST_aux(arr, inf, med-1);
        r->right=createBST_aux(arr, med+1, sup);
        return r;
    }
}

BSTree createBST(vector<int>& arr){
    if(!isOrdered(arr)){
        mergeSort(arr, 0, arr.size()-1);
    }
    BSTree tree;
    tree.root=createBST_aux(arr,0, arr.size()-1);
    return tree;
}

void seeBST(Node* v){
    if(v){
        cout<<v->key<<endl;
        seeBST(v->left);
        seeBST(v->right);
    }
}

int main(){

    int dim;
    vector<int> arr;
    cout<<"Dim: ";
    cin>>dim;

    for (size_t i = 0; i < dim; i++)
    {
        int tmp;
        cout<<"Elem "<<i+1<<" : ";
        cin>>tmp;
        arr.push_back(tmp);
    }

    BSTree tree = createBST(arr);
    seeBST(tree.root);

    return 0;
}