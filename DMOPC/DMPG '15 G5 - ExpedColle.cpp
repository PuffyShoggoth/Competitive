#include <bits/stdc++.h>
using namespace std;
int n, r;
long long int dp[2005];//, c1[2005], v1[2005], ca[2005], cb[2005], cm[2005], va[2005], vb[2005], vm[2005];
vector<long long int> vls[2005];
int main(){
	scanf("%i%i", &n, &r);
	long long int e, c1, v1, ca, cb, cm, va, vb, vm;
	//memset(dp, -1, sizeof(dp));
	for(int i=0; i<n; i++){
		scanf("%lli%lli%lli%lli%lli%lli%lli%lli%lli", &e, &c1, &v1, &ca, &cb, &cm, &va, &vb, &vm);
		for(int j=0; j<e; j++){
			if (c1<=r && v1>0){
				vls[c1].push_back(v1);
			}
			c1 = (c1*ca + cb)% cm; v1 = (v1*va + vb)%vm;
		}
	}
	int mxvl=0;
	for(int i=0; i<=r; i++){
		sort(vls[i].begin(), vls[i].end());
		int sj = vls[i].size()-1;
		for(int j=0; j<=sj; j++){
			for(int k=min(mxvl+i, r); k>=i*(j+1); k--){
				dp[k] = max(dp[k], dp[k-i]+vls[i][sj-j]);
			}
			mxvl += i;
		}
	}
	long long int mvl=0;
	for(int i=0; i<=r; i++){mvl = max(mvl, dp[i]);}
	printf("%lli", mvl);
	return 0;
}