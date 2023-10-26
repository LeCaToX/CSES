#include <bits/stdc++.h>

using namespace std;

int h[1005], s[1005];
int dp[1005][100005];  // max pages of price i uses books upto j

int main() {
    int n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; i++) cin >> h[i];
    for (int i = 1; i <= n; i++) cin >> s[i];
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= x; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j - h[i] >= 0) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - h[i]] + s[i]);
            }
        }
    cout << dp[n][x];
}