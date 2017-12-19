#include <cstdio>
#include <functional>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
string names[105];
int dp[125];
int nxt[125];
int tt[105];
int m, q;
void nmx(int cn){
	if (cn>=m) return;
	int tmx=tt[cn], tn=cn, ttp=1200000000;
	for(int i=1; i<q; i++){
		if (!dp[cn+i]) nmx(cn+i);
		if (dp[cn+i]+tmx<ttp){
			ttp=dp[cn+i]+tmx;
			nxt[cn]=cn+i;
		}
		tmx=max(tmx, tt[cn+i]);
	}
	dp[cn]=ttp;
	return;
}
	

int main() {
	int tmx;
	cin>>q>>m;
	memset(nxt, -1, 500);
	for(int i=0; i<m; i++){
		cin>>names[i]>>tt[i];
		
	}
	for(int i=m-1; i>=0; i--){
		tmx=tt[i]; dp[i]=1000000000; 
		for(int j=i+1; j<=i+q; j++){
			if (dp[i]>dp[j]+tmx){
				nxt[i]=j;
				dp[i]=dp[j]+tmx;
			}
			tmx=max(tmx, tt[j]);
		}
		
	}
	tmx=0;
	printf("Total Time: %i", dp[0]);
	while(tmx>=0){
		cout<<'\n';
		if (nxt[tmx]<0){
			for(int i=tmx; i<m; i++){
				cout<<names[i]<<" ";
			}
		}
		else{
			for(int i=tmx; i<nxt[tmx]; i++){
				cout<<names[i]<<" ";
			}
		}
		tmx=nxt[tmx];
	}
	return 0;
}