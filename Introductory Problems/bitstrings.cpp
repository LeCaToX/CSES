#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;

long long binpow(long long a, long long b) {
    if (b==1) return a%MOD;
    long long k = binpow(a,b/2)%MOD;
    if (b%2) return k*k*a%MOD;
    else return k*k%MOD;
}

int main() {
    int n;
    cin>>n;
    cout<<binpow(2,n)%MOD;
}