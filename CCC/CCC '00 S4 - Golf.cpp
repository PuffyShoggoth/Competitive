#include <cstdio>
#include <functional>
#include <cstring>
using namespace std;
int dp[5300];
int main() {
	int d, m, tp;
	scanf("%i%i", &d, &m);
	memset(dp, -1, 21200);
	dp[0]=0;
	for(int i=0; i<m; i++){
		scanf("%i", &tp);
		for(int k=tp; k<=d; k++){
			if (dp[k-tp]<0) continue;
			if (dp[k]<0){
				dp[k]=dp[k-tp]+1;
			}
			else{
				dp[k]=min(dp[k-tp]+1, dp[k]);
			}
		}
		
	}
	if (dp[d]<0) printf("Roberta acknowledges defeat.");
	else printf("Roberta wins in %i strokes.", dp[d]);
	return 0;
}