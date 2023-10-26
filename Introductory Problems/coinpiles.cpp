#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;
    while (t--) {
        int a,b;
        cin>>a>>b;
        if (b<a) swap(a,b);
        if ((a+b)%3) {
            cout<<"NO\n";
        } else 
        if (2*a<b) {
            cout<<"NO\n";
        } else {
            cout<<"YES\n";
        }
    }
}