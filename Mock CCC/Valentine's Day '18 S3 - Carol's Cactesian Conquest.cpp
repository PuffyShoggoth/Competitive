#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long int MOD = 1000000007;
long long int dp[105][105][105];
long long int ct[105][105][105];
int k;
long long int gdp(int l, int g, int ck){
	if(dp[l][g][ck]>=0){
		return dp[l][g][ck];
	}
	if(l==0 && g==0){
		if(ck==k){dp[l][g][ck]=1; ct[l][g][ck]=1;}
		else{dp[l][g][ck]=0; ct[l][g][ck]=1;}
		return dp[l][g][ck];
	}
	dp[l][g][ck]=0; ct[l][g][ck]=0;
	if(ck==k){
		for(int i=1; i<=l; i++){
			gdp(l-i, g+i-1, 1);
			ct[l][g][ck]=(ct[l-i][g+i-1][1] + ct[l][g][ck])%MOD;
		}
		dp[l][g][ck]=ct[l][g][ck];
		return dp[l][g][ck];
	}
	for(int i=1; i<=l; i++){
		dp[l][g][ck]=(gdp(l-i, g+i-1, 1)+dp[l][g][ck])%MOD;
		ct[l][g][ck]=(ct[l-i][g+i-1][1]+ct[l][g][ck])%MOD;
	}
	for(int i=1; i<=g; i++){
		dp[l][g][ck]=(dp[l][g][ck]+gdp(l+i-1, g-i, ck+1))%MOD;
		ct[l][g][ck]=(ct[l+i-1][g-i][ck+1]+ct[l][g][ck])%MOD;
	}
	return dp[l][g][ck];
}
long long int fact[105];
long long int comb[105][105];
int main() {
	int n;
	scanf("%i%i", &n, &k);
	memset(dp, -1, sizeof(dp));
	memset(ct, -1, sizeof(ct));
	printf("%lli\n", gdp(0, n, 0));
    return 0;
}