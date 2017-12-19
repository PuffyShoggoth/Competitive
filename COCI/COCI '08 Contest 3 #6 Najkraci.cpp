#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
vector<pair<int, int> > edges[1505];
int rdvl[5005];
int rdst[5005], rded[5005];
int visited[1505];
long long int nch[1505], nch2[1505];
vector<int> ch[1505], rch[1505];
long long int upval(int cn){
	if(nch[cn]){ return nch[cn]; }
	nch[cn] = 1; 
	for(int i: ch[cn]){
		long long int tp = upval(rded[i]);
		rdvl[i]=(rdvl[i]+nch2[cn]*tp)%MOD;
		nch[cn]=(nch[cn]+tp)%MOD;
	}
	return nch[cn];
}
long long int rdfs(int cn){
	if(nch2[cn]){ return nch2[cn]; }
	for(int i:rch[cn]){
		nch2[cn]=(nch2[cn]+rdfs(rdst[i]))%MOD;
	}
	return nch2[cn];
}
void dijkstra(int cn){
	priority_queue<pair<int, int> > pq;
	for(auto i: edges[cn]){ pq.push(i); }
	visited[cn]=1;
	while(!pq.empty()){
		auto tp = pq.top();
		pq.pop();
		if(!visited[rded[tp.second]]){
			visited[rded[tp.second]]=tp.first;
			rch[rded[tp.second]].push_back(tp.second);
			ch[rdst[tp.second]].push_back(tp.second);
			for(auto i: edges[rded[tp.second]]){
				if(!visited[rded[i.second]]){
					pq.push({i.first+tp.first, i.second});
				}
			}
		}
		else if(visited[rded[tp.second]]==tp.first){
			rch[rded[tp.second]].push_back(tp.second);
			ch[rdst[tp.second]].push_back(tp.second);
		}

	}
	return;
}
int main(){
	int n, m, o, d, l;
	scanf("%i%i", &n, &m);
	for(int i=1; i<=m; i++){
		scanf("%i%i%i", &o, &d, &l);
		edges[o].push_back({-l, i});
		rdst[i]=o; rded[i]=d;
	}
	for(int i=1; i<=n; i++){
		memset(visited, 0, sizeof(visited));
		memset(nch, 0, sizeof(nch));
		memset(nch2, 0, sizeof(nch2));
		for(int j=1; j<=n; j++){
			ch[j].clear(); rch[j].clear();
		}
		dijkstra(i);
		nch2[i]=1;
		for(int j=1; j<=n; j++){
			if(!nch2[j]){ rdfs(j); }
		}
		upval(i);
	}
	for(int i=1; i<=m; i++){
		printf("%i\n", rdvl[i]);
	}
}