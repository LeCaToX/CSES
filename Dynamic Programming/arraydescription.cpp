#include <bits/stdc++.h>
#define int long long

using namespace std;

const int mod = 1e9 + 7;

int dp[100005][105];

int a[100005];

signed main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (a[1] != 0) {
        dp[1][a[1]] = 1;
    } else {
        for (int i = 1; i <= m; i++) dp[1][i] = 1;
    }
    for (int i = 1; i <= n; i++)
        if (a[i] == 0) {
            for (int j = 1; j <= m; j++) {
                if (j - 1 >= 1) dp[i][j] += dp[i - 1][j - 1] % mod;
                dp[i][j] %= mod;
                dp[i][j] += dp[i - 1][j];
                dp[i][j] %= mod;
                if (j + 1 <= m) dp[i][j] += dp[i - 1][j + 1] % mod;
                dp[i][j] %= mod;
            }
        } else {
            if (a[i] - 1 >= 1) dp[i][a[i]] += dp[i - 1][a[i] - 1] % mod;
            dp[i][a[i]] %= mod;
            dp[i][a[i]] += dp[i - 1][a[i]];
            dp[i][a[i]] %= mod;
            if (a[i] + 1 <= m) dp[i][a[i]] += dp[i - 1][a[i] + 1] % mod;
            dp[i][a[i]] %= mod;
        }
    long long res = 0;
    for (int i = 1; i <= m; i++) res = (res + dp[n][i]) % mod;
    cout << res;
}