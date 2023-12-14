#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;
int main() {
    int n;
    cin >> n;
    ordered_set st;
    for (int i = 1; i <= n; i++) st.insert(i);
    int x = 1;
    while (st.size()) {
        x = x % st.size();
        auto k = st.find_by_order(x);
        st.erase(k);
        cout << *k << " ";
        x++;
    }
}