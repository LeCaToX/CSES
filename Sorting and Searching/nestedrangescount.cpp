#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

struct segment {
    int x, y, id;
} p[200005];

bool cmp(segment a, segment b) {
    return (a.x < b.x || (a.x == b.x && a.y < b.y));
}

bool cmp1(segment a, segment b) {
    return (a.x < b.x || (a.x == b.x && a.y > b.y));
}

int res1[200005];
int res2[200005];

const int inf = INT_MIN;

int n;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
        p[i].id = i;
    }
    sort(p, p + n, cmp1);

    ordered_set st;

    for (int i = 0; i < n; i++) {
        int val = i - st.order_of_key(p[i].y);
        res2[p[i].id] += val;
        st.insert(p[i].y);
    }

    ordered_set st1;

    sort(p, p + n, cmp1);

    for (int i = n - 1; i >= 0; i--) {
        int val = st1.order_of_key(p[i].y + 1);
        res1[p[i].id] += val;
        st1.insert(p[i].y);
    }
    for (int i = 0; i < n; i++) cout << res1[i] << " ";
    cout << "\n";
    for (int i = 0; i < n; i++) cout << res2[i] << " ";
}