#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
vector<pair<int, pair<int, int> > > edges[2050];
int mxv[2050];
int main() {
	int s, n, e;
	scanf("%i%i%i", &s, &n, &e);
	int sa, ta, da, u, a, b;
	
	for(int i=0; i<e; i++){
		scanf("%i%i%i%i", &sa, &ta, &da, &u);
		edges[sa].push_back(make_pair(-da, make_pair(ta, u)));
		edges[ta].push_back(make_pair(-da, make_pair(sa, u)));
	}
	scanf("%i%i", &a, &b);
	priority_queue<pair<int, pair<int, int> > >pq;
	memset(mxv, -1, sizeof(mxv));
	for(int i=0; i<edges[a].size(); i++){
		pq.push(edges[a][i]);
	}
	mxv[a]=0;
	int mnt=-1;
	while(!pq.empty()){
		pair<int, pair<int, int> > tp=pq.top(); pq.pop();
		int te=tp.second.first;
		if (tp.second.second>=s || (mxv[te]!=-1 && tp.second.second>=mxv[te])) continue; 
		if (te==b){
			mnt=-tp.first; 
			break;
		}
		mxv[te]=tp.second.second;
		for(int i=0; i<edges[te].size(); i++){
			pq.push(make_pair(tp.first+edges[te][i].first, make_pair(edges[te][i].second.first, edges[te][i].second.second+tp.second.second)));
		}
	}
	printf("%i", mnt);
}