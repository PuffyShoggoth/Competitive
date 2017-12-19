#include <bits/stdc++.h>
using namespace std;

int adj[105][105];
int n;
int evl[105];
int pv[105];
bool vst[105];
vector<int> fedge[105], redge[105];
deque<pair<int, pair<int, int> > > dq;
int path(){
	if (evl[1]==0){ return 0; }
	dq.clear();
	pv[1]=0;
	memset(vst, 0, sizeof(vst));
	vst[1]=1;
	for(int i: fedge[1]){
		dq.push_back({i, {1, evl[1]}});
	}
	int mn=0;
	while(dq.size()){
		pair<int, pair<int, int> > tp = dq.front(); 
		dq.pop_front();
		if (vst[tp.first]){continue; }
		vst[tp.first] = 1;
		pv[tp.first]=tp.second.first;
		if (tp.first==n){
			mn = tp.second.second; break;
		}
		if (evl[tp.first]){
			for(int i: fedge[tp.first]){
				dq.push_back({i, {tp.first, min(tp.second.second, evl[tp.first])}});
			}
		}
		for(int i:redge[tp.first]){
			if (adj[tp.first][i]){
				dq.push_back({i, {tp.first, min(tp.second.second, adj[tp.first][i])}});
			}
		}
	}
	if (mn==0){ return 0; }
	int tp = n;
	while(pv[tp]){
		if (evl[pv[tp]]){
			evl[pv[tp]]-=mn;
			adj[tp][pv[tp]]+=mn;
		}
		else{
			adj[tp][pv[tp]]-=mn;
		}
		tp=pv[tp];
	}
	return mn;

}
int main(){
	int m;
	scanf("%i", &n);
	for(int i=1; i<n; i++){
		scanf("%i", &evl[i]);
	}
	scanf("%i", &m);
	for(int i=0; i<m; i++){
		int a, b;
		scanf("%i%i", &a, &b);
		fedge[a].push_back(b);
		redge[b].push_back(a);
	}
	int sm=0, tp;
	while(1){
		tp = path();
		if (tp==0){ break; }
		sm+=tp;
	}
	printf("%i", sm);
	return 0;
}