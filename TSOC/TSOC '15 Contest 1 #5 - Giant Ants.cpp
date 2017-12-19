#include <cstdio>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
bool done[105];
bool ants[105];
vector<int> roads[105];
vector<int> nxt;
vector<int> tmp;
queue<pair<int, int> > bfs;

int main() {
	int n, m, x, y, w, t, ft=-1;
	scanf("%i%i", &n, &m);
	for(int i=0; i<m; i++){
		scanf("%i%i", &x, &y);
		roads[x].push_back(y);
		roads[y].push_back(x);
	}
	scanf("%i", &w);
	for(int i=0; i<w; i++){
		scanf("%i", &x);
		ants[x]=1;
		for(int i=0; i<roads[x].size(); i++){
			nxt.push_back(roads[x][i]);
		}
	}
	bfs.push(make_pair(0, 1));
	t=0;
	pair<int, int> tpp;
	while(!bfs.empty()){
		tpp=bfs.front(); bfs.pop();
		if (tpp.first>t){
			t++;
			if (t%4==0){
			for(int i=0; i<nxt.size(); i++){
				if (ants[nxt[i]]){continue;}
				ants[nxt[i]]=1;
				for(int j=0; j<roads[nxt[i]].size(); j++){
					tmp.push_back(roads[nxt[i]][j]);
				}
			}
			tmp.swap(nxt); tmp.clear();}
		}
		if (!ants[tpp.second] && tpp.second==n){
			ft=tpp.first; break;
		}
		else if (!ants[tpp.second] && !done[tpp.second]){
			done[tpp.second]=1;
			for(int i=0; i<roads[tpp.second].size(); i++){
				bfs.push(make_pair(t+1, roads[tpp.second][i]));
			}
		}
		
	}
	if (ft<0){printf("sacrifice bobhob314");}
	else {printf("%i", ft);}
	return 0;
}