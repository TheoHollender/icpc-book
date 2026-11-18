/**
 * Author: Théo Hollender
 * License: CC0
 * Description: Given $H[i]$, find for each i the maximal j < i such that $H[j] > i$,
 * or -1 if it doesn't exist.
 * Source: Yes*
 */

// Untested, check quickly that it works
vector<int> closest_higher (vector<int> &A) {
    vector<pair<int, int>> Q = { { 1e18, -1 } };
    vector<int> R(A.size());
    for (int i = 0; i < A.size(); i ++) {
        while (Q.back().first <= A[i]) Q.pop_back();
        R[i] = Q.back().second;
        Q.push_back({ A[i], i });
    }
    return R;
}