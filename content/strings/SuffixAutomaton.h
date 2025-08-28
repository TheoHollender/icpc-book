/**
 * Author: ???
 * Description: Suffix Automaton
 */

const int maxN = (int)1e5 + 100;
map<char, int> to[maxN];
int link[maxN];
int len[maxN];
int last = 0;
int sz = 1;
void add_letter(char c) {
    int p = last;
    last = sz++;
    len[last] = len[p] + 1;
    for(; to[p][c] == 0; p = link[p]) {
        to[p][c] = last;
    }
    if (to[p][c] == last) {
        link[last] = 0;
        return;
    }
    int q = to[p][c];
    if (len[q] == len[p] + 1) {
        link[last] = q;
        return;
    }
    int cl = sz++;
    to[cl] = to[q];
    link[cl] = link[q];
    len[cl] = len[p] + 1;
    link[last] = link[q] = cl;
    for (; to[p][c] == q; p = link[p]) {
        to[p][c] = cl;
    }
}
// all states [0; sz - 1]
// no more than 2 * n states, no more than 3 * n edges => maxN = 2 * string length
// Any path from the root (= 0) is a substring
// All strings with the same set of endings are in one state
// link[p] - a reference to the minimum vertex that has a set of endings no less than (but it is incorrect that link[p] < p -> you cannot consider dynamics as a cycle, you need to write dfs)
// if we construct the graph link[p] -> p, we get a tree
// if we count f[v] = len[link[v]] + 1, we get that strings of length [f[v]; len[v]] are in one state (and each of them appears in the string the same number of times)