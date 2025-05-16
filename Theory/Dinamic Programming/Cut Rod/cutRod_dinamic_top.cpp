#include <iostream>

using namespace std;

/**
 * @brief Funzione ausiliaria per il taglio dell'asta con memoization.
 *        Complessità: Θ(n^2)
 * 
 * @param p Vettore dei prezzi (p[0] corrisponde al prezzo di lunghezza 1)
 * @param j Lunghezza dell’asta corrente da analizzare
 * @param r Vettore memoization, r[i] = miglior ricavo per lunghezza i
 * @return Ricavo massimo per lunghezza j
 */
int memorized_cut_rod_aux(const vector<int>& p, int j, vector<int>& r){
    if(r[j] < 0){ // Se non è stato ancora calcolato
        int q;
        if(j == 0){
            q = 0;
        } else {
            q = -1;
            for(int i = 0; i < j; i++){
                q = max(q, p[i] + memorized_cut_rod_aux(p, j - i - 1, r));
            }
        }
        r[j] = q; // Memoization: salviamo il risultato
    }
    return r[j];
}

/**
 * @brief Funzione principale per calcolare il ricavo massimo con memoization.
 *        Complessità: Θ(n^2), molto più efficiente della versione ricorsiva semplice.
 * 
 * @param p Vettore dei prezzi, dove p[i] è il prezzo per asta di lunghezza i+1
 * @param n Lunghezza dell’asta da tagliare
 * @return Ricavo massimo ottenibile
 */
int memorized_cut_rod(const vector<int>& p, int n){
    vector<int> r(n + 1, -1); // Inizializziamo con -1, dimensione n+1 per gestire j == 0
    return memorized_cut_rod_aux(p, n, r);
}

int main(){
    
    return 0;
}