#include <bits/stdc++.h>
#define lch(a) (a<<1)
#define rch(a) ((a<<1)+1)
using namespace std;
struct node{
	long long int ls, rs, mx, ts;
	node(){
		ls=0; rs=0; mx=0; ts=0;
	}
	void set(long long int tvl){
		long long int tm= tvl;
		ls=tm; rs=tm; mx=tm; ts=tvl;
	}
};
node sgtree[400005];
void updatenode(node * par, node * tl, node * tr){
	par->ls = max(tl->ls, tl->ts+tr->ls);
	par->rs = max(tr->rs, tr->ts+tl->rs);
	par->ts = tl->ts+tr->ts;
	par->ls = max(par->ls, par->ts);
	par->rs = max(par->rs, par->ts);
	par->mx = max(max(tl->mx, tr->mx),max(max(par->ls, par->rs), max(par->ts, tl->rs+tr->ls)));
}
long long int swrd[100005];
int tind[100005];
void build(int ind, int l, int r){
	if (l==r){
		tind[l]=ind;
		sgtree[ind].set(swrd[l]);}
	else{
		int mid = (l+r)>>1;
		build(lch(ind), l, mid);
		build(rch(ind), mid+1, r);
		updatenode(&sgtree[ind], &sgtree[lch(ind)], &sgtree[rch(ind)]);
	}
}
void update(int id){
	int cind = tind[id];
	sgtree[cind].set(swrd[id]);
	cind = cind>>1;
	while(cind>0){
		updatenode(&sgtree[cind], &sgtree[lch(cind)], &sgtree[rch(cind)]);
		cind = cind>>1;
	}
}
node * qry(int ind, int cl, int cr, int l, int r){
	if (l<= cl && r>=cr){ return &sgtree[ind]; }
	int mid = (cl+cr)>>1;
	node * curr = (node*)malloc(sizeof(node));
	if (l<=mid && r>mid){
		updatenode(curr, qry(lch(ind), cl, mid, l, r), qry(rch(ind), mid+1, cr, l, r));
		return curr;
	}
	else if (l<=mid){
		return qry(lch(ind), cl, mid, l, r);
	}
	else {
		return qry(rch(ind), mid+1, cr, l, r);
	}
}
int main(){
	int n, q;
	scanf("%i%i", &n, &q);
	for(int i=1; i<=n; i++){
		scanf("%lli", &swrd[i]);
	}
	build(1, 1, n);
	for(int i=0; i<q; i++){
		getchar();
		char tp=getchar();
		long long int a, b;
		scanf("%lli%lli", &a, &b);
		if (tp=='S'){
			swrd[a]=b;
			update(a);
		}
		else{
			printf("%lli\n", qry(1, 1, n, a, b)->mx);
		}
	}
	return 0;
}