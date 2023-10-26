#include <bits/stdc++.h>

using namespace std;

int res=0;
string s;
int dx[4]={0,1,-1,0},dy[4]={-1,0,0,1};
char di[4]={'L','D','U','R'};
bool tck[10][10];


bool check(string a,string b) {
    for (int i=0;i<a.size();i++)
        if (a[i]!='?'&&b[i]!='?') {
            if (a[i]!=b[i]) return false;
        }
    return true;
}

void dfs(int i,int j, int index) {
    if ((tck[i-1][j]&&tck[i+1][j])&&(!tck[i][j-1]&&!tck[i][j+1])) return;
    if ((!tck[i-1][j]&&!tck[i+1][j])&&(tck[i][j-1]&&tck[i][j+1])) return;
    //cout<<path<<"\n";
    //if (!check(path,s)) return;
    if (i==7&&j==1) {
        if (index!=s.size()) return;
        
        res++;
        //cout<<path<<"\n";
        return;
    }
    if (index==s.size()) return;
    tck[i][j]=true; 
    if (s[index]!='?') {
        if (s[index]=='L') 
            if (!tck[i][j-1]) {
                dfs(i,j-1,index+1);
            }
        if (s[index]=='D') 
            if (!tck[i+1][j]) {
                dfs(i+1,j,index+1);
            }
        if (s[index]=='U')
            if (!tck[i-1][j]) {
                dfs(i-1,j,index+1);
            }
        if (s[index]=='R')
            if (!tck[i][j+1]) {
                dfs(i,j+1,index+1);
            }
    } else
    for (int k=0;k<4;k++) {
        int x=i+dx[k],y=j+dy[k];
        if (x>=1&&x<=7&&y>=1&&y<=7) 
            if (!tck[x][y]) {
                dfs(x,y,index+1);
            }
    }
    tck[i][j]=false;
    return;
}

int main() {
    cin>>s;
    for (int i=1;i<=7;i++)
        for (int j=1;j<=7;j++)
            tck[i][j]=false;
    for (int i=0;i<=8;i++) {
        tck[0][i]=true;
        tck[i][0]=true;
        tck[8][i]=true;
        tck[i][8]=true;
    }
    string path="????????????????????????????????????????????????";
    dfs(1,1,0); 
    cout<<res;
}