#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 2e5 + 5;
int a[maxn];

struct segment_tree {
    int size;
    int nodes[4 * maxn];
    int merge(int a, int b) { return a + b; }
    void update(int x, int val, int l, int r, int id) {
        if (l == r) {
            nodes[id] += val;
            return;
        }
        int m = (l + r) / 2;
        if (x <= m)
            update(x, val, l, m, id * 2 + 1);
        else
            update(x, val, m + 1, r, id * 2 + 2);
        nodes[id] = merge(nodes[id * 2 + 1], nodes[id * 2 + 2]);
    }
    void update(int x, int val) { update(x, val, 0, size - 1, 0); }
    int get(int u, int v, int l, int r, int id) {
        if (v < l || u > r) return 0;
        if (u <= l && r <= v) return nodes[id];
        int m = (l + r) / 2;
        return merge(get(u, v, l, m, id * 2 + 1),
                     get(u, v, m + 1, r, id * 2 + 2));
    }
    int get(int u, int v) { return get(u, v, 0, size - 1, 0); }
} st;

signed main() {
    int n, q;
    cin >> n >> q;
    st.size = n + 1;
    for (int i = 0; i < n; i++) cin >> a[i];
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r, val;
            cin >> l >> r >> val;
            l--;
            st.update(l, val);
            st.update(r, -val);
        } else {
            int k;
            cin >> k;
            k--;
            cout << a[k] + st.get(0, k) << "\n";
        }
    }
}