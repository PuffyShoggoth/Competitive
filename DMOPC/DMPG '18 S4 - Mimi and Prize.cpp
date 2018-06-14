#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
bool vl[200005];
vector<int> edges[200005];
int nc[200005];
long long int tt=0;
void dfs1(int cn, int par){
	nc[cn]=1;
	for(int i: edges[cn]){
		if(i==par){continue;}
		dfs1(i, cn);
		if(vl[i] != vl[cn]){
			nc[cn]+=nc[i];
		}
	}
	return;
}
void dfs2(int cn, int par, int ctt){
	if(vl[cn]==1){
		tt+=nc[cn]+ctt;
	}
	for(int i: edges[cn]){
		if(i==par){ continue; }
		if(vl[i]==vl[cn]){
			dfs2(i, cn, 0);
		}
		else{
			dfs2(i, cn, ctt+nc[cn]-nc[i]);
		}
		
	}
	return;

}
int main() {
	int n;
	scanf("%i", &n);
	for(int i=1; i<=n; i++){
		int tp; 
		scanf("%i", &tp);
		vl[i] = (tp%2==0)?0:1;
	}
	for(int i=0; i<n-1; i++){
		int a, b;
		scanf("%i%i", &a, &b);
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	dfs1(1, 0);
	dfs2(1, 0, 0);
	printf("%lli", tt);
    return 0;
}