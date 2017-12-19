#include <bits/stdc++.h>
using namespace std;
long long int dp[5005], mqv[5005];

int main(){
	int n, h, g, hi, q, t;
	scanf("%i%i", &n, &h);
	for(int i=0; i<n; i++){
		scanf("%i%i%i%i", &g, &hi, &q, &t);
		for(int j=0; j<=h; j++){
			if(j<hi){mqv[j]=0; }
			else if (j<hi+t){ mqv[j] = dp[j-hi]+g; }
			else{
				mqv[j] = max(dp[j-hi]+g, mqv[j-t]+q);
			}
		}
		for(int j=0; j<=h; j++){
			dp[j]=max(dp[j], mqv[j]);
		}
	}
	printf("%lli", dp[h]);
	return 0;
}