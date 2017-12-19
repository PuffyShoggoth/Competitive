#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > edges[200005];
int bval[200005];
int main() {
	int n, m, a, b, p;
	scanf("%i%i", &n, &m);
	for(int i=0; i<m; i++){
		scanf("%i%i%i", &a, &b, &p);
		edges[a].push_back(make_pair(p, b));
		edges[b].push_back(make_pair(p, a));
	}
	memset(bval, -1, sizeof(bval));
	bval[1]=0;
	priority_queue<pair<int, int> > pq;
	for(int i=0; i<edges[1].size(); i++){
		pq.push(edges[1][i]);
	}
	while(!pq.empty()){
		pair<int, int> tp = pq.top(); pq.pop();
		if (bval[tp.second]!=-1){ continue; }
		bval[tp.second]=tp.first;
		for(auto it=edges[tp.second].begin(); it!=edges[tp.second].end(); ++it){
			if (bval[it->second]!=-1) { continue; }
			else{ pq.push(make_pair(min(it->first, tp.first), it->second)); }
		}
	}
	for(int i=1; i<=n; i++){
		printf("%i\n", bval[i]);
	}
	return 0;
}