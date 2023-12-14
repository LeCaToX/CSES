#include <bits/stdc++.h>

using namespace std;

vector<int> g[200005];
int d[200005];
bool check[200005];
bool bi;

void bfs(int i, int x) {
    d[i] = x;
    check[i] = true;
    queue<int> q;
    q.push(i);
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        for (auto u : g[t])
            if (!check[u]) {
                d[u] = (d[t] == 1) ? 2 : 1;
                check[u] = true;
                q.push(u);
            } else {
                if (d[u] == d[t]) bi = true;
            }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (!check[i]) {
            bfs(i, 1);
        }
    }
    if (bi) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    for (int i = 1; i <= n; i++) cout << d[i] << " ";
}