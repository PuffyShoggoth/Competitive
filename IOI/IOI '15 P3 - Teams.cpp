#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int n;
vector<int> segtree[1050000];
vector<int> arr[500005];
int taken[1050000];
int lazy[1050000];
int sz[1050000];
int lupd[1050000];
int cqr = 0;
void build(int ind, int l, int r){
	if(l==r){
		for(int i: arr[l]){segtree[ind].push_back(i);}
		sort(segtree[ind].begin(), segtree[ind].end());
		sz[ind]=segtree[ind].size();
		return;
	}
	int m = (l+r)/2;
	build(ind*2, l, m); build(ind*2+1, m+1, r);
	sz[ind]=sz[ind*2]+sz[ind*2+1];
	int i1 = 0, i2 = 0;
	while(i1<segtree[ind*2].size() && i2<segtree[ind*2+1].size()){
		if(segtree[ind*2][i1]<=segtree[ind*2+1][i2]){
			segtree[ind].push_back(segtree[ind*2][i1]); i1++;
		}
		else{
			segtree[ind].push_back(segtree[ind*2+1][i2]); i2++;
		}
	}
	while(i1<segtree[ind*2].size()){ segtree[ind].push_back(segtree[ind*2][i1]); i1++;}
	while(i2<segtree[ind*2+1].size()){segtree[ind].push_back(segtree[ind*2+1][i2]); i2++;}
	
}
int query(int ind, int l, int r, int cm, int rm){
	int m = (l+r)/2;
	if(lupd[ind]!=cqr){ taken[ind]=0; lazy[ind] = 0; lupd[ind]=cqr;}

	if(cm>l){
		if(lazy[ind]){
			if(l!=r){
				lazy[ind*2]=lazy[ind]; lazy[ind*2+1]=lazy[ind]; 
				if(lupd[ind*2]!=cqr){ lupd[ind*2]=cqr; taken[ind*2]=0; }
				if(lupd[ind*2+1]!=cqr){ lupd[ind*2+1]=cqr; taken[ind*2+1]=0; }
			}
			lazy[ind]=0;
		}
		if(cm<=m){
			int tp = query(ind*2, l, m, cm, rm);
			if(tp<rm){return tp+query(ind*2+1, m+1, r, cm, rm-tp);}
			else{return tp;}
		}
		else{
			return query(ind*2+1, m+1, r, cm, rm);
		}
	}
	if(lazy[ind]){
		int nav2 = upper_bound(segtree[ind].begin(), segtree[ind].end(), lazy[ind])-segtree[ind].begin();
		if(l!=r){
			lazy[ind*2]=lazy[ind]; lazy[ind*2+1]=lazy[ind]; 
			if(lupd[ind*2]!=cqr){ lupd[ind*2]=cqr; taken[ind*2]=0; }
			if(lupd[ind*2+1]!=cqr){ lupd[ind*2+1]=cqr; taken[ind*2+1]=0; }
		}
		taken[ind] = nav2;
		lazy[ind]=0;
	}
	
	int nav = upper_bound(segtree[ind].begin(), segtree[ind].end(), cm)-segtree[ind].begin();
	if(nav-taken[ind]<=rm){
		if(l!=r){
			lazy[ind*2]=cm; lazy[ind*2+1]=cm; 
			if(lupd[ind*2]!=cqr){ lupd[ind*2]=cqr; taken[ind*2]=0; }
			if(lupd[ind*2+1]!=cqr){ lupd[ind*2+1]=cqr; taken[ind*2+1]=0; }
		}
		int tp = nav-taken[ind];
		taken[ind]= nav;
		return tp;
	}
	else{
		taken[ind]+=rm;
		if(l==r){ return rm;}
		if(cm<=m){
			int ptt = query(ind*2, l, m, cm, rm);
			if(ptt<rm){ query(ind*2+1, m+1, r, cm, rm-ptt);}
		}
		else{
			query(ind*2+1, m+1, r, cm, rm);
		}
		return rm;
	}

}
void init(int N, int A[], int B[]){
	for(int i=0; i<N; i++){
		arr[B[i]].push_back(A[i]);
	}
	build(1, 1, N);
	n = N;

}

int can(int M, int K[]){
	sort(K, K+M);
	int pv = 0, prv = 0;
	cqr++;
	for(int i=0; i<M; i++){
		if(query(1, 1, n, K[i], K[i])<K[i]){
			return 0;
		}
	}
	return 1;
}