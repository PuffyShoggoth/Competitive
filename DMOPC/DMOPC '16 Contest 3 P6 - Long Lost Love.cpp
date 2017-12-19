#include <bits/stdc++.h>
#define lch(a) (a<<1)
#define rch(a) ((a<<1)+1)
#define md(a, b) ((a+b)>>1)
using namespace std;

vector<pair<pair<char, int>, pair<int, int> > > ord[500005];
vector<pair<pair<char, int>, pair<int, int> > > nxt[500005];
struct node{
	int ts, pfx, sfx;
};
int vl[100005], pos[100005];
node sgt[400005];
void fxn(int ind){
	sgt[ind].ts = sgt[rch(ind)].ts+sgt[lch(ind)].ts;
	sgt[ind].pfx = max(sgt[lch(ind)].ts+sgt[rch(ind)].pfx, sgt[lch(ind)].pfx);
	sgt[ind].sfx = max(sgt[rch(ind)].ts + sgt[lch(ind)].sfx, sgt[rch(ind)].sfx);
	return;
}
void build(int ind, int s, int e){
	if (s==e){sgt[ind].ts = vl[s]; sgt[ind].pfx = sgt[ind].sfx = vl[s]; pos[s] = ind; return; }
	build(rch(ind), md(s, e) + 1, e); build(lch(ind), s, md(s, e));
	fxn(ind);
	return;
}
void update(int ind, int val){
	sgt[ind].ts = val; sgt[ind].pfx = sgt[ind].sfx = val;
	ind = ind>>1;
	while(ind > 0){
		fxn(ind); ind = ind>>1;
	}
	return;
}
int qsum(int ind, int cs, int ce, int s, int e){
	if (cs>=s && ce <= e ) return sgt[ind].ts;
	else if (cs > e || ce < s ) return 0;
	else return qsum(lch(ind), cs, md(cs, ce), s, e)+qsum(rch(ind), md(cs, ce)+1, ce, s, e);
}
int qpfx(int ind, int cs, int ce, int s, int e){
	if (cs>=s && ce<=e) return sgt[ind].pfx;
	else if (e<=md(cs, ce)){ return qpfx(lch(ind), cs, md(cs, ce), s, e);}
	else if (s>md(cs, ce)){ return qpfx(rch(ind), md(cs, ce)+1, ce, s, e); }
	else return max(qpfx(lch(ind), cs, md(cs, ce), s, e),qsum(lch(ind), cs, md(cs, ce), s, e)+qpfx(rch(ind), md(cs, ce)+1, ce, s, e));
}
int qsfx(int ind, int cs, int ce, int s, int e){
	if (cs>=s && ce<=e) return sgt[ind].sfx;
	else if (e<=md(cs, ce)){ return qsfx(lch(ind), cs, md(cs, ce), s, e);}
	else if (s>md(cs, ce)){ return qsfx(rch(ind), md(cs, ce)+1, ce, s, e); }
	else return max(qsfx(rch(ind), md(cs, ce)+1, ce, s, e),qsum(rch(ind), md(cs, ce)+1, ce, s, e)+qsfx(lch(ind), cs, md(cs, ce), s, e));
}
int n;
int ans[500005];
void gans(int cn){
	for(auto i: ord[cn]){
		if (i.first.first == 'S'){ ans[i.first.second] = qsfx(1, 1, n, i.second.first, i.second.second); }
		else{ans[i.first.second] = qpfx(1, 1, n, i.second.first, i.second.second);}
	}
	for(auto i: nxt[cn]){
		if (i.first.first == 'G'){ gans(i.first.second); }
		else{
			int tmp = vl[i.second.first]; vl[i.second.first] = i.second.second;
			update(pos[i.second.first], i.second.second);
			gans(i.first.second);
			vl[i.second.first] = tmp;
			update(pos[i.second.first], tmp);
		}
	}
	return;
}
int main(){
	scanf("%i", &n);
	for(int i=1; i<=n; i++){
		scanf("%i", &vl[i]);
	}
	build(1, 1, n);
	int q; 
	scanf("%i", &q);
	int crv = 0, cqr=0;
	char tp; int x, y;
	for(int i=0; i<q; i++){
		getchar(); tp = getchar();
		if (tp == 'P' || tp == 'S'){ scanf("%i%i", &x, &y); ord[crv].push_back({{tp, cqr},{x, y}}); cqr++; }
		else if (tp == 'G'){ scanf("%i", &x); crv++; nxt[x].push_back({{tp, crv}, {x, x}}); }
		else{ scanf("%i%i", &x, &y); crv++; nxt[crv-1].push_back({{tp, crv}, {x, y}}); }
	}
	gans(0);
	for(int i=0; i<cqr; i++){
		printf("%i\n", ans[i]);
	}
}