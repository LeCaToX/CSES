#include <bits/stdc++.h>

using namespace std;

int a[200005];

int main() {
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int res = 0;
    int l = 0;
    for (int i = 1; i <= n; i++) {
        l = max(l, mp[a[i]]);
        res = max(res, i - l);
        mp[a[i]] = i;
    }
    cout << res;
}