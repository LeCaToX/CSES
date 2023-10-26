#include <bits/stdc++.h>

using namespace std;

int dp[1000005];

int cal(int x) {
    if (x == 0) return 0;
    if (dp[x] != 1000000000) return dp[x];
    int k = x;
    while (k > 0) {
        if (k % 10 != 0) {
            dp[x] = min(dp[x], cal(x - (k % 10)) + 1);
            // cout<<x<<"\n";
        }
        k /= 10;
    }
    return dp[x];
}

int main() {
    for (int i = 0; i <= 1000000; i++) dp[i] = 1000000000;
    int n;
    cin >> n;
    cout << cal(n);
}