#include <bits/stdc++.h>

using namespace std;

int n, x;
int a[105];
int dp[1000005];

int main() {
    for (int i = 1; i <= 1000000; i++) dp[i] = 1000000000;
    int n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[a[i]] = 1;
    }
    for (int i = 1; i <= x; i++)
        for (int j = 1; j <= n; j++)
            if (i - a[j] > 0) {
                dp[i] = min(dp[i], dp[i - a[j]] + 1);
            }
    cout << ((dp[x] == 1000000000) ? -1 : dp[x]);
}