#include <bits/stdc++.h>

using namespace std;

void move(int n,int A, int B, int C) {
    if (n==1) {
        cout<<A<<" "<<C<<"\n";
    } else {
        move(n-1,A,C,B);
        move(1,A,B,C);
        move(n-1,B,A,C);
    }
}

int main() {
    int n;
    cin>>n;
    cout<<pow(2,n)-1<<"\n";
    move(n,1,2,3);
}