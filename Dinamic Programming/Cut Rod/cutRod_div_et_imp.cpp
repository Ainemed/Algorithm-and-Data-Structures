#include <iostream>

using namespace std;

/**
 * @brief Complexity: O(2^n), extremely bad
 * 
 * @param p  Vettore dei prezzi, dove p[i] è il prezzo di un'asta di lunghezza i+1
 * @param n  Lunghezza dell'asta da tagliare
 * @return int  Ricavo massimo ottenibile
 */
int cut_rod(vector<int> p,int n){
    if(n==0){
        return 0;
    }else{
        int q =-1;
        for(int i=0; i<n;i++){
            q = max(q,p.at(i)+cut_rod(p,n-i-1));
        }
        return q;
    }
}

int main(){
    
    return 0;
}