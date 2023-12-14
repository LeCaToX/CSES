#include <bits/stdc++.h>

using namespace std;

int a[1001][1001];
int pre[1001][1001];

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            char c;
            cin >> c;
            a[i][j] = (c == '*');
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            pre[i][j] =
                pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + a[i][j];
    while (q--) {
        int y1, x1, y2, x2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << pre[x2][y2] - pre[x2][y1 - 1] - pre[x1 - 1][y2] +
                    pre[x1 - 1][y1 - 1]
             << "\n";
    }
}