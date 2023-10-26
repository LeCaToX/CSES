#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int res = 1;
    int d = 1;
    for (int i=1;i<s.length();i++) {
        if (s[i] == s[i-1]) d++;
        else d = 1;
        res=max(res,d);
    }
    cout<<res;
}