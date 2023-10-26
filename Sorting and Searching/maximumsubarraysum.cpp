#include <bits/stdc++.h>

#define int long long

using namespace std;

int a[200005];

signed main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    int cur = 0;
    int res = -1e9;
    for (int i = 0; i < n; i++) {
        cur += a[i];
        res = max(res, cur);
        if (cur < 0) cur = 0;
    }
    cout << res;
}