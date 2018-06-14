#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
const int INF = 0x3f3f3f3f;
long long int fact[10005];
long long int finv[10005];
long long int inv[10005];
long long int dp[10005];

int main() {
	int n = 10000;
	dp[0]=1; dp[1]=1;
	fact[0]=1; fact[1]=1;
	finv[0]=1; finv[1]=1;
	inv[1]=1;
	for(int i=2; i<=n; i++){
		inv[i] = (MOD-((MOD/i)*inv[MOD%i])%MOD)%MOD;
		fact[i]=(fact[i-1]*i)%MOD;
		finv[i] = (finv[i-1]*inv[i])%MOD;
	}
	for(int i=2; i<=n; i++){
		for(int j=2; j<=i; j+=2){
			dp[i] = (dp[i]+(dp[j-1]*dp[i-j]%MOD)*((fact[i-1]*finv[j-1]%MOD)*finv[i-j]%MOD)%MOD)%MOD;
		}

	}
	for(int dnr=0; dnr<10; dnr++){
		int a;
		scanf("%i", &a);
		printf("%lli\n", dp[a]);
	}
    return 0;
}