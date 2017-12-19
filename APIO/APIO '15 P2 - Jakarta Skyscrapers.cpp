#include <bits/stdc++.h>
using namespace std;
set<int> doges[30005];
bool dn[30005];
deque<pair<int, pair<int, int> > > curr;
set<int> pvd[30005];
int main(){
	int n, m, st, ed;
	scanf("%i%i", &n, &m);
	int b, p, fn=-1;
	scanf("%i%i", &b, &p);
	st = b;
	doges[b].insert(p);
	scanf("%i%i", &b, &p);
	ed = b;
	for(int i=2; i<m; i++){
		scanf("%i%i", &b, &p);
		doges[b].insert(p);
	}
	if (st==ed){ fn = 0; }
	else{
	for(auto i=doges[st].begin(); i!=doges[st].end(); ++i){
		if (st+*i<n){
			curr.push_back({st+*i, {*i, 1}});
		}
		if (st-*i>=0){
			curr.push_back({st-*i, {-*i, 1}});
		}
	}
	while(!curr.empty()){
		pair<int, pair<int, int> > tp = curr.front();
		curr.pop_front();
		if (tp.first == ed){ fn = tp.second.second; break; }
		if (!dn[tp.first]){
			dn[tp.first]=1;
			for(auto i=doges[tp.first].begin(); i!=doges[tp.first].end(); ++i){
				if (tp.first+*i<n){
					curr.push_back({tp.first+*i, {*i, tp.second.second+1}});
				}
				if (tp.first-*i>=0){
					curr.push_back({tp.first-*i, {-*i, tp.second.second+1}});
				}
			}
		}
		if (tp.first+tp.second.first<n && tp.first+tp.second.first>=0 && (!doges[tp.first].count(abs(tp.second.first)))){
			curr.push_back({tp.first+tp.second.first, {tp.second.first, tp.second.second+1}});
		}
	}
	}
	printf("%i", fn);
	return 0;
}