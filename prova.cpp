#include <iostream>
#include <list>
#include <cmath>

using namespace std;

int decryptNum(vector<int> num){
    int res=0, i=0;
    for(int elem: num){
        res += elem*pow(3,i);
        i++;
    }
    return res;
}

vector<int> encryptNum(int num){
    vector<int> res;
    while(num!=0){
        if(num%3==0){
            res.push_back(0);
        }else if(num%3==1){
            res.push_back(1);
        }else{
            res.push_back(2);
        }
        num=num/3;
    }
    return res;
}

vector<int> successor(vector<int> num){
    int elem = decryptNum(num);
    elem++;
    return encryptNum(elem);
    
}


bool leq(vector<int> l1,vector<int> l2){
    int num1 = decryptNum(l1), num2= decryptNum(l2);
    if(num1<=num2){
        return true;
    }else{
        return false;
    }
}

vector<int> tritwise_min(vector<int> l1, vector<int>l2){
    vector<int> res;
    int i=0;
    while(i<l1.size() && i<l2.size()){
        if(l1.at(i)<=l2.at(i)){
            res.push_back(l1.at(i));
        }else{
            res.push_back(l2.at(i));
        }
        i++;
    }
    return res;
}

vector<vector<int>> f(vector<int> A, vector<int> B){
    vector<vector<int>> res;
    int dim = decryptNum(B);
    vector<int> elem =successor(A);
    int i = decryptNum(elem);
    while(i< dim){
        vector<int> first = successor(encryptNum(i));
        
        
    }
}


int main(){
    
    vector<int> num;
    vector<int> num2;
    cout<<12/3<<endl;
    for(int i=0; i<3;i++){
        int tmp;
        cout<<"Elem "<<i+1<<": ";
        cin>>tmp;
        num.push_back(tmp);
    }
    
    for(int elem: num){
        cout<<elem<<endl;
    }
    cout<<"-- "<<decryptNum(num)<<endl;
    cout<<"-----"<<endl;
    for(int i=0; i<3;i++){
        int tmp;
        cout<<"Elem "<<i+1<<": ";
        cin>>tmp;
        num2.push_back(tmp);
    }
    
    for(int elem: num2){
        cout<<elem<<endl;
    }
    cout<<"-- "<<decryptNum(num2)<<endl;
    vector<int> res = tritwise_min(num,num2);
    for(int elem: res){
        cout<<elem<<endl;
    }
    

        
    return 0;
}