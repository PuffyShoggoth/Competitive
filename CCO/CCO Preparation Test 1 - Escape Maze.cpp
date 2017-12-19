#include <bits/stdc++.h>
using namespace std;
vector<int> edges[405];
int low[405], num[405], numch[405];
int tte, dfsvl;
unsigned long long int ways;
int dfs(int cn, int par){
	dfsvl++;
	num[cn] = dfsvl; low[cn]=dfsvl;
	int dnch=0, tpb=0;
	int ndwex = 0;
	for(int i: edges[cn]){
		if (i==par) continue;
		if(num[i]){ low[cn] = min(low[cn], num[i]); }
		else{
			tpb = dfs(i, cn);
			low[cn] = min(low[cn], low[i]);
			if(low[i]>=num[cn]){
				dnch++;
				if(!tpb){
					tte++;
					ways *= numch[i];
				}
			}
			else{
				numch[cn]+=numch[i];
				ndwex+=tpb;
			}
		}
	}
	if(dnch){
		ndwex++;
	}
	else{
		numch[cn]++;
	}
	if(par==0 && dnch==1){
		if(tpb==1){
			tte++;
			ways *= (numch[edges[cn][0]]+1);
		}
		else if (tpb==0){
			tte++;
			ways = (ways*(numch[edges[cn][0]]+1))/2;
		}
	}
	return ndwex;
}
int main() {
	int n;
	while(1){
		scanf("%i", &n);
		if(n==0) break;
		for(int i=1; i<=400; i++){
			edges[i].clear();
		}
		int a, b;
		for(int i=0; i<n; i++){
			scanf("%i%i", &a, &b);
			edges[a].push_back(b);
			edges[b].push_back(a);
		}
		tte=0; ways=1; dfsvl=0;
		memset(low, 0, sizeof(low)); memset(num, 0, sizeof(num));
		memset(numch, 0, sizeof(numch));
		for(int i=1; i<=400; i++){
			if(num[i] || edges[i].size()==0){
				continue;
			}
			dfs(i, 0);
		}
		printf("%i %llu\n", tte, ways);
	}
	return 0;
}