/**
 * Author: Théo Hollender
 * Date: 2025-11-01
 * Description: Finds the minimum spanning tree.
 * Status: stress-tested
 */
#pragma once

#include "UnionFind.h"

pair<vector<bool>, int> find_mst (int N, int M, vector<pair<int, int>> &roads, vector<int> &weights) {
    // Union Find is in data structure section
    vector<bool> res(M); int val = 0; UF ufd(N);
    vector<int> I(M); iota(I.begin(), I.end(), 0);
    sort(I.begin(), I.end(), [&](int i, int j) { return weights[i] < weights[j]; });
    for (int i : I) {
        auto [a, b] = roads[i];
        if (ufd.join(a, b)) {
            val += weights[i];
            res[i] = true;
        }
    }
    return { res, val };
}