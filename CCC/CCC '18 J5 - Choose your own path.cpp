#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
bool visited[10005];
vector<int> edges[10005];
int main() {
	int n;
	
	scanf("%i", &n);
	for(int i=1; i<=n; i++){
		int m;
		scanf("%i", &m);
		for(int j=0; j<m; j++){
			int tp;
			scanf("%i", &tp);
			edges[i].push_back(tp);
		}
	}
	int fn=n;
	queue<pair<int, int> > q;
	q.push({1,1});
	int tt = 0;
	while(!q.empty()){
		pair<int, int> tpp = q.front(); q.pop();
		if(visited[tpp.first]) continue;
		tt++;
		visited[tpp.first]=1;
		if(edges[tpp.first].size()==0){
			fn = min(fn, tpp.second);
		}
		for(int i: edges[tpp.first]){
			if(visited[i]) continue;
			q.push({i, tpp.second+1});
		}
	}
	if(tt==n){printf("Y\n%i", fn);}
	else{printf("N\n%i", fn);}
    return 0;
}