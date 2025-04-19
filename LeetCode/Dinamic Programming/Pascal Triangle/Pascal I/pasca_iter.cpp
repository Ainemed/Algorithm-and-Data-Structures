#include <iostream>

using namespace std;

vector<int> generateAux(vector<int> tmp){
    vector<int> res;
    res.push_back(tmp.at(0));
    for(int i=0;i<tmp.size()-1;i++){
        res.push_back(tmp.at(i)+tmp.at(i+1));
    }
    res.push_back(tmp.at(tmp.size()-1));
    return res;
}
vector<vector<int>> generate(int numRows) {
    vector<vector<int>> res;
    vector<int> tmp;
    tmp.push_back(1);
    res.push_back(tmp);
    for(int i=1; i<numRows;i++){
        tmp = generateAux(tmp);
        res.push_back(tmp);
    }
    return res;
}

int main(){

    int numRows;
    cout<<"Dim: ";
    cin>>numRows;

    vector<vector<int>>  res = generate(numRows);
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