/**
 * Author: Théo Hollender
 * Date: 2025-11-01
 * Description: Simple Dijkstra.
 * Status: stress-tested
 */

vector<vector<pair<int, int>>> adj; // { next, cost }
int N;

vector<int> dijkstra (int start) {
    priority_queue<pair<int, int>> pos;
    vector<int> dists(N, INFINITY); // 1e18 for long long
    dists[start] = 0;
    pos.push({ 0, start });
    while (pos.size() != 0) {
        pair<int, int> curr = pos.top();
        pos.pop();
        int node = curr.second;
        int dist = - curr.first;
        if (dists[node] != dist) continue ;
        for (auto [nei, cst] : adj[node]) {
            if (dist + cst < dists[nei]) {
                dists[nei] = dist + cst;
                pos.push({ - dists[nei], nei });
            }
        }
    }
    return dists;
}