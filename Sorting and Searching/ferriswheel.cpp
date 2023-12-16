#include <bits/stdc++.h>

using namespace std;

int a[200005];

int main() {
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int i = 0, j = n - 1;
    int res = 0;
    while (i < j) {
        if (a[i] + a[j] <= x) {
            res++;
            i++;
            j--;
        } else {
            res++;
            j--;
        }
    }
    cout << res + (i == j);
}