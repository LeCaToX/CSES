#include <bits/stdc++.h>

using namespace std;

int a[2000005];
int pos[2000005];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    int res = 1;
    int cur = 1;
    while (cur < n) {
        if (pos[cur] < pos[cur + 1]) {
            cur += 1;
        } else {
            cur += 1;
            res++;
        }
    }
    cout << res;
}