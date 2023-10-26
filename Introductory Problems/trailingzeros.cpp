#include <bits/stdc++.h>

using namespace std;

int main () {
    long long n;
    cin>>n;
    long long k = 1;
    long long res=0;
    while (n/(k*5)>0) {
        k*=5;
        res+=n/k;
    }
    cout<<res;
}