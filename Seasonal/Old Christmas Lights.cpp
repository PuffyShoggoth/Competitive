#include <cstdio>
#include <set>
#include <vector>
#include <utility>
#define MXVL 2000000000
using namespace std;
int ai[100050];
vector<pair<int, int> > intvl;
multiset<int> minmax;
struct node{
	pair<int, int> lr, mlr;
	void asgn(pair<int, int> t, pair<int, int> u){
		lr=t; mlr=u;
	}
};
node sgtree[500010];
pair<int, int> build(int s, int e, int i){
	pair <int, int> tpa, tpb;
	if (s==e){
		sgtree[i].asgn(intvl[s], intvl[s]);
		return intvl[s];
	}
	tpa=build(s, (s+e)>>1, i<<1);
	tpb=build(((s+e)>>1)+1, e, (i<<1)+1);
	if ((tpb.second-tpb.first)>(tpa.second-tpa.first)){
		sgtree[i].asgn(make_pair(intvl[s].first, intvl[e].second), tpb);
	}
	else{ sgtree[i].asgn(make_pair(intvl[s].first, intvl[e].second), tpa);}
	return sgtree[i].mlr;
}
pair<int, int> qry(int sq, int eq, int i){
	if (sgtree[i].mlr.first>=sq && sgtree[i].mlr.second<=eq){
		return (sgtree[i].mlr);
	}
	else if (sgtree[i].lr.first>eq || sgtree[i].lr.second<sq){
		return make_pair(MXVL, MXVL);
	}
	int tpi, tpm;
	pair <int, int> tmx, tmp;
	if (sgtree[i].mlr.first>eq || sgtree[i].mlr.second<sq){tmx=make_pair(MXVL, MXVL);}
	else if (sgtree[i].mlr.first<=sq){
		if (sgtree[i].mlr.second>=eq){
			return make_pair(sq, eq);
		}
		else{tmx=make_pair(sq, sgtree[i].mlr.second);}
	}
	else{ tmx=make_pair(sgtree[i].mlr.first, eq);}
	tpm=tmx.second-tmx.first;
	tmp=qry(sq, eq, i<<1); tpi=tmp.second-tmp.first;
	if (tpi>tpm || ((tpi==tpm) && tmp.first<tmx.first)){
		tmx=tmp; tpm=tpi;
	}
	tmp=qry(sq, eq, (i<<1)+1); tpi=tmp.second-tmp.first;
	if (tpi>tpm || ((tpi==tpm) && tmp.first<tmx.first)){
		tmx=tmp; tpm=tpi;
	}
	return tmx;
}
int main() {
	int n, k, f=1, e=1, mn, mx, q;
	scanf("%i%i", &n, &k);
	for(int i=1; i<=n; i++){
		scanf("%i", &ai[i]);
	}
	ai[n+1]=ai[n]+k+1;
	minmax.insert(ai[1]);
	mn=ai[1]; mx=ai[1];
	while(e<=n){
		while((mx-mn)<=k){
			e++;
			minmax.insert(ai[e]);
			mn=(*(minmax.begin())); mx=(*(minmax.rbegin()));
		}
		intvl.push_back(make_pair(f, e-1));
		while((mx-mn)>k){
			minmax.erase(minmax.find(ai[f]));
			f++;
			mn=(*(minmax.begin())); mx=(*(minmax.rbegin()));
		}
	}
	build(0, intvl.size()-1, 1);
	pair<int, int> ans;
	scanf("%i", &q);
	for(int i=0; i<q; i++){
		scanf("%i%i", &mn, &mx);
		ans=qry(mn, mx, 1);
		printf("%i %i\n", ans.first, ans.second);
	}
	return 0;
}