#include <bits/stdc++.h>

using namespace std;

pair <int,int> a[200005];

int main() {
    int n;
    cin>>n;
    for (int i=0;i<n;i++) {
        cin>>a[i].second>>a[i].first;
    }
    sort(a,a+n);
    int res=1;
    int endcur=a[0].first;
    for (int i=1;i<n;i++) {
        if (a[i].second>=endcur) {
            res++;
            endcur=a[i].first;
        }
    }
    cout<<res;
}