/**
 * Author: Théo Hollender
 * License: CC0
 * Description: Given $H[i]$, find in O(1) the sum of subintervals
 * Source: Yes*
 */

struct Cumul {
    vector<int> X;
    Cumul (vector<int> &A) : X(A.size() + 1) {
        for (int i = 0; i < A.size(); i ++) X[i + 1] = X[i] + A[i];
    }
    int sum (int l, int r) { return X[r + 1] - X[l]; }
};