#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Computes the length and direction table of the Longest Common Subsequence (LCS)
 * 
 * @param x vector of characters (1-based indexing, x[0] is unused)
 * @param y vector of characters (1-based indexing, y[0] is unused)
 * @param c matrix to store LCS lengths
 * @param b matrix to store direction of choices (1 = diagonal, 2 = up, 3 = left)
 * 
 * Complexity: Θ(m * n)
 */
void lcs_top(vector<char>& x, vector<char>& y, vector<vector<int>>& c, vector<vector<int>>& b){
    int m = x.size() - 1;
    int n = y.size() - 1;

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(x[i] == y[j]){
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = 1; // ↖ match
            } else if(c[i-1][j] >= c[i][j-1]){
                c[i][j] = c[i-1][j];
                b[i][j] = 2; // ↑ up
            } else {
                c[i][j] = c[i][j-1];
                b[i][j] = 3; // ← left
            }
        }
    }
}

/**
 * @brief Recursively prints the Longest Common Subsequence (LCS) based on the direction matrix `b`.
 * 
 * @param x Vector containing the first input sequence (characters)
 * @param b Direction matrix:
 *          - 1: diagonal move (↖), means characters match
 *          - 2: up move (↑), skip character in x
 *          - 3: left move (←), skip character in y
 * @param i Current index in x (rows of the matrix)
 * @param j Current index in y (columns of the matrix)
 * 
 * @complexity O(m + n) in the worst case:
 *     - The recursion visits at most `m + n` cells in a path from bottom-right to top-left.
 *     - This is a single path through the matrix (not all cells).
 */
void print_lcs_rec(vector<char> x, vector<vector<int>> b, int i, int j) {
    if (i >= 0 && j >= 0) {
        if (b.at(i).at(j) == 1) {
            // Characters match: move diagonally
            print_lcs_rec(x, b, i - 1, j - 1);
            cout << x.at(i); // Print the matching character
        } else if (b.at(i).at(j) == 2) {
            // Move up
            print_lcs_rec(x, b, i - 1, j);
        } else {
            // Move left
            print_lcs_rec(x, b, i, j - 1);
        }
    }
}

/**
 * @brief Recursive function to print the Longest Common Subsequence (LCS)
 *        using only the LCS length matrix `c`, without relying on a separate direction matrix.
 *
 * The function starts from cell (i, j) and follows the recursive pattern:
 * - If current cell value is equal to the cell above, move up.
 * - If equal to the left cell, move left.
 * - Otherwise, it's a match; recurse diagonally and then print the character.
 *
 * @param x First sequence
 * @param c LCS length matrix
 * @param i Current index in x
 * @param j Current index in y
 *
 * @complexity Time: O(m + n), where m and n are lengths of the input strings.
 *             In the worst case, it traverses m+n steps following the LCS path.
 */
void print_lcs_rec_ott(vector<char> x, vector<vector<int>> c, int i, int j) {
    if(i>=0 && j>=0){
        if(i>0 && c.at(i).at(j)==c.at(i-1).at(j)){
            print_lcs_rec_ott(x,c,i-1,j);
        }else if(j>0 && c.at(i).at(j)==c.at(i).at(j-1)){
            print_lcs_rec_ott(x,c,i,j-1);
        }else{
            if(i>0 && j>0){
                print_lcs_rec_ott(x,c,i-1,j-1);
            }
            cout<<x.at(i)<<endl;
        }
    }
}

/**
 * @brief Computes LCS matrices and starts recursive print of LCS.
 * 
 * @param b Direction matrix to be filled (for backtracking the LCS)
 * @param c Cost matrix: c[i][j] contains length of LCS of x[0..i] and y[0..j]
 * @param x First input sequence (as vector of characters)
 * @param y Second input sequence
 * 
 * @complexity Overall complexity: O(m * n)
 *     - The call to lcs(x, y, c, b) fills two matrices of size m x n → O(m * n)
 *     - The recursive print traverses one path from bottom-right to top-left → O(m + n)
 */
void print_lcs(vector<vector<int>>& b, vector<vector<int>>& c, vector<char>& x, vector<char>& y) {
    lcs_top(x, y, c, b); // Fills c and b matrices
    cout<<"---Normal Print---"<<endl;
    print_lcs_rec(x, b, x.size() - 1, y.size() - 1); // Recursively prints the LCS
    cout<<"---Optimize Print---"<<endl;
    print_lcs_rec_ott(x,c,x.size()-1,y.size()-1);
}

int main(){

    // Strings (add dummy element at index 0 to enable 1-based indexing)
    vector<char> x = {'0', 'A', 'C', 'T', 'A', 'C', 'C', 'T', 'G'};
    vector<char> y = {'0', 'A', 'T', 'C', 'A', 'C', 'C'};

    int m = x.size() - 1;
    int n = y.size() - 1;

    // Initialize LCS length and direction matrices
    vector<vector<int>> c(m + 1, vector<int>(n + 1, 0));
    vector<vector<int>> b(m + 1, vector<int>(n + 1, 0));

    // Output LCS
    cout << "Longest Common Subsequence: ";
    print_lcs(b,c,x,y);
    cout << endl;

    // Output length
    cout << "Length of LCS: " << c[m][n] << endl;

    return 0;
}