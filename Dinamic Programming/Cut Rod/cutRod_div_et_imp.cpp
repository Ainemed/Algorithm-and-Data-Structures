#include <iostream>

using namespace std;

/**
 * @brief Complexity: O(2^n), extremely bad
 * 
 * @param p 
 * @param n 
 * @return int 
 */
int cut_rod(vector<int> p,int n){
    if(n==0){
        return 0;
    }else{
        int q =-1;
        for(int i=0; i<n;i++){
            q = max(q,p.at(i)+cut_rod(p,n-1));
        }
        return q;
    }
}

int main(){
    
    return 0;
}