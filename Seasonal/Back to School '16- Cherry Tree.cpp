#include <cstdio>
#include <vector>
#include <utility>
using namespace std;
int tt=0, c, k;
vector<pair<int, int> > branches[100050];
bool done[100050];
int cherries[100050];
pair<int, int> cuts(int n){
	done[n]=1;
	int ch=cherries[n], w=0, tpc, tpw;
	pair<int, int> tpp;
	for(int i=0; i<branches[n].size(); i++){
		if (done[branches[n][i].first]){continue;}
		tpw=branches[n][i].second; tpc=0;
		tpp=cuts(branches[n][i].first);
		tpw+=tpp.second; tpc+=tpp.first;
		if (tpw<=k && tpc>=c){tt+=1;}
		ch+=tpc; w+=tpw;
	}
	return make_pair(ch, w);
}
int main() {
	int n, ci, ai, bi, ki;
	scanf("%i%i%i", &n, &c, &k);
	for(int i=1; i<=n; i++){
		scanf("%i", &cherries[i]);
	}
	for(int i=0; i<n-1; i++){
		scanf("%i%i%i", &ai, &bi, &ki);
		branches[ai].push_back(make_pair(bi, ki));
		branches[bi].push_back(make_pair(ai, ki));
	}
	cuts(1);
	printf("%i", tt);
	return 0;
}