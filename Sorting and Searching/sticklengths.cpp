#include <bits/stdc++.h>

using namespace std;

int a[200005];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    int mid = a[(n + 1) / 2];
    long long res = 0;
    for (int i = 1; i <= n; i++) res += abs(a[i] - mid);
    cout << res;
}