#include <iostream>
#include <map>
#include <string>


using namespace std;

class MyDictionary{
    public:
        MyDictionary(){
            this->key=0;
            this->value=0;
        }
        MyDictionary(int key, int value){
            this->key=key;
            this->value=value;
        }
        int getKey(){
            return this->key;
        }
        void setKey(int key){
            this->key=key;
        }
    private:
        int key;
        int value;
    
};

void createDic(map<int, int> &dic, int dim){
    cout<<"---Create Dictionary---"<<endl;
    for(int i=0; i<dim; i++){
        int tmp;
        cin>>tmp;
        dic[i]=tmp;
    }
}

void printDic(map<int, int> dic, int dim){
    cout<<"---Print Dictionary---"<<endl;
    for(int i=0; i<dic.size(); i++){
        cout<<"Key: "<<i<<"  Value: "<<dic.at(i)<<endl;
    }
}
int searchDic_index(map<int, int> dic, int k,int p, int dim){
    if(dim<p){
        return -1;
    }else{
        int med = (p+dim)/2;
        if(med == k){
            return med;
        }else{
            if(med>k){
                return searchDic_index(dic,k,p,med-1);
            }else{
                return searchDic_index(dic,k,med+1,dim);
            }
        }
    }
}
int searchDic(map<int, int> dic, int k){
    int i = searchDic_index(dic,k,1,dic.size());
    if (i==-1){
        return -1;
    }else{
        return dic.at(i);
    }
}
void deleteDic(map<int,int> dic, int k){
    cout<<"---Delete Element---"<<endl;
    int elem = searchDic_index(dic, k, 1, dic.size());
    for(int i=elem; i< dic.size()-1;i++){
        dic[i]=dic[i+1];
    }
    
}
int main(){

    map<int, int> dic;
    MyDictionary tryDic(1,2);
    cout<<tryDic.getKey()<<endl;
    int dim;
    cout<< "Insert Dictionary Length"<<endl;
    cin>>dim;
    createDic(dic, dim);
    printDic(dic, dim);
    int i = searchDic(dic,4);
    if(i==-1){
        cout<<"Key not found"<<endl;
    }else{
        cout<<i<<endl;
    }

    
    return 0;
}