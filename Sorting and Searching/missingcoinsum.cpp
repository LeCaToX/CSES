#include <bits/stdc++.h>

using namespace std;

int a[200005];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    long long res = 0;
    for (int i = 0; i < n; i++) {
        if (res + 1 < a[i])
            break;
        else
            res += a[i];
    }
    cout << res + 1;
}