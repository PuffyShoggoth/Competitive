#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
vector<pair<int, int> > edges[55];
bool visited[55];
int fob, n;
bool dfs(int cn){
	if(visited[cn]) return 0;
	if(cn==n) return 1;
	visited[cn]=1;
	for(pair<int, int> tp:edges[cn]){
		if(tp.second==fob){continue;}
		if(dfs(tp.first)) return 1;
	}
	return 0;
}
int main() {
	int m;
	scanf("%i%i", &n, &m);
	int a, b;
	for(int i=0; i<m; i++){
		scanf("%i%i", &a, &b);
		edges[a].push_back({b, i});
	}
	for(int i=0; i<m; i++){
		fob=i;
		memset(visited, 0, sizeof(visited));
		if(dfs(1)){printf("YES\n");}
		else{printf("NO\n");}
	}
    return 0;
}