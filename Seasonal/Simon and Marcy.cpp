#include <cstdio>
#include <algorithm>
using namespace std;

int dp[1009];
int mx=0;

int main(){
	int c, m, n, k;
	scanf("%i%i", &c, &m);
	for(int i=0; i<c; i++){
		scanf("%i%i", &n, &k);
		for(int p=m; p>=k; p--){
			dp[p]=max(dp[p], (dp[p-k]+n));
		}
	}
	for(int i=0; i<=m; i++){
		mx=max(mx, dp[i]);
	}
	printf("%i", mx);
	return 0;
}