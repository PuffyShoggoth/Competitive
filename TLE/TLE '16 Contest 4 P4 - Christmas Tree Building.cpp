#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector<pair<int, int> > edges[100005];
long long int vl[100005];
long long int sb[100005];
int cid[100005];
bool dn[100005];
void dfs1(int cn, int pv){
	dn[cn]=1; int tpn; long long int tpv;
	for(int i=0; i<edges[cn].size(); i++){
		if (edges[cn][i].first==pv) continue;
		tpn=edges[cn][i].first; 
		dfs1(edges[cn][i].first, cn);
		tpv=vl[edges[cn][i].first]+edges[cn][i].second;
		if (vl[cn]<=tpv) { cid[cn]=tpn; sb[cn]=vl[cn]; vl[cn]=tpv; }
		else if (sb[cn]<tpv){ sb[cn]=tpv; }
	}
	return;
}
long long int dfsmx(int cn, int pv, long long int ttl){
	dn[cn]=1; long long int tmx=max(ttl, vl[cn]), tpv; int tpn;
	for(int i=0; i<edges[cn].size(); i++){
		tpn=edges[cn][i].first; 
		if (tpn==pv) continue;
		tpv=edges[cn][i].second;
		if (ttl>=vl[cn]) {tmx=max(tmx, dfsmx(tpn, cn, tpv+ttl));}
		else if (cid[cn]==tpn){ tmx=max(tmx, dfsmx(tpn, cn, max(ttl, sb[cn])+tpv)); }
		else { tmx=max(tmx, dfsmx(tpn, cn, vl[cn]+tpv)); }
	}
	return tmx;
}
long long int dfsmn(int cn, int pv, long long int ttl){
	dn[cn]=1; long long int tmn=max(ttl, vl[cn]), tpv; int tpn;
	for(int i=0; i<edges[cn].size(); i++){
		tpn=edges[cn][i].first; 
		if (tpn==pv) continue;
		tpv=edges[cn][i].second;
		if (ttl>=vl[cn]) {tmn=min(tmn, dfsmn(tpn, cn, tpv+ttl));}
		else if (cid[cn]==tpn){ tmn=min(tmn, dfsmn(tpn, cn, max(ttl, sb[cn])+tpv)); }
		else { tmn=min(tmn, dfsmn(tpn, cn, vl[cn]+tpv)); }
	}
	return tmn;
}

int main() {
	int n, m, q, u, v, l; long long int tp, tpa=-1, tpb=-1;
	scanf("%i%i%i", &n, &m, &q);
	for(int i=0; i<m; i++){
		scanf("%i%i%i", &u, &v, &l);
		edges[u].push_back(make_pair(v, l));
		edges[v].push_back(make_pair(u, l));
	}
	for(int i=1; i<=n; i++){
		if (dn[i]) continue;
		dfs1(i, 0);
		if (q==1){
			tp=dfsmx(i, 0, 0);
			if (tpa==-1){ tpa=tp; }
			else { tpa+=tp+1; }
		}
		else{
			tp=dfsmn(i, 0, 0);
			if (tpa==-1){ tpa=tp; }
			else if (tp==tpa) {tpb=tp; }
			else if (tp > tpa) { tpb=tpa; tpa=tp; }
			else { tpb=max(tpb, tp); }
		}
	}
	if (q==1){
		printf("%lli", tpa);
	}
	else {
		if (tpa==tpb){ printf("%lli", tpa+1); }
		else { printf("%lli", tpa);}
	}
	return 0;
}