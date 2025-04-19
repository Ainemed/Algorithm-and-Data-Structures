#include <iostream>

using namespace std;

void getRowAux(vector<int>& tmp, int rowIndex){
    vector<int> res;
    if(rowIndex>0){
        res.push_back(tmp.at(0));
        for(int i=0;i<tmp.size()-1;i++){
            res.push_back(tmp.at(i)+tmp.at(i+1));
        }
        res.push_back(tmp.at(tmp.size()-1));
        tmp = res;
        getRowAux(tmp, rowIndex-1);
    }
}
vector<int> getRow(int rowIndex) {
    vector<int> tmp;
    tmp.push_back(1);
    if(rowIndex==0) return tmp;
    getRowAux(tmp,rowIndex);
    return tmp;
    
}

int main(){

    int numRows;
    cout<<"Dim: ";
    cin>>numRows;

    vector<int>  res = getRow(numRows);
    cout<<'[';
    for (size_t i = 0; i < res.size(); i++)
    {
        cout<<res.at(i)<<", ";
        
    }
    cout<<']';
    

    return 0;
}