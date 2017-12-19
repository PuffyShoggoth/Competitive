#include <cstdio>
#define max(a,b) ((a<b)?b:a)
using namespace std;
int dp[105][105];
int main() {
	int n;
	scanf("%i", &n);
	for(int i=1; i<=n; i++){
		for(int j=1; j<=i; j++){
			scanf("%i", &dp[i][j]);
			dp[i][j]+=max(dp[i-1][j-1], dp[i-1][j]);
		}
	}
	int mx= dp[n][n];
	for(int j=1; j<=n; j++){
		mx= max(mx, dp[n][j]);
	}
	printf("%i", mx);
	return 0;
}