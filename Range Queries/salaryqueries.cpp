#include <bits/stdc++.h>
using namespace std;
#define maxn 200005
int a[maxn];
int x[maxn], y[maxn];
char type[maxn];
typedef long long ll;
struct FT {
    vector<ll> s;
    FT(int n) : s(n) {}
    void update(int pos, ll dif) {  // a[pos] += dif
        for (; pos < s.size(); pos |= pos + 1) s[pos] += dif;
    }
    ll query(int pos) {  // sum of values in [0, pos)
        ll res = 0;
        for (; pos > 0; pos &= pos - 1) res += s[pos - 1];
        return res;
    }
    ll get(int l, int r) { return query(r + 1) - query(l); }
};
vector<int> tmp;
map<int, int> mp;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, cnt = 0;
    cin >> n >> m;

    vector<int> a(n);
    vector<int> x(m), y(m);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        tmp.push_back(a[i]);
    }

    for (int i = 0; i < m; i++) {
        cin >> type[i] >> x[i] >> y[i];
        tmp.push_back(y[i]);
        if (type[i] == '?') tmp.push_back(x[i]);
    }

    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());

    FT st(4 * tmp.size());

    for (auto i : tmp) {
        mp[i] = ++cnt;
    }

    for (int i = 0; i < n; i++) {
        st.update(mp[a[i]], 1);
    }

    for (int i = 0; i < m; i++) {
        if (type[i] == '!') {
            int pos = x[i], val = y[i];
            pos -= 1;
            st.update(mp[a[pos]], -1);
            a[pos] = val;
            st.update(mp[val], 1);
        } else {
            int u = mp[x[i]], v = mp[y[i]];
            cout << st.get(u, v) << '\n';
        }
    }
    return 0;
}