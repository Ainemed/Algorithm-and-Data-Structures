#include <iostream>

using namespace std;

int memorized_cut_rod_aux(vector<int> p, int j, vector<int> r){
    if(r.at(j)<0){
        if(j==0){
            r.at(j)=0;
        }else{
            int q = -1;
            for(int i=0; i<j;i++){
                q = max(q, p.at(i)+memorized_cut_rod_aux(p,j-i,r));
            }
        }
    }
    return r.at(j);
}
/**
 * @brief Complexity: Θ(n^2), better then dividi et impera solution
 * 
 * @param p 
 * @param n 
 * @return int 
 */
int memorized_cut_rod(vector<int> p, int n){
    vector<int> r;
    for(int i=0;i<n;i++){
        r.push_back(-1);
    }
    return memorized_cut_rod_aux(p,n,r);
}

int main(){
    
    return 0;
}