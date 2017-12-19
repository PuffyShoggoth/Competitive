#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
vector<int> edges[100005], weights[100005];
int lch[100005], wch[100005][2];
int mxdpth = 0, dpnode = 1;
void dfs(int cn, int par, int dpth){
	if (dpth >= mxdpth){ dpnode = cn; mxdpth = dpth;} //Holy @#$%, that was a stupid mistake. 
	for(int i:edges[cn]){
		if (i!=par){ dfs(i, cn, dpth+1); }
	}
}
int ovmax=0;
int dfs2(int cn, int par){
	wch[cn][0]=0; wch[cn][1] = 0;
	for(int i=0; i<edges[cn].size(); i++){
		if (edges[cn][i]==par){ continue; }
		int tp = dfs2(edges[cn][i], cn)+weights[cn][i];
		if (tp>=wch[cn][0]){
			lch[cn]=i;
			wch[cn][1] = wch[cn][0];
			wch[cn][0] = tp;
		}
		else if (tp>wch[cn][1]){
			wch[cn][1] = tp;
		}
	}
	ovmax = max(ovmax, wch[cn][0]+wch[cn][1]);
	return wch[cn][0];
}
void mrk(int cn){
	if (lch[cn]==-1){ return; }
	weights[cn][lch[cn]]=-1;
	mrk(edges[cn][lch[cn]]);
}
int main(){
	int n, k;
	scanf("%i%i", &n, &k);
	int a, b;
	memset(lch, -1, sizeof(lch));
	for(int i=0; i<n-1; i++){
		scanf("%i%i", &a, &b);
		edges[a].push_back(b);
		weights[a].push_back(1);
		edges[b].push_back(a);
		weights[b].push_back(1);
	}
	dfs(1, 0, 0);
	dfs2(dpnode, 0);
	if (k==1){printf("%i", (n-1)*2-ovmax+1);}
	else{
		int tp = ovmax;
		ovmax = 0;
		mrk(dpnode);
		dfs2(dpnode, 0);
		printf("%i", (n-1)*2-tp-ovmax+2);
	}
	return 0;
}