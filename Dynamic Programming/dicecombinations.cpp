#include <bits/stdc++.h>
#define int long long
using namespace std;

int dp[1000005];

const int mod = 1e9 + 7;

signed main() {
    int n;
    cin >> n;
    for (int i = 1; i <= 6; i++) dp[i] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 6; j++)
            if (i - j > 0) dp[i] = (dp[i] + dp[i - j]) % mod;
    }
    cout << dp[n];
}