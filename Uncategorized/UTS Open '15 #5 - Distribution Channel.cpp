#include <cstdio>
#include <utility>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int dsj[50005], rnk[50005], lvl[50005];
int net;
vector<pair<int, pair<int, int> > > edges, unused;
vector<pair<int, int> > mstedge[50005];
int anc[50005][20], spt[50005][20];
int n;
void mtree(int cn, int par, int w, int l){
	net++;
	anc[cn][0]=par; spt[cn][0]=w; lvl[cn]=l;
	for(auto tp: mstedge[cn]){
		if (tp.first==par){ continue; }
		mtree(tp.first, cn, tp.second, l+1);
	}
	return;
}
void join(int a, int b){
	if (rnk[a]==rnk[b]){
		rnk[a]++; dsj[b]=a;
	}
	else if (rnk[a]>rnk[b]){
		dsj[b]=a;
	}
	else{
		dsj[a]=b;
	}
	return;
}
int root(int a){
	while(dsj[a]){
		a=dsj[a];
	}
	return a;
}
int lca(int a, int b){
	int k;
	while(a!=b){
	    k=-1;
		for(int i=0; anc[a][i]!=anc[b][i]; i++){
			k=i;
		}
		if (k<0){ return anc[a][0]; }
		a=anc[a][k]; b=anc[b][k];
	}
	return a;
}
int main(){
	int m, a, b, w, k, tt=0, q, sbt=-1;
	scanf("%i%i", &n, &m);
	for(int i=0; i<m; i++){
		scanf("%i%i%i", &a, &b, &w);
		edges.push_back({w,{a,b}});
	}
	sort(edges.begin(), edges.end());
	for(auto tp: edges){
		a=root(tp.second.first); b=root(tp.second.second);
		if (a==b) { unused.push_back(tp); continue; }
		mstedge[tp.second.first].push_back({tp.second.second, tp.first});
		mstedge[tp.second.second].push_back({tp.second.first, tp.first});
		tt+=tp.first;
		join(a, b);
	}
	mtree(1, -1, -1, 0);
	if (net!=n){printf("-1");}
	else{
	for(int j=1; (1<<j)<=n; j++){
		for(int i=1; i<=n; i++){
			anc[i][j]=anc[anc[i][j-1]][j-1];
			spt[i][j]=max(spt[i][j-1], spt[anc[i][j-1]][j-1]);
		}
	}
	int mx;
	for(auto tp: unused){
		a=tp.second.first; b=tp.second.second; w=tp.first;
		mx=0;
		while (lvl[a]>lvl[b]){
			k=log2(lvl[a]-lvl[b]);
			mx=max(mx, spt[a][k]);
			a=anc[a][k];
		}
		while (lvl[a]<lvl[b]){
			k=log2(lvl[b]-lvl[a]);
			mx=max(mx, spt[b][k]);
			b=anc[b][k];
		}
		q=lca(a, b);
		while(a!=q){
			k=log2(lvl[a]-lvl[q]);
			mx=max(mx, spt[a][k]);
			a=anc[a][k];
		}
		while(b!=q){
			k=log2(lvl[b]-lvl[q]);
			mx=max(mx, spt[b][k]);
			b=anc[b][k];
		}
		if (mx==w){ continue; }
		if (sbt<0 || sbt>(tt-mx+w)){
			sbt=tt-mx+w;
		}
	}
	printf("%i", sbt);
	}
	return 0;

}