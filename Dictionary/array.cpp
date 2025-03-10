#include <iostream>

using namespace std;

template <typename Key, typename Elem> 
class Record{
    public:
        Key key;
        Elem info;
        
        Record(int key, int info){
            this->key=key;
            this->info=info;
        }
        Record(){
            this->info=0;
            this->key=0;
        }
};

/**
 * @brief Create an Array Dictionary Data Structure
 * 
 * @param dic 
 */
void createDic(vector<Record<int,int> >& dic){
    int dim;
    cout<<"Size: ";
    cin>>dim;

    cout<<"--Create Dictionary--"<<endl;
    for (size_t i = 0; i < dim; i++)
    {
        int info=0, key=0;
        cout<<"Record n: "<<i+1<<endl;
        cout<<"Key: ";
        cin>>key;
        cout<<"Info: ";
        cin>>info;
        cout<<"---------"<<endl;
        Record<int,int> elem(key,info);
        dic.push_back(elem);
    }
    
}

/**
 * @brief Print an Array Dictionary Data Structure
 * 
 * @param dic 
 */
void printDic(vector<Record<int,int> > dic){
    cout<<"---Print Dictionary---"<<endl;
    for (size_t i = 0; i < dic.size(); i++)
    {
        cout<<"key: "<<dic.at(i).key<<" info: "<<dic.at(i).info<<endl;
    }
}

/**
 * @brief Index function for search function
 * 
 * @param dic 
 * @param key 
 * @param p 
 * @param r 
 * @return int 
 */
int searchDic_index(vector<Record<int,int> > dic, int key, int p, int r){
    if(r<=p){
        return -1;
    }else{
        int med= (p+r)/2;
        cout<<med<<endl;
        if(dic.at(med).key==key){
            return med;
        }else{
            if(dic.at(med).key>key){
                return searchDic_index(dic,key,p,med-1);
            }else{
                return searchDic_index(dic,key,med+1,r);
            }
        }
    }
}

/**
 * @brief Search a specific key in Array Dictionary Data Structure
 * 
 * @param dic 
 * @param key 
 * @return int 
 */
int searchDic(vector<Record<int,int> > dic, int key){
    int i = searchDic_index(dic,key,0,dic.size());
    if(i==-1){
        return -1;
    }else{
        return dic.at(i).info;
    }
}


void insertDic(vector<Record<int,int> >& dic, int info, int key){
    int i=0;
    while(i<dic.size() && dic.at(i).key<key){
        i++;
    }
    if(i<dic.size() and dic.at(i).key == key){
        dic.at(i).info = info;
    }else{
        Record<int,int> elem(key,info);
        cout<<i<<endl;
        if(i==dic.size()-1){
            dic.push_back(elem);
        }else{
            int j=i;
            while(j<dic.size()){
                Record<int,int> tmp=dic.at(j);
                dic.at(j)=elem;
                elem=tmp;
                j++;
            }
            dic.push_back(elem);
            
        }
        
    }
}


int main(){
    
    vector<Record<int,int> > dic;
    createDic(dic);
    printDic(dic);

    /*
    int key;
    cout<<"Search the key: ";
    cin>>key;
    int search = searchDic(dic,key);
    if(search==-1){
        cout<<"key Not found"<<endl;
    }else{
        cout<<"Elem: "<<search<<" Key: "<<key<<endl;
    }
    */
    
    cout<<"Element to insert: "<<endl;
    int infoElem, keyElem;
    cout<<"Key: ";
    cin>>keyElem;
    cout<<"Info: ";
    cin>>infoElem;
    insertDic(dic,infoElem,keyElem);

    printDic(dic);
    

    return 0;
}