#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int> > froads[100000];
vector<pair<int, int> > rroads[100000];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
int roads[100000][4];
int abest[100000];
int bbest[100000];
vector<pair<int, int> > costs;
int ord[100000];
vector<pair<int, int> > queries;
int main(){
	int n, m, a, b, x, y, l, c;
	pair<int, int> tp;
	scanf("%i%i%i%i", &n, &m, &a, &b);
	for(int i=0; i<m; i++){
		scanf("%i%i%i%i", &x, &y, &l, &c);
		froads[x].push_back(make_pair(l, y));
		rroads[y].push_back(make_pair(l, x));
		roads[i][0]=x; roads[i][1]=y; roads[i][2]=l; roads[i][3]=c;
	}
	for(int i=0; i<froads[a].size(); i++){
		pq.push(froads[a][i]);
	}
	while(pq.size()){
		tp=pq.top();
		pq.pop();
		if (abest[tp.second]==0 && tp.second!=a){
			abest[tp.second]=tp.first;
			for(int i=0; i<froads[tp.second].size(); i++){
				pq.push(make_pair(froads[tp.second][i].first+tp.first, froads[tp.second][i].second));
			}
		}
	}
	for(int i=0; i<rroads[b].size(); i++){
		pq.push(rroads[b][i]);
	}
	while(pq.size()){
		tp=pq.top();
		pq.pop();
		if (bbest[tp.second]==0 && tp.second!=b){
			bbest[tp.second]=tp.first;
			for(int i=0; i<rroads[tp.second].size(); i++){
				pq.push(make_pair(rroads[tp.second][i].first+tp.first, rroads[tp.second][i].second));
			}
		}
	}
	for(int i=0; i<m; i++){
		if ((abest[roads[i][0]]==0 && roads[i][0]!=a) || (bbest[roads[i][1]]==0 && roads[i][1]!=b) ) continue;
		costs.push_back(make_pair(abest[roads[i][0]]+bbest[roads[i][1]]+roads[i][2], roads[i][3]));
	}
	sort(costs.begin(), costs.end());
	for(int i=1; i<costs.size(); i++){
		costs[i].second+=costs[i-1].second;
	}
	int q;
	scanf("%i", &q);
	for(int i=0; i<q; i++){
		scanf("%i", &l);
		queries.push_back(make_pair(l, i));
	}
	sort(queries.begin(), queries.end());
	x=0;
	for(int i=0; i<queries.size(); i++){
		while(x<costs.size() && costs[x].first<=queries[i].first) x++;
		if (x==0) continue;
		ord[queries[i].second]=costs[x-1].second;
	}
	for(int i=0; i<q; i++){
		printf("%i\n", ord[i]);
	}
	return 0;
}