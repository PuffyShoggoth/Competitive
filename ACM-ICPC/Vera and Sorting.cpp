#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
const int INF = 0x3f3f3f3f;
long long int dp[35][905];
long long int nck[35][35];
int main() {
	int n, k;
	scanf("%i%i", &n, &k);
	nck[0][0]=1;
	for(int i=1; i<=n; i++){
		nck[i][0]=1; nck[i][i]=1;
		for(int j=1; j<=i-j; j++){
			nck[i][j]=(nck[i][j-1]*(i-j+1)/j)%MOD;
			nck[i][i-j]=nck[i][j];
		}
	}
	dp[0][0]=1;
	for(int i=1; i<=n; i++){
		for(int j=0; j<i; j++){
			for(int l=0; l<=k-i; l++){
				for(int q=j; q<=l; q++){
					dp[i][l+i]=(dp[i][l+i]+(dp[j][q]*nck[i-1][j]%MOD)*dp[i-1-j][l-q])%MOD;
					
				}
			}
		}
	}
	printf("%lli", dp[n][k]);
    return 0;
}