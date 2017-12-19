#include <bits/stdc++.h>
using namespace std;

int spt[6005][15];
long long int spl[6005][15];
int lvl[6005];
vector<pair<int, int> > edges[6005];
void mktree(int cn, int par, int clvl){
//	if (clvl>100){ return; }
//	printf("%i %i %i\n", cn, par, clvl);
	lvl[cn]=clvl;
	spt[cn][0]=par;
	for(pair<int, int> tp:edges[cn]){
		if (tp.first == par){continue; }
		spl[tp.first][0]=tp.second;
		mktree(tp.first, cn, clvl+1);
	}
	return;
}
int main(){
	int n;
	scanf("%i", &n);
	int a, b, w;
	for(int i=0; i<n-1; i++){
		scanf("%i%i%i", &a, &b, &w);
		edges[a].push_back({b,w});
		edges[b].push_back({a,w});
	}
	mktree(0, -1, 0);
	for(int i=1; i<=log2(n); i++){
		for(int j=0; j<n; j++){
			if (spt[j][i-1]>=0){
				spt[j][i]=spt[spt[j][i-1]][i-1];
				spl[j][i]=spl[j][i-1]+spl[spt[j][i-1]][i-1];
			}
		}
	}
	int q;
	scanf("%i", &q);
	for(int i=0; i<q; i++){
		scanf("%i%i", &a, &b);
		long long int tt=0;
		while(lvl[a]>lvl[b]){
			int k = log2(lvl[a]-lvl[b]);
			tt+=spl[a][k];
			a=spt[a][k];
		}
		while(lvl[b]>lvl[a]){
			int k = log2(lvl[b]-lvl[a]);
			tt+=spl[b][k];
			b=spt[b][k];
		}
		while (a!=b){
			for(int j=log2(n); j>=0; j--){	
				if (j==0 || spt[a][j]!=spt[b][j]){
					tt+=spl[a][j]+spl[b][j];
					b=spt[b][j]; a=spt[a][j];
				//	printf("%i %i\n", a, b);
					break;
				}
			}
		}
		printf("%lli\n", tt);
	}
	return 0;
}