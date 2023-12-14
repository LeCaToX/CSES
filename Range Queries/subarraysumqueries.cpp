#include <bits/stdc++.h>
using namespace std;
#define maxn 200005
#define int long long
int a[maxn];
struct ms {
    int seg, pre, suf, sum;
};
struct segment_tree {
    ms nodes[4 * maxn];
    int size;
    ms merge(ms a, ms b) {
        int seg = max(max(a.seg, b.seg), a.suf + b.pre);
        int pre = max(a.pre, a.sum + b.pre);
        int suf = max(b.suf, b.sum + a.suf);
        int sum = a.sum + b.sum;
        return {seg, pre, suf, sum};
    }
    void init(int l, int r, int id) {
        if (l == r) {
            if (a[l] > 0)
                nodes[id] = {a[l], a[l], a[l], a[l]};
            else
                nodes[id] = {0, 0, 0, a[l]};
            return;
        }
        int mid = (l + r) / 2;
        init(l, mid, id * 2 + 1);
        init(mid + 1, r, id * 2 + 2);
        nodes[id] = merge(nodes[id * 2 + 1], nodes[id * 2 + 2]);
    }
    void build() { init(0, size - 1, 0); }
    void update(int x, int val, int l, int r, int id) {
        if (l == r) {
            if (val > 0)
                nodes[id] = {val, val, val, val};
            else
                nodes[id] = {0, 0, 0, val};
            return;
        }
        int mid = (l + r) / 2;
        if (x <= mid)
            update(x, val, l, mid, id * 2 + 1);
        else
            update(x, val, mid + 1, r, id * 2 + 2);

        nodes[id] = merge(nodes[id * 2 + 1], nodes[id * 2 + 2]);
    }
    void update(int x, int val) { update(x, val, 0, size - 1, 0); }
    ms get(int u, int v, int l, int r, int id) {
        if (r < u || v < l) return {0, 0, 0, 0};
        if (u <= l && r <= v) return nodes[id];
        int mid = (l + r) / 2;
        return merge(get(u, v, l, mid, id * 2 + 1),
                     get(u, v, mid + 1, r, id * 2 + 2));
    }
    int get() { return get(0, size - 1, 0, size - 1, 0).seg; }
} st;
signed main() {
    int m;
    cin >> st.size >> m;
    for (int i = 0; i < st.size; i++) cin >> a[i];
    st.build();
    while (m--) {
        int i, v;
        cin >> i >> v;
        i--;
        st.update(i, v);
        cout << st.get() << '\n';
    }
}