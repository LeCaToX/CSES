#include <bits/stdc++.h>

using namespace std;

vector<int> g[200005];
bool check[200005];

void dfs(int x) {
    check[x] = true;
    for (auto u : g[x])
        if (!check[u]) dfs(u);
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> res;
    for (int i = 1; i <= n; i++)
        if (!check[i]) {
            dfs(i);
            res.push_back(i);
        }
    cout << res.size() - 1 << "\n";
    for (int i = 0; i < res.size() - 1; i++)
        cout << res[i] << " " << res[i + 1] << "\n";
}