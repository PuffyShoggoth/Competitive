#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > edges1[500005], edges2[500005];
int dst1[500005], dst2[500005];
void dijkstra(int st, int dst[500005], vector<pair<int, int> > edges[500005]){
	priority_queue<pair<int, int> > pq;
	pq.push({0, st});
	while(!pq.empty()){
		auto tp = pq.top(); pq.pop();
		if(dst[tp.second]>=0) continue;
		dst[tp.second] = -tp.first;
		for(auto i: edges[tp.second]){
			if(dst[i.second]>=0) continue;
			pq.push({i.first+tp.first, i.second});
		}
	}
	return;
}
int main(){
	int n, m;
	scanf("%i%i", &n, &m);
	int a, b, k;
	for(int i=0; i<m; i++){
		scanf("%i%i%i", &a, &b, &k);
		edges1[a].push_back({-k, b});
		edges2[b].push_back({-k, a});
	}
	memset(dst1, -1, sizeof(dst1));
	memset(dst2, -1, sizeof(dst2));
	dijkstra(1, dst1, edges1); dijkstra(n, dst2, edges2);
	int d;
	scanf("%i", &d);
	int res = dst1[n];
	for(int i=0; i<d; i++){
		scanf("%i%i%i", &a, &b, &k);
		if(dst1[a]<0 || dst2[b]<0){ continue; }
		if (res<0){res = dst1[a]+dst2[b]+k; }
		else{res = min(res, dst1[a]+dst2[b]+k);}
	}
	printf("%i", res);
}