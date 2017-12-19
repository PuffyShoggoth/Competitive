#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int dp[205][205];
int e[205];
int n;
int main() {
	scanf("%i", &n);
	while(n!=0){
	memset(dp, 0, 168100);
	memset(e, 0, 820);
	for(int i=0; i<n; i++){
		scanf("%i", &e[i]);
	}
	for(int i=1; i<(n-1); i++){
		dp[i][i]=e[i-1]+e[i]+e[i+1];
	}
	for(int i=1; i<(n-1); i++){
		for(int j=i+1; j<(n-1); j++){
			dp[j-i][j]=max(dp[j-i][j], dp[j-i+1][j]+e[j-i]+e[j-i-1]+e[j+1]);
			dp[j-i][j]=max(dp[j-i][j], dp[j-i][j-1]+e[j]+e[j-i-1]+e[j+1]);
			for(int k=(j-i+1); k<j; k++){
				dp[j-i][j]=max(dp[j-i][j], dp[j-i][k-1]+e[k]+e[j-i-1]+e[j+1]+dp[k+1][j]);
			}
		}
	}
	printf("%i\n", dp[1][n-2]);
	scanf("%i", &n);
	}
	return 0;
}