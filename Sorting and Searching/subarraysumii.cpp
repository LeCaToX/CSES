#include <bits/stdc++.h>
#define int long long
using namespace std;

long long a[200005], pre[200005];

signed main() {
    int n;
    long long x;
    cin >> n >> x;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
    map<long long, int> mp;
    mp[0] = 1;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        res += mp[pre[i] - x];
        mp[pre[i]]++;
    }
    cout << res;
}