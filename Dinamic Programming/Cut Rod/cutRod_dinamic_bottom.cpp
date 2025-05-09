#include <iostream>

using namespace std;

/**
 * @brief Extended bottom-up rod cutting algorithm.
 *        Builds two arrays:
 *        - r[j]: stores the maximum revenue for a rod of length j
 *        - s[j]: stores the optimal first cut length to achieve that revenue
 * 
 * @param p Price list, where p[i] is the price of a rod of length i+1
 * @param n Length of the rod to cut
 * @param r Output vector of maximum revenues (filled by the function)
 * @param s Output vector of cut positions (used to reconstruct the optimal solution)
 * 
 * @complexity Θ(n^2), due to the nested loops in bottom-up dynamic programming
 */
void ext_bottom_up_cut_rod(const vector<int>& p, int n, vector<int>& r, vector<int>& s){
    r.resize(n + 1, 0);  // Initialize revenue array with zeros
    s.resize(n + 1, 0);  // Initialize solution array with zeros

    for(int j = 1; j <= n; j++){  // Iterate over rod lengths from 1 to n
        int q = -1;
        for(int i = 1; i <= j; i++){  // Try all possible first cuts
            if(q < p[i - 1] + r[j - i]){  // Check if this cut gives a better revenue
                q = p[i - 1] + r[j - i];  // Update the maximum revenue
                s[j] = i;  // Store the length of the first optimal cut
            }
        }
        r[j] = q;  // Store the optimal revenue for rod length j
    }
}

/**
 * @brief Bottom-up implementation of the rod cutting problem.
 *        Computes only the maximum obtainable revenue.
 * 
 * @param p Price list
 * @param n Rod length
 * @return int Maximum revenue for rod of length n
 * 
 * @complexity Θ(n^2), using bottom-up dynamic programming
 */
int bottom_up_cut_rod(const vector<int>& p, int n){
    vector<int> r(n + 1, 0);  // Initialize revenue array with zeros

    for(int j = 1; j <= n; j++){  // Iterate over rod lengths
        int q = -1;
        for(int i = 1; i <= j; i++){  // Try all possible first cuts
            q = max(q, p[i - 1] + r[j - i]);  // Choose the best among all cuts
        }
        r[j] = q;  // Store the result
    }

    return r[n];  // Return the best revenue for full rod length
}

/**
 * @brief Prints the sequence of optimal cuts to maximize profit.
 * 
 * @param p Price list
 * @param n Rod length
 * 
 * @complexity Θ(n^2), because it calls ext_bottom_up_cut_rod
 */
void print_cut_rod_sol(const vector<int>& p, int n){
    vector<int> r, s;
    ext_bottom_up_cut_rod(p, n, r, s);  // Compute optimal revenues and cuts

    while(n > 0){
        cout << s[n] << endl;  // Print the first cut length
        n -= s[n];  // Reduce rod length by the cut size
    }
}

int main(){
    
    return 0;
}