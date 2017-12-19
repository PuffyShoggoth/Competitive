#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int> > alled;
vector<int> edges[100005];
bool colour[100005];
void dfs(int cn, int par, bool cc){
	colour[cn]=cc;
	for(int i: edges[cn]){
		if (i!=par){
			dfs(i, cn, !cc);
		}
	}
	return;
}

int main(){
	int n, a, b;
	scanf("%i", &n);
	for(int i=1; i<n; i++){
		scanf("%i%i", &a, &b);
		alled.push_back({a,b});
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	dfs(1, 0, 0);
	for(pair<int, int> i: alled){
		printf("%i\n", colour[i.first]);
	}
	return 0;
}