#include <vector>
#include <cstdio>
#include <cmath>
using namespace std;
vector<int> ch[100005];
int fvt[100005];
int lvt[100005];
int lvl[100005];
int spt[17][100005];
int dfs(int cn, int pve, int clv){
	fvt[cn]=pve; lvl[cn]=clv;
	for(int i=0; i<ch[cn].size(); i++){
		pve = dfs(ch[cn][i], pve+1, clv+1);
	}
	lvt[cn]=pve;
	return pve+1;
}
int aat(int cn, int k){
	int tlg;
	while(k>0){
		tlg=log2(k);
		cn=spt[tlg][cn];
		k-=1<<tlg;
	}
	return cn;
}
int lca(int u, int v){
	int i;
    while (u!=v){
        i=0;
	    while(spt[i][u]!=spt[i][v]){
		    i++;
	    }
	    if (i==0) return spt[i][u];
	    u=spt[i-1][u]; v=spt[i-1][v];
		
	}
	return u;
}
int main() {
	int n, c, ci, tmp, q, u, v, la;
	scanf("%i", &n); 
	for(int i=1; i<=n; i++){
		scanf("%i", &c);
		for(int j=0; j<c; j++){
			scanf("%i", &ci);
			ch[i].push_back(ci);
			spt[0][ci]=i;
		}
	}
	for(int i=1; i<=log2(n); i++){
		for(int j=1; j<=n; j++){
			spt[i][j]=spt[i-1][spt[i-1][j]];
		}
	}
	dfs(1, 0, 0);
	scanf("%i", &q);
	for(int i=0; i<q; i++){
		scanf("%i%i", &u, &v);
		if (lvl[u]>lvl[v]){
			la=lca(aat(u, lvl[u]-lvl[v]), v);
		}
		else{
			la=lca(u, aat(v, lvl[v]-lvl[u]));
		}
		if (fvt[u]<=fvt[v]){
		    
			printf("%i\n",  fvt[v]-fvt[la]-lvl[u]+lvl[la]);
		}
		else{
			tmp = aat(u, lvl[u]-lvl[la]-1);
			printf("%i\n", fvt[v]-fvt[la]-lvl[u]+lvl[tmp]+1+lvt[tmp]-fvt[tmp]);
		}
	}
	return 0;
}