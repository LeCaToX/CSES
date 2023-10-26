#include <bits/stdc++.h>

using namespace std;

pair<int,int> a[200005];

int bs(int l,int r,int x) {
    int left=l-1;
    int right=r+1;
    while (left+1<right) {
        int m=(left+right)/2;
        if (a[m].first==x) {
            return m;
        }
        if (a[m].first<x) left=m;
        else right=m;
    }
    return -1;
}

int main() {
    int n,x;
    cin>>n>>x;
    for (int i=0;i<n;i++) {
        cin>>a[i].first;
        a[i].second=i;
    }
    sort(a,a+n);
    for (int i=0;i<n-1;i++) {
        int t=bs(i+1,n-1,x-a[i].first);
        if (t!=-1) {
            cout<<a[i].second+1<<" "<<a[t].second+1;
            return 0;
        }
    }
    cout<<"IMPOSSIBLE";
}