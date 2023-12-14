#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e5 + 5;

int a[maxn];

struct segment_tree {
    int nodes[4 * maxn];
    int size;
    void build(int id, int l, int r) {
        if (l == r) {
            nodes[id] = a[l];
            return;
        }
        int m = (l + r) / 2;
        build(id * 2 + 1, l, m);
        build(id * 2 + 2, m + 1, r);
        nodes[id] = max(nodes[id * 2 + 1], nodes[id * 2 + 2]);
    }
    void init() { build(0, 0, size - 1); }
    void update(int pos, int val, int l, int r, int id) {
        if (l == r) {
            nodes[id] -= val;
            return;
        }
        int m = (l + r) / 2;
        if (pos <= m)
            update(pos, val, l, m, id * 2 + 1);
        else
            update(pos, val, m + 1, r, id * 2 + 2);
        nodes[id] = max(nodes[id * 2 + 1], nodes[id * 2 + 2]);
    }
    void update(int pos, int val) { update(pos, val, 0, size - 1, 0); }
    int get(int val, int l, int r, int id) {
        if (l == r) {
            update(l, val, 0, size - 1, 0);
            return l + 1;
        }
        int m = (l + r) / 2;
        if (val <= nodes[id * 2 + 1])
            return get(val, l, m, id * 2 + 1);
        else
            return get(val, m + 1, r, id * 2 + 2);
    }
    int get(int val) { return get(val, 0, size - 1, 0); }
} st;

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    st.size = n;
    st.init();
    // cout<<st.nodes[4]<<"\n";
    while (m--) {
        int x;
        cin >> x;
        if (st.nodes[0] < x) {
            cout << 0 << " ";
        } else {
            cout << st.get(x) << " ";
        }
    }
}