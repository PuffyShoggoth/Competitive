#include <bits/stdc++.h>
using namespace std;
vector<int> edges[100005];
int spt[100005][17], dpth[100005];
int dfs_num[100005], dfs_low[100005], brvals[100005], rng[100005];
bool artval[100005];
int dfsvl = 0;
void tarjan(int cn, int par, int tdpth){
	dfsvl++; 
	dfs_num[cn] = dfs_low[cn] = dfsvl;
	spt[cn][0] = par;
	dpth[cn]=tdpth;
	for(int i:edges[cn]){
		if(i==par) {continue; }
		else if (dfs_num[i]){
			dfs_low[cn] = min(dfs_low[cn], dfs_num[i]);
		}
		else{
			int tp = dfsvl;
			tarjan(i, cn, tdpth+1);
			dfs_low[cn] = min(dfs_low[cn], dfs_low[i]);
			if(dfs_low[i]>=dfs_num[cn]){
				artval[i]=1;
			}
			if(dfs_low[i]>dfs_num[cn]){
				brvals[i]=dfsvl;
			}
		}
	}
	rng[cn]=dfsvl;
	return;
}
int alvl(int a, int dff){
	while(dff>0){
		int tplg = floor(log2(dff));
		dff-=(1<<tplg);
		a = spt[a][tplg];
	}
	return a;
}
int main(){
	int n, e;
	scanf("%i%i", &n, &e);
	int a, b;
	for(int i=0; i<e; i++){
		scanf("%i%i", &a, &b);
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	tarjan(1, 0, 0);
	int lg2 = log2(n);
	for(int i=1; i<=lg2; i++){
		for(int j=1; j<=n; j++){
			spt[j][i] = spt[spt[j][i-1]][i-1];
		}
	}
	int q, id, c, g1, g2;
	scanf("%i", &q);
	for(int i=0; i<q; i++){
		scanf("%i", &id);
		if(id==1){
			scanf("%i%i%i%i", &a, &b, &g1, &g2);
			if(dfs_num[g2]<dfs_num[g1]){
				c = g2; g2 = g1; g1 = c; 
			}
			if(dfs_low[g2]<=dfs_num[g1]){
				printf("yes\n");
			}
			else{
				if((dfs_num[g2]<=dfs_num[a] && brvals[g2]>=dfs_num[a])^(dfs_num[g2]<=dfs_num[b] && brvals[g2]>=dfs_num[b])){
					printf("no\n");
				}
				else{
					printf("yes\n");
				}
			}
		}
		else{
			scanf("%i%i%i", &a, &b, &c);
			bool avl = (dfs_num[c]<=dfs_num[a] && rng[c]>=dfs_num[a]);
			bool bvl = (dfs_num[c]<=dfs_num[b] && rng[c]>=dfs_num[b]);
			if(avl){
				g1 = alvl(a, dpth[a]-dpth[c]-1);
				if (bvl){
					g2 = alvl(b, dpth[b]-dpth[c]-1);
					if(g1==g2){
						printf("yes\n");
					}
					else if(artval[g1]||artval[g2]){
						printf("no\n");
					}
					else{
						printf("yes\n");
					}
				}
				else if(artval[g1]){
					printf("no\n");
				}
				else{
					printf("yes\n");
				}
			}
			else if (bvl){
				g1 = alvl(b, dpth[b]-dpth[c]-1);
				if(artval[g1]){
					printf("no\n");
				}
				else{
					printf("yes\n");
				}
			}
			else{
				printf("yes\n");
			}
		}
	}
	return 0;
}