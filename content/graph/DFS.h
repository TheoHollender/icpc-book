/**
 * Author: Théo Hollender
 * Date: 2025-11-01
 * Description: Simple DFS on a tree.
 * Status: stress-tested
 */

vector<vector<int>> adj;
vector<bool> parents, depth;

void dfs(int current_node, int parent, int _depth = 0) {
    depth[current_node] = _depth;
    parents[current_node] = parent;

	for (int neighbor : adj[current_node]) if (neighbor != parent)
        { dfs(neighbor, current_node, _depth + 1); }
}