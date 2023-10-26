#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    set<int> ele;
    multiset<int> len;

    int n;
    int x;
    cin >> x >> n;
    ele.insert(0);
    ele.insert(x);
    len.insert(x);
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        ele.insert(k);
        auto it = ele.lower_bound(k);
        it--;
        auto it2 = ele.upper_bound(k);
        // cout << *it << " " << *it2 << "\n";
        len.erase(len.lower_bound(*it2 - *it));
        len.insert(*it2 - k);
        len.insert(k - *it);
        // for (auto k : len) cout << k << " ";
        // cout << "\n";
        cout << *(--len.end()) << "\n";
    }
}