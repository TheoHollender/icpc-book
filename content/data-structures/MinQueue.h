/**
 * Author: Théo Hollender
 * Date: 2025-08-23
 * License: CC0
 * Source: My head
 * Description: Linear time min on queue.
 * Status: tested on day 6 problem F of Pafos Camp 2025
 */
template<typename T> struct MinQueue {
    deque<pair<T, int>> q;
    void push (int i, T v) { // <= for max queue
        while (q.size() != 0 && q.back().first >= v)
            q.pop_back();
        q.push_back({ v, i }); }
    void pop (int i) { // pop in order of adds !!!
        while (q.size() != 0 && q.front().second == i)
            q.pop_front(); }
    T min () {
        return q.front().first; } };