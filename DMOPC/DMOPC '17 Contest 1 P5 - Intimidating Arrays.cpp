#include <bits/stdc++.h>
#define rch(n) ((n<<1)+1)
#define lch(n) (n<<1)
#define mid(r, l) ((r+l)>>1)
using namespace std;

vector<int> segtree[4000005];
int orig[1000005];
void build(int ind, int l, int r){
	if (l==r){
		segtree[ind].push_back(orig[l]);
		return;
	}
	build(lch(ind), l, mid(l,r));
	build(rch(ind), mid(l,r)+1, r);
	auto tpe = segtree[lch(ind)].end();
	for(auto it=segtree[lch(ind)].begin(); it!=tpe; ++it){
		segtree[ind].push_back(*it);
	}
	tpe = segtree[rch(ind)].end();
	for(auto it=upper_bound(segtree[rch(ind)].begin(), segtree[rch(ind)].end(), *segtree[lch(ind)].rbegin()); it!=tpe; ++it){
		segtree[ind].push_back(*it);
	}
}
pair<int, int> sm(int ind, int s, int e, int l, int r, int cmax){
	if(l<=s && r>=e){
		if (cmax>*segtree[ind].rbegin()){ return{cmax, 0}; }
		else{
			return {*segtree[ind].rbegin(), segtree[ind].size()-(upper_bound(segtree[ind].begin(), segtree[ind].end(), cmax)-segtree[ind].begin())};
		}
	}
	else if(l>mid(s, e)){
		return sm(rch(ind), mid(s,e)+1, e, l, r, cmax);
	}
	else if (r<=mid(s,e)){
		return sm(lch(ind), s, mid(s,e), l, r, cmax);
	}
	else{
		pair<int, int> tp = sm(lch(ind), s, mid(s,e), l, r, cmax);
		pair<int, int> tp2 = sm(rch(ind), mid(s,e)+1, e, l, r, tp.first);
		return {tp2.first, tp2.second+tp.second};
	}
}
int main(){
	int n, q;
	scanf("%i%i", &n, &q);
	for(int i=1; i<=n; i++){
		scanf("%i", &orig[i]);
	}
	build(1, 1, n);
	int l, r;
	for(int i=0; i<q; i++){
		scanf("%i%i", &l, &r);
		printf("%i\n", sm(1, 1, n, l, r, 0).second);
	}
	return 0;

}