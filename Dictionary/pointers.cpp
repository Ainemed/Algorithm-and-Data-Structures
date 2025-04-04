#include <iostream>
#include <map>
#include <string>


using namespace std;

template<typename T>
struct DicNode{
    int key;
    T info;
    DicNode<T>* next;
    DicNode<T>* prev;

    DicNode(): key(0), info(0), next(nullptr), prev(nullptr){}
    DicNode(int key, T info, DicNode<T>* next, DicNode<T>* prev): key(0), info(0), next(next), prev(prev){}
};
template<typename T>
struct Dictionary{
    DicNode<T>* head;

    Dictionary(): head(nullptr){}
    Dictionary(DicNode<T>* head): head(head){}
};


template<typename T>
void insertDic(Dictionary<T>& dic, T info, int key){
    DicNode<T>* elem = new DicNode<T>();
    elem->info=info;
    elem->key=key;
    elem->next = dic.head;
    
    if(dic.head){
        dic.head->prev = elem;
    }
    elem->prev = nullptr;
    dic.head = elem;
    
}
template<typename T>
void createDic(Dictionary<T>& dic){
    cout<<"Insert the Dictionary Size"<<endl;
    int dim;
    cout<<"Size: ";
    cin>>dim;

    for (size_t i = 0; i < dim; i++)
    {
        T elem;
        cout<<"Elem "<<i+1<<" : ";
        cin>>elem;
        insertDic(dic,elem, i);
    }
    
}

template<typename T>
T searchDic(Dictionary<T> dic, int key){
    DicNode<T>* x = dic.head;
    while (x!=nullptr && x->key != key)
    {
        x = x->next;
    }

    if(x){
        return x->info;
    }else{
        return NULL;
    }
    
}
template<typename T>
void printDic(Dictionary<T> dic){
    cout<<"----Print Dic----"<<endl;
    DicNode<T>* x = dic.head;
    while (x)
    {
        cout<<"Key: "<<x->key<<"  Info: "<<x->info<<endl;
        x = x->next;
    }
    
}

template<typename T>
void deleteDic(Dictionary<T>& dic, int key){
    DicNode<T>* x = dic.head;
    while (x)
    {
        if(x->key == key){
            if(x->next){
                x->next->prev = x->prev;
            }
            if(x->prev){
                x->prev->next = x->next;
            }else{
                dic.head = x->next;
            }
            DicNode<T>* temp=x;
            x = x->next;
            delete(temp);
        }else{
            x = x->next;
        }
    }
    
}

int main(){
    Dictionary<int> dic;

    createDic(dic);
    printDic(dic);
    cout<<"Search the Elem with the Key"<<endl;
    int key;
    cout<<"Key: ";
    cin>>key;
    int search = searchDic(dic, key);
    if(search!=NULL){
        cout<<"Search Elem: "<<search<<endl;
        deleteDic(dic,key);
        printDic(dic);
    }else{
        cout<<"The key doesn't exits"<<endl;
    }

    
    return 0;
}