#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;

int a[maxn];

struct ms {
    int val;
    int st;
};

struct segment_tree {
    ms nodes[4 * maxn];
    int size;
    ms merge(ms a, ms b) { return {-1, a.st + b.st}; }
    void build(int id, int l, int r) {
        if (l == r) {
            nodes[id] = {a[l], 1};
            return;
        }
        int m = (l + r) / 2;
        build(id * 2 + 1, l, m);
        build(id * 2 + 2, m + 1, r);
        nodes[id] = merge(nodes[id * 2 + 1], nodes[id * 2 + 2]);
    }
    void build() { build(0, 0, size - 1); }
    void update(int pos, int l, int r, int id) {
        if (l == r) {
            nodes[id].st = 0;
            return;
        }
        int m = (l + r) / 2;
        if (pos <= m)
            update(pos, l, m, id * 2 + 1);
        else
            update(pos, m + 1, r, id * 2 + 2);
        nodes[id] = merge(nodes[id * 2 + 1], nodes[id * 2 + 2]);
    }
    void update(int pos) { update(pos, 0, size - 1, 0); }
    int get(int val, int l, int r, int id) {
        if (l == r) {
            update(l);
            return nodes[id].val;
        }
        int m = (l + r) / 2;
        if (nodes[id * 2 + 1].st >= val)
            return get(val, l, m, id * 2 + 1);
        else
            return get(val - nodes[id * 2 + 1].st, m + 1, r, id * 2 + 2);
    }
    int get(int val) { return get(val, 0, size - 1, 0); }
} st;

int main() {
    int n;
    cin >> n;
    st.size = n;
    for (int i = 0; i < n; i++) cin >> a[i];
    st.build();
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cout << st.get(x) << " ";
    }
}