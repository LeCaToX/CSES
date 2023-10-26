#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int n, x;
int a[105];
int dp[1000005];

int main() {
    for (int i = 1; i <= 1000000; i++) dp[i] = 0;
    int n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dp[0] = 1;
    for (int j = 1; j <= n; j++)
        for (int i = 0; i <= x; i++)
            if (i - a[j] >= 0) {
                dp[i] = (dp[i] + dp[i - a[j]]) % mod;
            }
    cout << dp[x];
}