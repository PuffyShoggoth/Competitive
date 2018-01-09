#include <bits/stdc++.h>
using namespace std;
long long int segtree[400005];
int nvals[400005];
vector<pair<int, int> > srtd;
int sind[100005];
int cvals[100005];
vector<long long int> mxd1a(250005,0);
vector<long long int> mxd2a(250005,0);
vector<long long int> mxd1b(250005,0);
vector<long long int> mxd2b(250005,0);
void build(int ind, int l, int r){
	if(l==r){
		sind[srtd[l].second]=ind;
		segtree[ind]=srtd[l].first;
		nvals[ind]=1;
	}
	else{
		build(ind*2, l, (l+r)/2);
		build(ind*2+1, (l+r)/2+1, r);
		segtree[ind]=segtree[ind*2]+segtree[ind*2+1];
		nvals[ind]=nvals[ind*2]+nvals[ind*2+1];
	}
	return;
}
void update(int city, int val, int num){
	int ind = sind[city];
	while(ind>0){
		segtree[ind]+=val;
		nvals[ind]+=num;
		ind>>=1;
	}
}
long long int query(int ind, int nd){
	if(nd==0){return 0;}
	if(nvals[ind]<=nd){ return segtree[ind];}
	if(nvals[ind*2+1]>=nd){ return query(ind*2+1, nd);}
	else{
		return query(ind*2+1, nvals[ind*2+1])+query(ind*2, nd-nvals[ind*2+1]);
	}
}
void fl(int cl, int cr, int dl, int dr, int mlt, vector<long long int>&mxd){
	if(cl>cr) return;
	int m = (dl+dr)/2;
	long long int mn = -1;
	int bv=cl;
	for(int i=cr; i>=cl; i--){
		long long int tp=0;
		if(i*mlt<=m){
			tp = query(1, m-i*mlt);
			
		}
		if(tp>=mn){
			mn = tp;
			bv = i;
		}
		update(i, -cvals[i], -1);
	}
	mxd[m]=mn;
	if(mn<0){printf("wawawawawaaa");}
	if(dl==dr){
		return;
	}
	for(int i=cl; i<=cr; i++){
		update(i, cvals[i], 1);
	}
	fl(bv, cr, m+1, dr, mlt, mxd);
	if(dl==m){
		for(int i = cl; i<bv; i++) update(i, -cvals[i], -1);
		return;
	}
	update(bv, cvals[bv], 1);
	fl(cl, bv, dl, m-1, mlt, mxd);
	return;
}
long long int findMaxAttraction(int n, int start, int d, int attraction[]){
	for(int i=start; i<n; i++){
		srtd.push_back({attraction[i], i-start});
		cvals[i-start]=attraction[i];
	}
	sort(srtd.begin(), srtd.end());
	build(1, 0, srtd.size()-1);
	fl(0, srtd.size()-1, 0, d, 1, mxd1a);
	build(1, 0, srtd.size()-1);
	update(0, -cvals[0], -1);
	fl(1, srtd.size()-1, 0, d, 2, mxd2a);
	srtd.clear();
	memset(cvals,0,sizeof(cvals));
	for(int i=start; i>=0; i--){
		srtd.push_back({attraction[i], start-i});
		cvals[start-i]=attraction[i];
	}
	sort(srtd.begin(), srtd.end());
	build(1, 0, srtd.size()-1);
	fl(0, srtd.size()-1, 0, d, 1, mxd1b);
	build(1, 0, srtd.size()-1);
	update(0, -cvals[0], -1);
	fl(1, srtd.size()-1, 0, d, 2, mxd2b);
	long long int fmx = 0;
	for(int i=0; i<=d; i++){
		fmx = max(fmx, max(mxd1a[i]+mxd2b[d-i], mxd2a[i]+mxd1b[d-i]));
	}
	return fmx;

}