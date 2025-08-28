/**
 * Author: Théo Hollender
 * Date: 28/08/2005
 * Description: $O(nm \log n)$ algorithm for all pairs shortest path with negative edges but no negative cycles.
 * First, run Bellman-Ford starting all values at 0 on the graph, let the result be p(x). Then replace the weight of
 * edge (u -> v) by w' = w + p(u) - p(v). Now run $N$ Dijkstras, and for a pair (s, t), remove p(s) - p(t), which has
 * been added by the potential.
 */