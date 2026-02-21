#include <iostream>
#include <vector>

using namespace std;

int cut_top_aux(vector<int>& p, int n, vector<int>& r){
    int q;
    if(r[n]>=0) return r[n];
    if(n==0) q=0;
    else{
        q=-1;
        for(int i=1;i<=n;i++){
            q=max(q,p[i]+cut_top_aux(p,n-i,r));
        }
    }
    r[n]=q;
    return q;
}

int cut_top(vector<int>& p, int n){
    vector<int> r(n+1,-1);
    return cut_top_aux(p,n,r);
}

int main(){
    cout<<"lol"<<endl;
    
    return 0;
}