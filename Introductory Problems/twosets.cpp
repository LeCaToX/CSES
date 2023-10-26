#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin>>n;
    if (n%4==0) {
        cout<<"YES\n";
        vector<int> res1;
        vector<int> res2;
        for (int i=1;i<=n;i++) {
            if (i%4==1||i%4==0)
                res1.push_back(i);
            else res2.push_back(i);  
        }
        cout<<res1.size()<<"\n";
        for (int x:res1) cout<<x<<" ";
        cout<<"\n"<<res2.size()<<"\n";
        for (int x:res2) cout<<x<<" ";
    } else if ((n-3)%4==0) {
        cout<<"YES\n";
        vector<int> res1;
        vector<int> res2;
        res1.push_back(1);
        res1.push_back(n-1);
        res2.push_back(n);
        for (int i=2;i<=n-2;i++) {
            if (i%4==1||i%4==2)
                res1.push_back(i);
            else res2.push_back(i);
        }
        cout<<res1.size()<<"\n";
        for (int x:res1) cout<<x<<" ";
        cout<<"\n"<<res2.size()<<"\n";
        for (int x:res2) cout<<x<<" ";
    } else {
        cout<<"NO";
    }
}