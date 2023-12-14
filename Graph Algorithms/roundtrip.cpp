#include <iostream>
#include <vector>
using namespace std;

int n, m, a, b, p[100005];
vector<int> v[100005], ans;

void dfs(int x, int pre) {
    for (int i : v[x]) {
        if (i == pre) continue;
        if (p[i]) {
            ans.push_back(x);
            while (ans.back() != i) {
                ans.push_back(p[ans.back()]);
            }
            ans.push_back(x);
            cout << ans.size() << "\n";
            for (int i : ans) {
                cout << i << " ";
            }
            exit(0);
        }
        p[i] = x;
        dfs(i, x);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (!p[i]) {
            p[i] = i;
            dfs(i, 0);
        }
    }
    cout << "IMPOSSIBLE\n";
}