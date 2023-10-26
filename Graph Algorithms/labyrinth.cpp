#include <bits/stdc++.h>

using namespace std;

char a[1005][1005];
bool vis[1005][1005];
int dis[1005][1005];
char pre[1005][1005];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int di[4] = {'R', 'D', 'L', 'U'};

int main() {
    int n, m;
    cin >> n >> m;
    pair<int, int> start;
    pair<int, int> end;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'A') start = {i, j};
            if (a[i][j] == 'B') end = {i, j};
            pre[i][j] = '\0';
        }
    queue<pair<int, int> > q;
    q.push(start);
    dis[start.first][start.second] = 0;
    vis[start.first][start.second] = true;
    while (!q.empty()) {
        pair<int, int> tmp = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
            int x = tmp.first + dx[k];
            int y = tmp.second + dy[k];
            if (!vis[x][y] && x >= 1 && x <= n && y >= 1 && y <= m &&
                a[x][y] != '#') {
                dis[x][y] = dis[tmp.first][tmp.second] + 1;
                vis[x][y] = true;
                pre[x][y] = di[k];
                q.push({x, y});
            }
        }
    }
    if (dis[end.first][end.second] == 0) {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    cout << dis[end.first][end.second] << "\n";
    string res = "";
    int x = end.first;
    int y = end.second;
    while (pre[x][y] != '\0') {
        // cout << x << " " << y << "\n";
        res += pre[x][y];
        if (pre[x][y] == 'L') {
            y += 1;
        } else if (pre[x][y] == 'R') {
            y -= 1;
        } else if (pre[x][y] == 'D') {
            x -= 1;
        } else if (pre[x][y] == 'U') {
            x += 1;
        }
    }
    reverse(res.begin(), res.end());
    cout << res;
    // cout << pre[2][7];
}