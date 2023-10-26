#include <bits/stdc++.h>

using namespace std;

int a[200005],b[200005];

int main() {
    int n,m,k;
    cin>>n>>m>>k;
    for (int i=0;i<n;i++)
        cin>>a[i];
    for (int i=0;i<m;i++)
        cin>>b[i];
    sort(a,a+n);
    sort(b,b+m);
    int i=0,j=0;
    int res=0;
    while (i<n&&j<m) {
        if (a[i]-k<=b[j]&&b[j]<=a[i]+k) {
            i++;
            j++;
            res++;
        } else {
            if (a[i]-k>b[j]) {
                j++;
            }
            else i++;
        }
    }
    cout<<res;
}