#include <bits/stdc++.h>

using namespace std;

struct pp {
    long long w;
    int v;
    int st;
};

vector<pair<long long, int> > g[100005];

long long d[100005][2];

struct cmp {
    bool operator()(const pp& a, const pp& b) { return a.w > b.w; }
};

int main() {
    int n, m;
    cin >> n >> m;
    while (m--) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        g[u].push_back({w, v});
    }
    priority_queue<pp, vector<pp>, cmp> pq;
    for (int i = 1; i <= n; i++) d[i][0] = d[i][1] = LLONG_MAX;
    d[1][0] = d[1][1] = 0;
    pq.push({0, 1, 0});
    while (!pq.empty()) {
        pp tm = pq.top();
        pq.pop();
        if (d[tm.v][tm.st] != tm.w) continue;
        for (auto u : g[tm.v]) {
            if (tm.st == 0) {
                if (d[tm.v][0] + u.first < d[u.second][0]) {
                    d[u.second][0] = d[tm.v][0] + u.first;
                    pq.push({d[u.second][0], u.second, 0});
                }
                if (d[tm.v][0] + u.first / 2 < d[u.second][1]) {
                    d[u.second][1] = d[tm.v][0] + u.first / 2;
                    pq.push({d[u.second][1], u.second, 1});
                }
            }
            if (tm.st == 1) {
                if (d[tm.v][1] + u.first < d[u.second][1]) {
                    d[u.second][1] = d[tm.v][1] + u.first;
                    pq.push({d[u.second][1], u.second, 1});
                }
            }
        }
    }
    cout << min(d[n][0], d[n][1]);
}