#include <iostream>
#include <vector>

using namespace std;

int memo_cut_rod_top_aux(vector<int>& p, int j, vector<int>& r){
    if(r.at(j)<0){
        int q;
        if(j==0){
            q=0;
        }else{
            q=-1;
            for(int i=0; i<j;i++){
                q = max(q, p.at(i)+memo_cut_rod_top_aux(p, j-i-1,r));
            }
        }
        r.at(j)=q;
    }
    return r.at(j);
}

int memo_cut_rod_top(vector<int>& p, int n){
    vector<int> r(n+1,-1);
    return memo_cut_rod_top_aux(p,n,r);
}

int memo_cut_rod_bottom(vector<int>& p, int n){
    vector<int> r(n+1,0);
    for(int j=1; j<=n; j++){
        int q=-1;
        for(int i=1; i<=j;i++){
            q=max(q, p.at(i-1)+r.at(j-i));
        }
        r.at(j)=q;
    }
    return r.at(n);
}

void ext_memo_cut_rod_bottom(vector<int>& p, int n, vector<int>& r, vector<int>& s){
    r.resize(n+1,0);
    s.resize(n+1,0);
    for(int j=1; j<=n; j++){
        int q=-1;
        for(int i=1;i<=j;i++){
            if(q<p.at(i-1)+r.at(j-i)){
                q = p.at(i-1)+r.at(j-i);
                s.at(j)=i;
            }
        }
    }
    
}

void print_cut_rod(vector<int>& p, int n){
    vector<int> r,s;
    ext_memo_cut_rod_bottom(p,n,r,s);
    while (n>0)
    {
        cout<<s.at(n)<<endl;
        n -=s.at(n);
    }
    
}

int main(){
    int dim;
    cout<<"Dim: ";
    cin>>dim;
    vector<int> arr;
    for (int i = 0; i < dim; i++)
    {
        int tmp;
        cout<<"Elem "<<i+1<<" : ";
        cin>>tmp;
        arr.push_back(tmp);
    }
    //int cut= memo_cut_rod_bottom(arr,arr.size());
    //cout<<"Cut "<<cut<<endl;
    
    print_cut_rod(arr,arr.size());


    return 0;
}