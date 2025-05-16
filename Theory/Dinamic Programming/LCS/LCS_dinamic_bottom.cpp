#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Recursive LCS with memoization (Top-Down DP).
 * 
 * @param x First string
 * @param y Second string
 * @param i Current index in x
 * @param j Current index in y
 * @param memo Memoization matrix storing LCS lengths
 * @return int Length of LCS from x[0..i] and y[0..j]
 * 
 * @complexity Time: O(m * n), Space: O(m * n)
 */
int lcs_top_down(const string& x, const string& y, int i, int j, vector<vector<int>>& memo) {
    if (i == 0 || j == 0) return 0;
    if (memo[i][j] != -1) return memo[i][j];

    if (x[i - 1] == y[j - 1]) {
        memo[i][j] = 1 + lcs_top_down(x, y, i - 1, j - 1, memo);
    } else {
        memo[i][j] = max(lcs_top_down(x, y, i - 1, j, memo),
                        lcs_top_down(x, y, i, j - 1, memo));
    }
    return memo[i][j];
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
 * @brief Optimized recursive print of the LCS using only the memo table.
 * 
 * @param x First string
 * @param y Second string
 * @param i Current index in x
 * @param j Current index in y
 * @param memo Memoization matrix filled by lcs_top_down
 * 
 * @complexity Time: O(m + n), Space: O(1) auxiliary (not counting memo)
 */
void print_lcs(const string& x, const string& y, int i, int j, vector<vector<int>>& memo) {
    if (i == 0 || j == 0) return;

    if (x[i - 1] == y[j - 1]) {
        print_lcs(x, y, i - 1, j - 1, memo);
        cout << x[i - 1];  // Print in order
    } else if (memo[i - 1][j] >= memo[i][j - 1]) {
        print_lcs(x, y, i - 1, j, memo);
    } else {
        print_lcs(x, y, i, j - 1, memo);
    }
}

int main() {
    string x = "ACTACCTG";
    string y = "ATCACC";

    int m = x.size();
    int n = y.size();

    vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));

    // Calcola la lunghezza della LCS
    int len = lcs_top_down(x, y, m, n, memo);
    cout << "Length of LCS: " << len << endl;

    // Stampa la LCS
    cout << "LCS: ";
    print_lcs(x, y, m, n, memo);
    cout << endl;

    return 0;
}