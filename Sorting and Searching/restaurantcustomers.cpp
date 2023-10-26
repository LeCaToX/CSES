#include <bits/stdc++.h>

using namespace std;

vector <pair <int,int> > point;

int main() {
    int n;
    cin>>n;
    for (int i=0;i<n;i++) {
        int a,b;
        cin>>a>>b;
        point.push_back({a,1});
        point.push_back({b,0});
    }
    sort(point.begin(),point.end());
    int res=0,cur=0;
    for (auto i:point) {
        if (i.second==0) {
            cur--;
        } else cur++;
        res=max(res,cur);
    }
    cout<<res;
}