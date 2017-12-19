#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > edges[500005];
bool isk[500005];
int dtk[500005];
long long int lng[500005][2];
long long int ans[500005];
long long int ttw =0;
int dfsmrk(int cn, int par){
	for(auto tp: edges[cn]){
		if (tp.first==par){ continue; }
		long long int tpi = dfsmrk(tp.first, cn);
		if (tpi<0){ continue; }
		else{
			ttw += tp.second;
			isk[cn] = 1;
			if (tpi + tp.second >= lng[cn][0]){
				lng[cn][1] = lng[cn][0];
				lng[cn][0] = tpi + tp.second;
			}
			else if (tpi + tp.second > lng[cn][1]){
				lng[cn][1] = tpi+tp.second;
			}
		}
	}
	if (!isk[cn]){ return -1; }
	else{ return lng[cn][0]; }
}
void nkslv(int cn, int par, long long int td, long long int dtree){
	ans[cn] = ttw*2 + dtree - td;
	for(auto tp: edges[cn]){
		if (tp.first==par){ continue; }
		nkslv(tp.first, cn, td, tp.second+dtree);
	}
}
void slv(int cn, int par, long long int pvw){
	if(pvw >= lng[cn][0]){
		lng[cn][1] = lng[cn][0];
		lng[cn][0] = pvw;
	}
	else if (pvw > lng[cn][1]){
		lng[cn][1] = pvw;
	}
	ans[cn] = ttw*2 - lng[cn][0];
	for(auto tp: edges[cn]){
		if (tp.first == par){
			continue;
		}
		else if (!isk[tp.first]){nkslv(tp.first, cn, lng[cn][0], tp.second);}
		else{
			if (tp.second + lng[tp.first][0] == lng[cn][0]){
				slv(tp.first, cn, lng[cn][1]+tp.second);
			}
			else{
				slv(tp.first, cn, lng[cn][0]+tp.second);
			}
		}
	}
}
int main(){
	int n, k;
	scanf("%i%i", &n, &k);
	int a, b, c;
	int kval;
	for(int i=1; i<n; i++){
		scanf("%i%i%i", &a, &b, &c);
		edges[a].push_back({b, c});
		edges[b].push_back({a, c});
	}
	for(int i=0; i<k; i++){
		scanf("%i", &kval);
		isk[kval]=1;
	}
	dfsmrk(kval, 0);
	slv(kval, 0, 0);
	for(int i=1; i<=n; i++){
		printf("%lli\n", ans[i]);
	}
	return 0;
}