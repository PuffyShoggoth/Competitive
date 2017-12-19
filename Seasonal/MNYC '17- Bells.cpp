#include <bits/stdc++.h>
#define lch(a) (a<<1)
#define rch(a) ((a<<1)+1)
#define mid(a, b) ((a+b)>>1)
using namespace std;

bitset<1000> sgtree[400005];
int fqs[100005], pos[100005];
vector<int> avb;
map<int, int> vl, cnt;
bitset<1000> build(int ind, int l, int r){
	if (r==l){
		pos[r] = ind;
		if (!cnt[fqs[r]]){
			vl[fqs[r]]=avb.back();
			avb.pop_back();
		}
		cnt[fqs[r]]++;
		sgtree[ind][vl[fqs[r]]] = 1;
		return sgtree[ind];
	}
	else{
		sgtree[ind] |= build(lch(ind), l, mid(l, r));
		sgtree[ind] |= build(rch(ind), mid(l,r)+1, r);
		return sgtree[ind];
	}
}
void update(int ind, int val) {
	sgtree[pos[ind]][vl[fqs[ind]]]=0;
	cnt[fqs[ind]]--;
	if (cnt[fqs[ind]]==0){
		avb.push_back(vl[fqs[ind]]);
		vl.erase(fqs[ind]);
	}
	cnt[val]++;
	if (cnt[val]==1){
		vl[val] = avb.back();
		avb.pop_back();
	}
	sgtree[pos[ind]][vl[val]]=1;
	for(int i = pos[ind]>>1; i>0; i=(i>>1)) {
		sgtree[i]=sgtree[lch(i)]|sgtree[rch(i)];
	}
	fqs[ind] = val;
}
bitset<1000> query(int ind, int l, int r, int cl, int cr){
	if (cl<=l && cr>=r){
		return sgtree[ind];
	}
	else if (cl>mid(l,r)){
		return query(rch(ind), mid(l,r)+1, r, cl, cr);
	}
	else if (cr<=mid(l,r)){
		return query(lch(ind), l, mid(l,r), cl, cr);
	}
	else{
		return query(lch(ind), l, mid(l,r), cl, cr)| query(rch(ind), mid(l,r)+1, r, cl, cr);
	}
}
int main(){
	int n, q;
	scanf("%i%i", &n, &q);
	for(int i=0; i<1000; i++){avb.push_back(i);}
	for(int i=1; i<=n; i++){
		scanf("%i", &fqs[i]);
	}
	build(1, 1, n);
	int cmd, l, r;
	for(int i=0; i<q; i++){
		scanf("%i%i%i", &cmd, &l, &r);
		if (cmd == 1) {
			update(l, r);
		}
		else{
			printf("%i\n", query(1, 1, n, l, r).count());
		}
	}
	return 0;
}