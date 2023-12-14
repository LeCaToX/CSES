#include <bits/stdc++.h>
#define int long long
using namespace std;

long long d[505][505];

main() {
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i == j)
                d[i][j] = 0;
            else
                d[i][j] = 1e18;

    while (m--) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        d[u][v] = min(w, d[u][v]);
        d[v][u] = min(w, d[v][u]);
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            if (d[i][k] != 1e18)
                for (int j = 1; j <= n; j++)
                    if (d[k][j] != 1e18)
                        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << (d[a][b] == 1e18 ? -1 : d[a][b]) << "\n";
    }
}