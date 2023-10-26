#include <bits/stdc++.h>

using namespace std;

int a[20];

int main() {
    int n;
    cin>>n;
    for (int i=0;i<(1<<n);i++){
        int val = (i^(i>>1));
        bitset<32> k(val);
        cout<<k.to_string().substr(32-n)<<"\n";
    }
}