#include <bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = 2e5 + 5;

int a[maxn];

struct ms {
    int pre, sum;
};

struct segment_tree {
    ms nodes[4 * maxn];
    int size;
    ms merge(ms a, ms b) {
        ms res;
        res.pre = max({0LL, a.pre, a.sum + b.pre});
        res.sum = a.sum + b.sum;
        return res;
    }
    void build(int id, int l, int r) {
        if (l == r) {
            nodes[id] = {(max(0LL, a[l])), a[l]};
            return;
        }
        int m = (l + r) / 2;
        build(id * 2 + 1, l, m);
        build(id * 2 + 2, m + 1, r);
        nodes[id] = merge(nodes[id * 2 + 1], nodes[id * 2 + 2]);
    }
    void build() { build(0, 0, size - 1); }
    void update(int pos, int val, int l, int r, int id) {
        if (l == r) {
            nodes[id] = {max(0LL, val), val};
            return;
        }
        int m = (l + r) / 2;
        if (pos <= m)
            update(pos, val, l, m, id * 2 + 1);
        else
            update(pos, val, m + 1, r, id * 2 + 2);
        nodes[id] = merge(nodes[id * 2 + 1], nodes[id * 2 + 2]);
    }
    void update(int pos, int val) { update(pos, val, 0, size - 1, 0); }
    ms get(int u, int v, int l, int r, int id) {
        if (u > r || v < l) return {0, 0};
        if (u <= l && r <= v) return nodes[id];
        int m = (l + r) / 2;
        return merge(get(u, v, l, m, id * 2 + 1),
                     get(u, v, m + 1, r, id * 2 + 2));
    }
    int get(int u, int v) { return get(u, v, 0, size - 1, 0).pre; }
} st;

signed main() {
    int n, q;
    cin >> n >> q;
    st.size = n;
    for (int i = 0; i < n; i++) cin >> a[i];
    st.build();
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int k, u;
            cin >> k >> u;
            st.update(k - 1, u);
        } else {
            int l, r;
            cin >> l >> r;
            cout << st.get(l - 1, r - 1) << "\n";
        }
    }
}