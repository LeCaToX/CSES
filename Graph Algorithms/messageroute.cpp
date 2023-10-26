#include <bits/stdc++.h>

using namespace std;

vector<int> g[100005];
int dis[100005];
int pre[100005];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) dis[i] = 1000000000;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dis[1] = 0;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int k = q.front();
        q.pop();
        for (auto x : g[k])
            if (dis[x] == 1000000000) {
                q.push(x);
                dis[x] = dis[k] + 1;
                pre[x] = k;
            }
    }
    if (dis[n] == 1000000000) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    cout << dis[n] + 1 << "\n";
    vector<int> res;
    res.push_back(n);
    while (pre[n] > 0) {
        n = pre[n];
        res.push_back(n);
    }
    reverse(res.begin(), res.end());
    for (auto x : res) cout << x << " ";
}