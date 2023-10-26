#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7;
int a[1005][1005];
int dp[1005][1005];

signed main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            char c;
            cin >> c;
            a[i][j] = (c == '.');
        }
    dp[1][1] = a[1][1];
    for (int i = 2; i <= n; i++) {
        dp[i][1] = dp[i - 1][1] & a[i][1];
        dp[1][i] = dp[1][i - 1] & a[1][i];
    }
    for (int i = 2; i <= n; i++)
        for (int j = 2; j <= n; j++)
            if (a[i][j]) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                dp[i][j] %= mod;
            }

    cout << dp[n][n];
}