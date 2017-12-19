#include <iostream>
#include <cstdio>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
char _;
int adj[5009][5009];
int pncl[5009];
int cts[5009];
int flg[5009];
int main() {
	int n, t, x, y, c, k, p, d, cv, nv, mv, tmnt=999999999;
	cin>>n>>t;
	for (int i=0; i<=n; i++){
		pncl[i]=-1;
		cts[i]=999999999;
	}
	for (int i=0; i<t; i++){
		scan(x); scan(y); scan(c);
		if (adj[x][y]==0 || adj[x][y]>c){
			adj[x][y]=c;
			adj[y][x]=c;
		}
	}
	cin>>k;
	for (int i=0; i<k; i++){
		scan(c); scan(p);
		if (pncl[c]==-1){pncl[c]=p;}
		else{pncl[c]=min(pncl[c], p);}
	}
	cin>>d;
	cv=d;
	cts[d]=0;
	while (cv!=0){
		nv=0;
		mv=999999999;
		flg[cv]=1;
		if (pncl[cv]!=-1){tmnt=min(tmnt, cts[cv]+pncl[cv]);}
		if (cts[cv]>=tmnt){cv=0; break;}
		for (int i=1; i<=n; i++){
			if (adj[cv][i]==0){continue;}
			if (flg[i]==1){continue;}
			cts[i]=min(cts[cv]+adj[cv][i], cts[i]);
			if (cts[i]<mv){
				mv=cts[i];
				nv=i;
			}
		}
		cv=nv;
	}
	cout<<tmnt;
	return 0;
}