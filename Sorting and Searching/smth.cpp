#include <bits/stdc++.h>

using namespace std;

vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

int pre[1000005];

int main() {
    string s;
    cin >> s;
    vector<int> z = z_function(s);
    int n = z.size();
    pre[n]++;
    for (int i = 1; i < n; i++) pre[z[i]]++;
    for (int i = n; i >= 0; i--) {
        pre[i] += pre[i + 1];
    }
    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        cout << (((z[n - x] == x) && (pre[x] >= 3)) ? "YES " + to_string(pre[x])
                                                    : "NO")
             << "\n";
    }
}