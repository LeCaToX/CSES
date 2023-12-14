#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<pair<int, int> > g[100005];

main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({w, v});
    }
    priority_queue<pair<int, int>, vector<pair<int, int> >,
                   greater<pair<int, int> > >
        pq;
    vector<int> dist(n + 1, LLONG_MAX);
    pq.push({0, 1});
    dist[1] = 0;
    while (!pq.empty()) {
        int u = pq.top().second;
        int w = pq.top().first;
        pq.pop();
        if (dist[u] != w) continue;
        for (auto i : g[u]) {
            int v = i.second;
            int wt = i.first;
            if (dist[v] > dist[u] + wt) {
                dist[v] = dist[u] + wt;
                pq.push({dist[v], v});
            }
        }
    }
    for (int i = 1; i <= n; i++) cout << dist[i] << " ";
}