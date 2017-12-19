#include <cmath>
#include <vector>
#include <cstring>
#include <cstdio>
#include <utility>
using namespace std;
long long int dp[5005][5005];
int n;
vector<pair<int, int> > crds;
long long int vl(int cc, int nd){
	if (nd>=n-1) return 0;
	if (dp[cc][nd]>=0) return dp[cc][nd];
	dp[cc][nd]=crds[cc].first;
	int tpa=nd;
	nd+=crds[cc].second;
	if (tpa==cc) {
		dp[cc][tpa]+=vl(cc+1, nd);
	}
	else{
		dp[cc][tpa]=min(vl(cc+1, tpa), vl(cc+1, nd)+crds[cc].first);
	}
	return dp[cc][tpa];
}
int main() {
	int a, b;
	scanf("%i", &n);
	memset(dp, -1, sizeof(dp));
	for(int i=0; i<n; i++){
		scanf("%i%i", &a, &b);
		crds.push_back(make_pair(a,b));
	}
	printf("%lli", vl(0, 0));
	return 0;
}