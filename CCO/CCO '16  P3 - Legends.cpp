#include <bits/stdc++.h>
using namespace std;
vector<int> edges[100005];
int vsted[100005];
int vsts[1005];
int chv[1005];
void mark(int cn, int par, int cyc, int nc){
	if (cn==cyc){ chv[cn]++; return; }
	if (vsts[cn]==nc){ return; }
	vsts[cn]=nc;
	for(int i: edges[cn]){
		if (i!=par){ 
			mark(i, cn, cyc, nc);
		}
	}
	return;
}
bool flask(int cn){
	int nc=1;
	for(int i:edges[cn]){
		chv[cn]=0;
		mark(i, cn, cn, nc);
		nc++;
		if (chv[cn]>1){return true; }
	}
	return false;
}
bool cc;
bool cycf(int cn, int pv, int lvl){
	bool hc=0, ic=0;
	vsted[cn]=lvl;
	for(int i:edges[cn]){
		if (i==pv) continue;
		if (vsted[i] == lvl-2 && lvl>2){
			if (hc){ cc=1; return 1; }
			ic=1;
		}
		else if (vsted[i]<lvl && vsted[i]){
			cc=1; return true;
		}
		else if (!vsted[i]){
			if (cycf(i, cn, lvl+1)){
				if (hc || ic){ cc=1; return true; }
				else{ hc=1; }
			}
		}
		if (cc) return true;
	}
	return ic;
}
bool cyct(int cn, int pv){
	if (vsted[cn]) return 1;
	vsted[cn]=1;
	for(int i: edges[cn]){
		if (i!=pv && cyct(i, cn)){ return 1; }
	}
	return 0;
}
bool nof(int cn, int par, int cyc, int nc, int depth){
	if (cn==cyc){
		if ((depth>4 && chv[cn]) || chv[cn]>4){
			cc=1;
			return 0;
		}
		else if (vsts[cn]>1) {
			cc=1;
			return 0;
		}
		else if (vsts[cn]) {
			vsts[cn]++;
			chv[cn]=depth;
			return 1;
		}
		else {
			vsts[cn]++;
			chv[cn]=depth;
			return 0;
		}
	}
	if (vsts[cn] == nc) { return 1; }
	vsts[cn] = nc;
	if (edges[cn].size()==1) { return 1;}
	bool branch=0;
	for(int i: edges[cn]) {
		if (i==par) {continue;}
		branch |= nof(i, cn, cyc, nc, depth+1);
		if (cc) { return 1; }
	}
	return branch;
}

bool hs(int cn){
    int nc = 1;
	for(int i: edges[cn]){
		chv[cn]=0;
		vsts[cn]=0;
		bool tp = nof(i, cn, cn, nc, 1);
		if (cc || (edges[cn].size()>vsts[cn]+1 && chv[cn] && tp)){
		return 1;
		}
		nc++;
	}
	return 0;
}
int main(){
	int s, t, n, m, a, b;
	scanf("%i%i", &s, &t);
	for(int i=0; i<t; i++){
		bool ans=0;
		scanf("%i%i", &n, &m);
		memset(chv, 0, sizeof(chv));
		memset(vsted, 0, sizeof(vsted));
		for(int j=1; j<=n; j++){ edges[j].clear(); }
		for(int j=0; j<m; j++){
			scanf("%i%i", &a, &b);
			edges[a].push_back(b);
			edges[b].push_back(a);
		}
		if (s==1){
			for(int j=1; j<=n; j++){
				memset(vsts, 0, sizeof(vsts));
				ans = flask(j);
				if (ans){ break; }
			}
			
		}
		else if (s==2){
			ans=cyct(1, 0);
		}
		else if (s==3){
			cc=0; 
			cycf(1, 0, 1);
			ans = cc;
		}
		else if (s==4){
			for(int j=1; j<=n; j++){
				if (edges[j].size()>2){ ans=1; break;}
			}
		}
		else{
			for(int j=1; j<=n; j++){
				if (edges[j].size()>1){
					memset(vsts, 0, sizeof(vsts));
					memset(chv, 0, sizeof(chv));
					cc=0;
					ans=hs(j);
				}
				if (ans) { break; }
			}
		}
		if (ans){printf("YES\n");}
		else {printf("NO\n");}
	}
	return 0;
}