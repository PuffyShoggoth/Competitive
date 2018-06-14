#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
pair<int, int> dirs[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
vector<pair<pair<int, pair<int, int> >, pair<int, int> > > pv;
int dsj[500005];
int rnk[500005];
int sz[500005];
void Init(int N){
	for(int i=1; i<=N; i++){
		sz[i]=1;
	}
}
int grt(int cn){
	while(dsj[cn]){cn = dsj[cn]; }
	return cn;
}
void AddEdge(int U, int V){
	int a = grt(U), b = grt(V);
	if(a==b){
		pv.push_back({{a, {sz[a], rnk[a]}}, {b, dsj[b]}});
	}
	else if(rnk[a]>=rnk[b]){
		pv.push_back({{a, {sz[a], rnk[a]}}, {b, dsj[b]}});
		sz[a]+=sz[b]; dsj[b] = a;
		if(rnk[a]==rnk[b]){rnk[a]+=1;}
	}
	else{
		pv.push_back({{b, {sz[b], rnk[b]}}, {a, dsj[a]}});
		sz[b]+=sz[a]; dsj[a] = b;
	}
	return;
}
void RemoveLastEdge(){
	pair<pair<int, pair<int, int> >, pair<int, int> > tpp = pv.back(); pv.pop_back();
	sz[tpp.first.first] = tpp.first.second.first;
	rnk[tpp.first.first]= tpp.first.second.second;
	dsj[tpp.second.first]=tpp.second.second;
	return;
}
int GetSize(int U){
	return sz[grt(U)];
}