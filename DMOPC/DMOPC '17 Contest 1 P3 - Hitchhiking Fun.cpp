#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > edges[100005];

bool vstd[100005];
int main(){
	int n, m, a, b, t;
	scanf("%i%i", &n, &m);
	for(int i=0; i<m; i++){
		scanf("%i%i%i", &a, &b, &t);
		edges[a].push_back({-t, b});
		edges[b].push_back({-t, a});
	}
	bool dn = 0;
	priority_queue<pair<pair<int, int>, int> > pq;
	for(auto i: edges[1]){
		pq.push({{i.first, -1}, i.second});
	}
	while(!pq.empty()){
		auto tp = pq.top();
		pq.pop();
		if (tp.second==n){
			printf("%i %i", -tp.first.first, -tp.first.second);
			dn = 1; break;
		}
		if (vstd[tp.second]){ continue; }
		vstd[tp.second]=1;
		for(auto i: edges[tp.second]){
			if(vstd[i.second]){ continue; }
			pq.push({{tp.first.first+i.first, tp.first.second-1}, i.second});
		}
	}
	if (!dn){printf("-1");}
	return 0;
}