#include <iostream>
#include<string>
#include<vector>

using namespace std;

void lcs(string x, string y, vector<vector<int>>& c ,vector<vector<int>>& b){
    int m = x.size()-1;
    int n = y.size()-1;
    for(int i=1; i<=m; i++){
        for(int j=1;j<=n;j++){
            if(x.at(i)==y.at(j)){
                c.at(i).at(j)=c.at(i-1).at(j-1);
                b.at(i).at(j)=1;
            }else if(c.at(i-1).at(j)>=c.at(i).at(j-1)){
                c.at(i).at(j)=c.at(i-1).at(j);
                b.at(i).at(j)=2;
            }else{
                c.at(i).at(j)=c.at(i).at(j-1);
                b.at(i).at(j)=3;
            }
        }
    }
}

void print_lcs_rec(string x, vector<vector<int>> b, int i, int j){
    if(i>=0 && j>=0){
        if(b.at(i).at(j)==1){
            print_lcs_rec(x,b,i-1,j-1);
            cout<<x.at(i);
        }else if(b.at(i).at(j)==2){
            print_lcs_rec(x,b,i-1,j);
        }else{
            print_lcs_rec(x,b,i,j-1);
        }
    }
}

void print_lcs(string x, string y, vector<vector<int>>& c ,vector<vector<int>>& b){
    lcs(x,y,c,b);
    print_lcs_rec(x,b,x.size()-1,y.size()-1);
}


int main(){
    string x,y;
    cout<<"String X: ";
    cin>>x;
    cout<<"String Y: ";
    cin>>y;
    vector<vector<int>> c(x.size(),vector<int>(y.size(),0));
    vector<vector<int>> b(x.size(),vector<int>(y.size(),0));
    print_lcs(x,y,c,b);

    return 0;
}