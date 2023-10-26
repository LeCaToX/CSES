#include <bits/stdc++.h>

using namespace std;

int a[1005][1005];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void dfs(int i, int j) {
    a[i][j] = 0;
    for (int k = 0; k < 4; k++) {
        int x = i + dx[k];
        int y = j + dy[k];
        if (a[x][y] == 1) dfs(x, y);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            char c;
            cin >> c;
            a[i][j] = (c == '.');
        }
    int res = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i][j] == 1) {
                res++;
                dfs(i, j);
            }
    cout << res;
}