#include <bits/stdc++.h>
using namespace std;
int fvn[100005][2];
pair<int, pair<int, int> >edvl[200005];
vector<pair<int, int> > edges[100005];
void dijkstra(int st, int vl){
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	pq.push({0, st});
	while(pq.size()){
		if(fvn[pq.top().second][vl]>=0){
			pq.pop();
			continue;
		}
		int cn = pq.top().second, ct=pq.top().first;
		fvn[cn][vl]=ct;
		pq.pop();
		for(pair<int, int> i: edges[cn]){
			if (fvn[i.first][vl]>=0) continue;
			pq.push({i.second+ct, i.first});
		}
	}
	return;
}

int main(){
	int n, m, x, y, a, b, c;
	scanf("%i%i%i%i", &n, &m, &x, &y);
	for(int i=1; i<=m; i++){
		scanf("%i%i%i", &a, &b, &c);
		edvl[i]={c,{a,b}};
		edges[a].push_back({b, c});
		edges[b].push_back({a, c});
	}
	memset(fvn, -1, sizeof(fvn));
	dijkstra(x, 0);
	dijkstra(y, 1);
	int q, f, l;
	scanf("%i", &q);
	for(int i=0; i<q; i++){
		scanf("%i%i", &f, &l);
		if (f==1){
			if(fvn[l][0]==fvn[l][1]){
				printf("%i\n", fvn[l][0]);
			}
			else{
				printf("%i\n", -1);
			}
		}
		else{
			int hf, hs, cf, cs;
			hf = edvl[l].second.first; hs = edvl[l].second.second;
			if(fvn[hf][1]==fvn[hf][0]){
				if(fvn[hs][1]==fvn[hs][0]){
					printf("%i\n", min(fvn[hf][1], fvn[hs][1]));
				}
				else{
					if(min(fvn[hs][1], fvn[hs][0])+edvl[l].first==fvn[hf][1]){
						printf("-1\n");
					}
					else{
						printf("%i\n", fvn[hf][1]);
					}
				}
			}
			else if (fvn[hs][1]==fvn[hs][0]){
				if(min(fvn[hf][1], fvn[hf][0])+edvl[l].first==fvn[hs][1]){
					printf("-1\n");
				}
				else{
					printf("%i\n", fvn[hs][1]);
				}
			}
			else if (fvn[hs][1]<fvn[hs][0]){
				if(fvn[hf][1]<fvn[hf][0]){
					printf("-1\n");
				}
				else{
					double dt = abs(fvn[hs][1]-fvn[hf][0]);
					dt = (edvl[l].first-dt)/2;
					printf("%f\n", max(fvn[hs][1], fvn[hf][0])+dt);
				}
			}
			else{
				if(fvn[hf][0]<fvn[hf][1]){
					printf("-1\n");
				}
				else{
					double dt = abs(fvn[hs][0]-fvn[hf][1]);
					dt = (edvl[l].first-dt)/2;
					printf("%f\n", max(fvn[hs][0], fvn[hf][1])+dt);
				}
			}
		}
	}
	return 0;
}