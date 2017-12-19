#include <vector>
#include <utility>
#include <cmath>
#include <deque>
#include <cstdio>
#include <cstring>
using namespace std;

vector<pair<int, int> > edges[1005];
vector<int> topsort;
int inc[1005];
int mxv[1005];
int nm[1005];
int main(){
	int n, m, a, b, d;
	scanf("%i%i", &n, &m);
	for(int i=0; i<m; i++){
		scanf("%i%i%i", &a, &b, &d);
		inc[b]++; edges[a].push_back({b, d});
	}
	deque<int> dq;
	for(int i=1; i<=n; i++){
		if (!inc[i]){
			dq.push_back(i);
		}
	}
	int tt=0;
	while(!dq.empty()){
		a=dq.front(); dq.pop_front(); tt++;
		topsort.push_back(a);
		for(pair<int, int> tp: edges[a]){
			inc[tp.first]--; 
			if (!inc[tp.first]){
				dq.push_back(tp.first);
			}
		}
	}
	if (tt!=n){
		printf("-1");
	}
	else{
		memset(mxv, -1, sizeof(mxv));
		mxv[1]=0;
		for(int tp: topsort){
			if (mxv[tp]<0){ continue; }
			for(pair<int, int> tpp: edges[tp]){
				if (tpp.second+mxv[tp] > mxv[tpp.first]){
					mxv[tpp.first]=tpp.second+mxv[tp];
					nm[tpp.first]=nm[tp]+1;
				}
				else if (tpp.second+mxv[tp]==mxv[tpp.first] && nm[tpp.first]<nm[tp]+1){
					nm[tpp.first]=nm[tp]+1;
				}
			}
		}
		if (mxv[n]<0){ printf("-1");}
		else{printf("%i %i", mxv[n], nm[n]+1);}
	}

	return 0;
}