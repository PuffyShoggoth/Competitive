#include <iostream>
#include <stdio.h>
using namespace std;
int stf[10009];
int flg[10009];
int s(int ca, int cb){
	int c=stf[ca], cnt=0;
	flg[ca]=1;
	for (int i=0; i<10000; i++){
		flg[i]=0;
	}
	while (flg[c]==0){
		flg[c]=1;
		if (c==cb){return cnt;}
		c=stf[c];
		cnt++;
	}
	return -1;
}
int main() {
	int n, x, y, m, a, b, ti=0, tx=9999, ty=9999;
	cin>>n;
	for(int i=0; i<n; i++){
		scanf("%i%i", &x, &y);
		stf[x]=y;
		tx=min(tx, x);
		ty=min(ty, y);
		ti=max(ti, i);
	}
	cin>>a>>b;
	while(a!=0 && b!=0){
		m=s(a, b);
		if (m>-1){cout<<"Yes "<<m<<"\n";}
		else{cout<<"No\n";}
		cin>>a>>b;
	}
	return 0;
}