#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin>>s;
    map<char,int> mp;
    for (char c:s) 
        mp[c]++;
    int cnt=0;
    char mid;
    for (auto i:mp) 
        if (i.second%2) cnt++,mid=i.first;
    if (cnt>1) {
        cout<<"NO SOLUTION";
    } else {
        if (cnt==0) {
            string k = "";
            for (auto i:mp) 
                for (int j=0;j<i.second/2;j++) 
                    k+=i.first;
            cout<<k;
            reverse(k.begin(),k.end());
            cout<<k;
        } else {
            string k = "";
            for (auto i:mp) 
                for (int j=0;j<i.second/2;j++) 
                    k+=i.first;
            cout<<k;
            reverse(k.begin(),k.end());
            cout<<mid;
            cout<<k;
        }
    }
}