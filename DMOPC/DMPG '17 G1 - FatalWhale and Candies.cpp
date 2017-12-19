#include <bits/stdc++.h>
using namespace std;
int dp[4097][2];
vector<int> vls;
bitset<4096> pv[4097];
int main(){
	int n, p, tp;
	memset(dp, -1, sizeof(dp));
	dp[0][1]=0;
	int curr=0, prv=1;
	scanf("%i%i", &n, &p);
	vls.push_back(0);
	for(int i=1; i<=n; i++){
		scanf("%i", &tp);
		int mval=tp%p;
		vls.push_back(mval);
		for(int j=p-1; j>=0; j--){
			if (dp[(j-mval+p)%p][prv]<0 || dp[j][prv]>dp[(j-mval+p)%p][prv]+tp){ 
				dp[j][curr]=dp[j][prv]; 
				continue; }
			else{
				dp[j][curr]=dp[(j-mval+p)%p][prv]+tp;
				pv[i][j] = 1;
			}
			
			//printf("%i %i\n", mval, dp[j][curr]);
		}
		prv=curr;
		curr= (curr+1)%2;
	}
	vector<int> ans;
	int cr = 0;
	for(int i=n; i>0; i--){
		if (pv[i][cr]){ ans.push_back(i); cr=(cr-vls[i]+p)%p; }
	}
	printf("%i\n%i\n", dp[0][prv], ans.size());
	for(int i=ans.size()-1; i>=0; i--){
		printf("%i ", ans[i]);
	}
	return 0;
}