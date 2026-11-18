/**
 * Author: Théo Hollender
 * Date: 2025-11-01
 * Description: Simple BFS.
 * Status: stress-tested
 */

vector<vector<int>> adj; int N;

vector<int> bfs (int start) {
    queue<int> pos;
    vector<int> dists(N, -1);
    dists[start] = 0;
    pos.push(start);
    while (pos.size() != 0) {
        int curr = pos.front();
        pos.pop();
        for (int nei : adj[curr]) {
            if (dists[nei] == -1) {
                dists[nei] = dists[curr] + 1;
                pos.push(nei);
            }
        }
    }
    return dists;
}