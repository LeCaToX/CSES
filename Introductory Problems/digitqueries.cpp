#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string str(ll num){ll a = num;stringstream ss;ss << a;string str = ss.str();return str;}
ll k;
ll val[20];
ll cnt(ll x){
    string s=str(x);
    int t=s.size()-1;
    long long sum=0;
    for (int i=1;i<=t;i++)
        sum+=val[i];
    x-=sum;
    long long res=0;
    for (int i=1;i<=t;i++)
        res+=val[i]*i;
    return res+x*(t+1);
}
ll bs(ll x){
    ll l=1,r=1e18;
    while (l+1<r){
        ll m=(l+r)/2;
        if (cnt(m)>=x) r=m;
        else l=m;
    }
    return l;
}
int main(){
    val[1]=9;
    for (int i=2;i<=18;i++)
        val[i]=val[i-1]*10;
    int t;
    cin>>t;
    while (t--) {
        cin>>k;
        long long l=bs(k);
        k-=cnt(l);
        string s=str(l+1);
        cout<<s[k-1]<<"\n";
    }
    
}
    