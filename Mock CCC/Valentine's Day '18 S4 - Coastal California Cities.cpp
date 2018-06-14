#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long int MOD = 1000000007;
long long int fact[200005];
vector<int> edges[200005];
long long int gans(int cn){
	long long int tt = (fact[edges[cn].size()+1])%MOD;
	for(int i: edges[cn]){
		tt = (tt*gans(i))%MOD;
	}
	return tt;
}
int main() {
	int n;
	scanf("%i", &n);
	int mx = 0;
	for(int i=1; i<n; i++){
		int tp;
		scanf("%i", &tp);
		edges[tp].push_back(i);
		tp =edges[tp].size();
		mx = max(mx, tp);
	}
	fact[0]=1;
	for(int i=1; i<=mx+1; i++){
		fact[i]=(fact[i-1]*i)%MOD;
	}
	printf("%lli\n", gans(0));
    return 0;
}