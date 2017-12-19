#include <bits/stdc++.h>
#define OFFSET 1002
#define mp(a,b) make_pair(a,b)
using namespace std;
int pvc[2005];
struct car{
	int n, s, e, w, r, c;
	char dir;
	car(char _dir, int _n, int _s, int _w, int _e, int _r, int _c): dir(_dir), n(_n), s(_s), w(_w), e(_e), r(_r), c(_c){}
};
vector<car> crs;
vector<bool> dn;
void dfs(int cn){
	if (cn==0) return;
	
	if (crs[cn].dir=='N'){ while(crs[cn].n){dfs(crs[cn].n); }}
	else if (crs[cn].dir=='S'){ while(crs[cn].s){dfs(crs[cn].s);} }
	else if (crs[cn].dir=='E'){ while(crs[cn].e){dfs(crs[cn].e); }}
	else{ while(crs[cn].w){dfs(crs[cn].w); }}
	car tp = crs[cn];
	crs[tp.n].s=tp.s;
	crs[tp.s].n=tp.n;
	crs[tp.e].w=tp.w;
	crs[tp.w].e=tp.e;
	dn[cn]=1;
	printf("(%i,%i)\n", tp.r, tp.c);
	return;
	
}
int main() {
	int n, m, cc=1, pvr;
	scanf("%i%i", &n, &m);
	char tp;
	crs.push_back(car(0, 0, 0, 0, 0, 0, 0));
	dn.push_back(1);
	for(int i=0; i<n; i++){
		getchar();
		pvr=0;
		for(int j=0; j<m; j++){
			tp=getchar();
			if (tp=='.') continue;
			crs.push_back(car(tp, pvc[j], 0, pvr, 0, i, j));
			dn.push_back(0);
			crs[pvr].e=cc; crs[pvc[j]].s=cc; 
			pvr=cc; pvc[j]=cc;
			cc++;
		}
	}
	for(int i=0; i<cc; i++){
		if (dn[i]) continue;
		dfs(i);
	}
	return 0;
}