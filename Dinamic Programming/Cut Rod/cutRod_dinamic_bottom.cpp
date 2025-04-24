#include <iostream>

using namespace std;

void ext_bottom_up_cut_rod(vector<int> p, int n, vector<int>& r, vector<int>& s){
    r.at(0)=0;
    for(int j=0;j<n;j++){
        int q=-1;
        for(int i=0;i<j;i++){
            if(q<p.at(i)+r.at(j-i)){
                q=p.at(i)+r.at(j-i);
                s.at(j)=i;
            }
        }
        r.at(j)=q;
    }
}

/**
 * @brief Complexity: Θ(n^2), better then dividi et impera solution
 * 
 * @param p 
 * @param n 
 * @return int 
 */
int bottom_up_cut_rod(vector<int> p, int n){
    vector<int> r;
    r.at(0)=0;
    for(int j=0; j<n;j++){
        int q=-1;
        for(int i=0;i<j;i++){
            q = max(q,p.at(i)+r.at(j-i));
        }
        r.at(j)=q;
    }
    return r.at(n);
}

/**
 * @brief Complexity: Θ(n^2), better then dividi et impera solution
 * 
 * @param p 
 * @param n 
 */
void print_cut_rod_sol(vector<int> p, int n){
    vector<int> r,s;
    ext_bottom_up_cut_rod(p,n,r,s);
    while(n>0){
        cout<<s.at(n)<<endl;
        n -= s.at(n);
    }
}

int main(){
    
    return 0;
}