#include <bits/stdc++.h>

using namespace std;

int main() {
    multiset<int> st;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        auto it = st.upper_bound(x);
        st.insert(x);
        if (it != st.end()) {
            st.erase(it);
        }
    }
    cout << st.size();
}