#include <bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = 2e5 + 5;

int a[maxn];
int b[maxn];

struct segment_tree {
    int nodes[4 * maxn];
    int size;
    void build(int l, int r, int id) {
        if (l == r) {
            nodes[id] = b[l];
            return;
        }
        int m = (l + r) / 2;
        build(l, m, id * 2 + 1);
        build(m + 1, r, id * 2 + 2);
        nodes[id] = min(nodes[id * 2 + 1], nodes[id * 2 + 2]);
    }
    void build() { build(0, size - 1, 0); }
    void update(int pos, int val, int l, int r, int id) {
        if (l == r) {
            nodes[id] = val;
            return;
        }
        int m = (l + r) / 2;
        if (pos <= m)
            update(pos, val, l, m, id * 2 + 1);
        else
            update(pos, val, m + 1, r, id * 2 + 2);
        nodes[id] = min(nodes[id * 2 + 1], nodes[id * 2 + 2]);
    }
    void update(int pos, int val) { update(pos, val, 0, size - 1, 0); }
    int get(int u, int v, int l, int r, int id) {
        if (u > r || v < l) return LLONG_MAX;
        if (u <= l && r <= v) return nodes[id];
        int m = (l + r) / 2;
        return min(get(u, v, l, m, id * 2 + 1),
                   get(u, v, m + 1, r, id * 2 + 2));
    }
    int get(int u, int v) { return get(u, v, 0, size - 1, 0); }
};

segment_tree stp;
segment_tree stm;

signed main() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) b[i] = a[i] + i;
    stp.size = n;
    stp.build();
    for (int i = 0; i < n; i++) b[i] = -i + a[i];
    stm.size = n;
    stm.build();
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int k, x;
            cin >> k >> x;
            k--;
            a[k] = x;
            stm.update(k, -k + x);
            stp.update(k, k + x);
        } else {
            int k;
            cin >> k;
            k--;
            // cout<<k<<" ";
            cout << min({a[k], -k + stp.get(k + 1, n - 1),
                         k + stm.get(0, k - 1)})
                 << "\n";
        }
    }
}