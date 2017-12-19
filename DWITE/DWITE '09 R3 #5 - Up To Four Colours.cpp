#include <bits/stdc++.h>
using namespace std;
map<int, int> dn;
map<int, vector<int> > edges;
bool adj[25][25];
int colour[25];
int fs;
void mgraph(int cn, int par, int pv){
	int id = fs; fs++;
	dn[cn]=id;
	if (par>=0){
		adj[par][id]=1; adj[id][par]=1;
	}
	for(int i: edges[cn]){
		if (i==pv){ continue; }
		if(dn[i]>=0){ adj[id][dn[i]]=1; adj[dn[i]][id]=1; continue;}
		mgraph(i, id, cn);
	}
}
bool bip(int cn, int par, int mask, int clr){
	colour[cn] = clr + 1;
	for(int i=0; i<fs; i++){
		if(i==par || ((1<<i)&mask)==0 || !adj[cn][i]) continue;
		if (colour[i] == clr+1) return 0;
		else if (colour[i]) continue;
		if(!bip(i, cn, mask, (clr+1)%2)) return 0;
	}
	return 1;
}
bool tcl(int mask){
	for(int i=0; i<fs; i++){
		if ((1<<i)&mask && !colour[i]){
			if(!bip(i, 0, mask, 0)){
				return 0;
			}
		}
	}
	return 1;
}
bool spt(int mask){
	for(int i=0; i<fs; i++){
		if(!((1<<i)&mask)){ continue;}
		for(int j=i+1; j<fs; j++){
			if(!((1<<j)&mask)) continue;
			if(adj[i][j]){ return 0;}
		}
	}
	return 1;
}
int nc(){
	memset(colour, 0, sizeof(colour));
	if (bip(0, -1, (1<<fs)-1, 0)) { return 2; }
	int mn = 5;
	for(int i=1; i<(1<<fs); i++){
		memset(colour, 0, sizeof(colour));
		if(spt(i)){
			if(tcl((~i)&((1<<fs)-1))){ return 3; }
		}
		else if(mn==5){
			if(tcl((~i)&((1<<fs)-1)) && tcl(i)){ mn = 4; }
		}
	}
	return mn;
}
int main(){
	int n, a, b;
	for(int dnr=0; dnr<5; dnr++){
		scanf("%i", &n);
		edges.clear(); dn.clear();
		for(int i=0; i<n; i++){
			scanf("%i%i", &a, &b);
			edges[a].push_back(b);
			edges[b].push_back(a);
			dn[a]=-1; dn[b]=-1;
		}
		int mcolour = 0;
		for(auto it=dn.begin(); it!=dn.end(); ++it){
			if (it->second>=0) {continue; }
			memset(adj, 0, sizeof(adj));
			fs = 0;
			mgraph(it->first, -1, -1);
			if (fs==1){ mcolour = max(mcolour, 1); }
			else{
				mcolour = max(mcolour, nc());
			}
			if (mcolour == 5){ break; }
		}
		if (mcolour==5) printf("0\n");
		else printf("%i\n", mcolour);
	}
	return 0;
}