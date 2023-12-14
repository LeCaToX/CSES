#include <bits/stdc++.h>

using namespace std;

struct edge {
    int u, v;
    long long w;
} e[5005];

vector<int> g[5005];
vector<int> g1[5005];

bool ck[5005];
bool ck1[5005];

void dfs(int x) {
    ck[x] = true;
    for (int u : g[x])
        if (!ck[u]) dfs(u);
}

void dfs1(int x) {
    ck1[x] = true;
    for (int u : g1[x])
        if (!ck1[u]) dfs1(u);
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> e[i].u >> e[i].v >> e[i].w;
        g[e[i].u].push_back(e[i].v);
        g1[e[i].v].push_back(e[i].u);
    }
    dfs(1);
    dfs1(n);
    vector<long long> d(n + 1, -100000000000000000);
    d[1] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            if (d[e[j].u] + e[j].w > d[e[j].v]) {
                d[e[j].v] = max(d[e[j].v], d[e[j].u] + e[j].w);
                if (i == n - 1) {
                    if (ck[e[j].v] && ck1[e[j].v]) {
                        cout << -1;
                        return 0;
                    }
                }
            }
    }
    cout << ((d[n] == -100000000000000000) ? -1 : d[n]);
}
