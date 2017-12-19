#include <cstdio>
#include <algorithm>
#define rch(dnr) ((dnr<<1)+1)
#define lch(dnr) (dnr<<1)
using namespace std;
struct node{
	int vl, l, r;
};
node sgtree[530000];
int lzy[530000];
int arr[200005];
int MOD;
void build(int s, int e, int i){
	sgtree[i].l=s; sgtree[i].r=e;
	if (s==e){
		sgtree[i].vl=(arr[s]%MOD);
		return;
	}
	build(s, (s+e)>>1, lch(i));
	build(((s+e)>>1)+1, e, rch(i));
	sgtree[i].vl=(sgtree[lch(i)].vl+sgtree[rch(i)].vl)%MOD;
	return;
}
void update(int l, int r, int x, int ind){
	sgtree[ind].vl=(sgtree[ind].vl+lzy[ind]*(sgtree[ind].r-sgtree[ind].l+1))%MOD;
	if (sgtree[ind].l==sgtree[ind].r) {
		lzy[ind]=0; 
		if (!(sgtree[ind].r<l || sgtree[ind].l>r)){sgtree[ind].vl=(sgtree[ind].vl+x)%MOD;}
		return;
	}
	lzy[lch(ind)]=(lzy[ind]+lzy[lch(ind)])%MOD; lzy[rch(ind)]=(lzy[ind]+lzy[rch(ind)])%MOD;
	lzy[ind]=0;
	if (l<=sgtree[ind].l && r>=sgtree[ind].r){
		lzy[lch(ind)]=(lzy[lch(ind)]+x)%MOD; lzy[rch(ind)]=(lzy[rch(ind)]+x)%MOD;
		sgtree[ind].vl=(sgtree[ind].vl+x*(sgtree[ind].r-sgtree[ind].l+1))%MOD;
		return;}
	else if (l>sgtree[ind].r || r<sgtree[ind].l){return;}
	else{
		update(l, r, x, lch(ind));
		update(l, r, x, rch(ind));
		sgtree[ind].vl=(sgtree[lch(ind)].vl+sgtree[rch(ind)].vl)%MOD;
	}
	return;
}
int sum(int l, int r, int ind){
	if (l<=sgtree[ind].l && r>=sgtree[ind].r){
		return (sgtree[ind].vl+(lzy[ind]*((sgtree[ind].r-sgtree[ind].l+1)%MOD))%MOD)%MOD;
	}
	else if (l>sgtree[ind].r || r<sgtree[ind].l){
		return 0;
	}
	else{
		sgtree[ind].vl=(sgtree[ind].vl+(lzy[ind]*((sgtree[ind].r-sgtree[ind].l+1)%MOD))%MOD)%MOD;
		lzy[lch(ind)]=(lzy[ind]+lzy[lch(ind)])%MOD; lzy[rch(ind)]=(lzy[ind]+lzy[rch(ind)])%MOD;
		lzy[ind]=0;
		return (sum(l, r, lch(ind))+sum(l, r, rch(ind)))%MOD;
	}
}
int main(){
	int n, q, id, l, r, x;
	scanf("%i%i%i", &MOD, &n, &q);
	for(int i=1; i<=n; i++){
		scanf("%i", &arr[i]);
	}
	build(1, n, 1);
	for(int i=0; i<q; i++){
		scanf("%i", &id);
		if (id==1){
			scanf("%i%i%i", &l, &r, &x);
			update(l, r, x%MOD, 1);
		}
		else{
			scanf("%i%i", &l, &r);
			printf("%i\n", sum(l, r, 1));
		}
	}
	return 0;
}