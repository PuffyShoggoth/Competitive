#include <bits/stdc++.h>
using namespace std;

vector<pair<int, unsigned long long int> > edges[100005];
bool visited2[100005];
int cycpar[100005], visited[100005];
unsigned long long int distpar[100005], dfpar[100005];
pair<int, unsigned long long int> res[100005];
pair<int, unsigned long long int> cycch[100005];
int dfsn = 1;
pair<int, unsigned long long int> dfs(int cn, int par, unsigned long long int cdist){
	if (visited[cn]){
		return {cn, 0};
	}
	visited[cn] = dfsn++;
	pair<int, unsigned long long int> tp;
	dfpar[cn] = cdist;
	for (auto i: edges[cn]){
		if (i.first == par || visited[i.first] > visited[cn]) continue;
		tp = dfs(i.first, cn, cdist+i.second);
		if (tp.first!=0 && tp.first!=cn){
			cycch[cn] = i;
			cycpar[cn] = tp.first;
			distpar[cn] = tp.second + i.second;
		}
	}
	if (cycpar[cn]){
		dfpar[cn] -= dfpar[cycpar[cn]];
	}
	return {cycpar[cn], distpar[cn]};

}
void dfs2(int cn, unsigned long long int bd){
	if (visited2[cn]) {return; }
	visited2[cn] = 1;
	if (cycch[cn].first == 0){
		res[cn] = {1, bd};
	}
	else{
		
		dfs2(cycch[cn].first, bd+cycch[cn].second);
		if (cycpar[cn] == 1 || res[cycpar[cn]].first == 2){
			res[cn] = {2, res[cycpar[cn]].second+distpar[cn]+dfpar[cn]};
		}
		else{
			res[cn] = {1, res[cycpar[cn]].second+min(distpar[cn], dfpar[cn])};
		}
		if (distpar[cn] < dfpar[cn]) {
			bd = bd-dfpar[cn]+distpar[cn];
		}
	}
	for(auto i: edges[cn]){
		if (visited2[i.first]) continue;
		dfs2(i.first, bd+i.second);
	}
	return;
}
int main(){
	int n, m;
	scanf("%i%i", &n, &m);
	int x, y, w;
	for(int i=0; i<m; i++){
		scanf("%i%i%i", &x, &y, &w);
		edges[x].push_back({y, w});
		edges[y].push_back({x, w});
	}
	dfs(1, 0, 0);
	dfs2(1, 0);
	for(int i = 2; i<=n; i++){
		printf("%i %llu\n", res[i].first, res[i].second);
	}
	return 0;
}