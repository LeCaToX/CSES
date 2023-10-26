#include <bits/stdc++.h>

#define int long long

using namespace std;

int a[25];

int getbit(int u,int v) {
    return (u>>v)&1;
}

signed main() {
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>a[i];
    int res=1e9;
    for (int i=0;i<(1<<n);i++) {
        int sum1=0,sum2=0;
        for (int v=0;v<n;v++)
            if (getbit(i,v)) sum1+=a[v];
            else sum2+=a[v];
        res=min(res,abs(sum1-sum2));    
    }
    cout<<res;
}