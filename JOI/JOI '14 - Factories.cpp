#include <bits/stdc++.h>
#include "factories.h"
using namespace std;
vector<pair<int, int> > edges[500005];
bool isc[500005];
int cnt[500005], mx[500005], lch[500005], par[500005][20], idpar[500005];
long long int dpar[500005][20];
int cta=0;
int dfs(int cn, int tpar){
	cnt[cn]=1;
	mx[cn]=0;
	for(pair<int, int> tp: edges[cn]){
		if (isc[tp.first] || tp.first==tpar){
			continue;
		}
		int tpp = dfs(tp.first, cn);
		cnt[cn]+=tpp;
		if (mx[cn]<tpp){
			mx[cn]=tpp;
			lch[cn]=tp.first;
		}
	}
	return cnt[cn];
}
void dcomp(int ccent, int tpar);
void getcnt(int cn, int tpar, int tt){
	if (mx[cn]<=tt/2){
		dcomp(cn, tpar);
	}
	else{
		getcnt(lch[cn], cn, tt);
	}
}
void mrk(int cn, int tpar, int cid, long long int dist){
	par[cn][idpar[cn]]=cid;
	dpar[cn][idpar[cn]]=dist;
	idpar[cn]++;
	for(pair<int, int> tp: edges[cn]){
		if(!isc[tp.first] && tp.first!=tpar){
			mrk(tp.first, cn, cid, dist+tp.second);
		}
	}
}
void dcomp(int ccent, int tpar){
	isc[ccent] = 1;
	par[ccent][idpar[ccent]]=ccent;
	dpar[ccent][idpar[ccent]]=0;
	for(pair<int, int> tp: edges[ccent]){
		if(!isc[tp.first]){
			mrk(tp.first, ccent, ccent, tp.second);
			if (tp.first==tpar){
				dfs(tp.first, ccent);
			}
			getcnt(tp.first, ccent, cnt[tp.first]);
		}
	}
	return;
}
void Init(int N, int A[], int B[], int D[]){
	for(int i=0; i<N-1; i++){
		edges[A[i]].push_back({B[i], D[i]});
		edges[B[i]].push_back({A[i], D[i]});
	}
	int tt = dfs(0, -1);
	getcnt(0, -1, tt);
}
int pvc[500005];
long long mdst[500005];
long long Query(int S, int X[], int T, int Y[]){
	cta+=1;
	for(int i=0; i<S; i++){
		int cn = X[i];
		for(int j=0; j<=idpar[cn]; j++){
			int tpar = par[cn][j];
			if(pvc[tpar]==cta){
				mdst[tpar] = min(mdst[tpar], dpar[cn][j]);
			}
			else{
				mdst[tpar] = dpar[cn][j];
				pvc[tpar] = cta;
			}
		}
	}
	long long mn = -1;
	for(int i=0; i<T; i++){
		int cn = Y[i];
		for(int j=0; j<=idpar[cn]; j++){
			int tpar = par[cn][j];
			if(pvc[tpar]==cta){
				if (mn==-1){ mn = dpar[cn][j]+mdst[tpar]; }
				else{ mn = min(mn, dpar[cn][j]+mdst[tpar]);}
			}
		}
	}
	return mn;
}