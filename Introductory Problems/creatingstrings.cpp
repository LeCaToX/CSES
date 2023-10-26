#include <bits/stdc++.h>
 
using namespace std;

int main() {
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    vector<string> res;
    do {
        res.push_back(s);
    } while (next_permutation(s.begin(),s.end()));
    cout<<res.size()<<"\n";
    for (string k:res)  cout<<k<<"\n";
}