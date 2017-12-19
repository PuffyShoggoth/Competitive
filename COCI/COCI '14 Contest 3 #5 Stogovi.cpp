#include <cstdio>
#include <cmath>
using namespace std;
int lvl[300005];
int spt[300005][20];
int vl[300005];
int cpy[300005];
void update(int ind){
	int tp=cpy[spt[ind][0]], cp=1;
	while(cpy[spt[tp][cp-1]]){
		spt[ind][cp]=cpy[spt[tp][cp-1]];
		tp=spt[ind][cp];
		cp++;
	}
	return;
}
int lca(int a, int b){
	int k;
	while(a!=b){
		k=-1;
		for(int i=0; spt[a][i]!=spt[b][i]; i++){
			k=i;
		}
		if (k<0){ return spt[a][0]; }
		else{ a=spt[a][k]; b=spt[b][k]; }
		
	}
	return a;
}
int main() {
	int n, v, w, tv, tw, k; char tp;
	scanf("%i", &n);
	for(int i=1; i<=n; i++){
		getchar(); tp=getchar(); scanf("%i", &v);
		v=cpy[v];
		if (tp=='a'){
			spt[i][0]=v;
			lvl[i]=lvl[v]+1;
			vl[i]=i;
			cpy[i]=i;
			update(i);
		}
		else if (tp=='b'){
			cpy[i]=spt[v][0];
			printf("%i\n", vl[v]);
		}
		else{
			scanf("%i", &w);
			cpy[i]=v;
			tv=v; tw=cpy[w];
			while (lvl[tv]<lvl[tw]){
				k=log2(lvl[tw]-lvl[tv]);
				tw=spt[tw][k];
			}
			while(lvl[tw]<lvl[tv]){
				k=log2(lvl[tv]-lvl[tw]);
				tv=spt[tv][k];
			}
			printf("%i\n", lvl[lca(tv, tw)]);
		}
	}
	return 0;
}