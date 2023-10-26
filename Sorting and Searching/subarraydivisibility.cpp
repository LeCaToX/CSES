#include <bits/stdc++.h>
#define int long long
using namespace std;

long long a[200005], pre[200005];

signed main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += n * 1000000000;
        a[i] %= n;
    }
    // for (int i = 1; i <= n; i++) cout << a[i] << " ";
    for (int i = 1; i <= n; i++) pre[i] = (pre[i - 1] + a[i]) % n;
    map<long long, int> mp;
    mp[0] = 1;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        res += mp[pre[i] - n];
        res += mp[pre[i]];
        mp[pre[i]]++;
    }
    cout << res;
}