#include<bits/stdc++.h>
using namespace std;
char chess[8][8];
int res=0;
bool ld[15], rd[15], row[7];
void rec(int q){
	if (q==8) {res++; return;}
	for (int i=0;i<8;i++) {
		if (chess[i][q]=='.' && ld[i-q+7]==0 && rd[i+q]==0 && row[i]==0){
			ld[i-q+7]=1, rd[i+q]=1, row[i]=1;
			rec(q+1);
			ld[i-q+7]=0, rd[i+q]=0, row[i]=0;
		}
	}
}
int main(){
	for (int i=0;i<8;i++)
        for (int j=0;j<8;j++)
            cin>>chess[i][j];
	rec(0);
	cout<<res;
}