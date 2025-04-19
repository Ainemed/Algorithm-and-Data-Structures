#include <iostream>

using namespace std;

void generateAux(vector<int>& tmp, vector<vector<int>>& sol, int numRows){
    vector<int> res;
    if(numRows>1){
        res.push_back(tmp.at(0));
        for(int i=0;i<tmp.size()-1;i++){
            res.push_back(tmp.at(i)+tmp.at(i+1));
        }
        res.push_back(tmp.at(tmp.size()-1));
        tmp = res;
        sol.push_back(res);
        generateAux(tmp,sol,numRows-1);
    }
}


vector<vector<int>> generate_ric(int numRows) {
    vector<vector<int>> res;
    if(numRows==0) return res;
    vector<int> tmp;
    tmp.push_back(1);
    res.push_back(tmp);
    
    generateAux(tmp,res, numRows);
    
    return res;
}

int main(){

    int numRows;
    cout<<"Dim: ";
    cin>>numRows;

    vector<vector<int>>  res = generate_ric(numRows);
    cout<<'[';
    for (size_t i = 0; i < res.size(); i++)
    {
        cout<<'[';
        for (size_t j = 0; j < res.at(i).size(); j++)
        {
            cout<<res.at(i).at(j)<<',';
        }
        cout<<"],";
        
    }
    cout<<']';
    

    return 0;
}