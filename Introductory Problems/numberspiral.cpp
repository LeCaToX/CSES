#include <bits/stdc++.h>

using namespace std;
#define int long long
signed main() {
    int t;
    cin>>t;
    while (t--) {
        int x,y;
        cin>>y>>x;
        int lay = (max(x,y)-2)*2+1;
        long long sum = ((lay+1)*(((lay-1)/2)+1))/2;
        if ((x-2)*2+1==lay) {
            if (x%2==0) {
                cout<<sum+y;
            } else {
                cout<<sum+2*(x-1)+1-y+1;
            }
        }
        else {
            if (y%2==0) {
                cout<<sum+2*(y-1)+1-x+1;
            } else {
                cout<<sum+x;
            }
        }
        cout<<endl;
    }
}