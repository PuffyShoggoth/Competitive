#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int n, m, npies[3005], mpies[105], dp[3005][105][105], dpm[105][105], pfx[105];

int msugar(int cpie, int skm, int tkm){
	if (skm> tkm){skm=m+1; tkm=m;}
	if (dp[cpie][skm][tkm]>0) return dp[cpie][skm][tkm];
	if (cpie==n){
		if (skm!=m+1){
			dp[cpie][skm][tkm]=dpm[skm+1][tkm];
		}
		dp[cpie][skm][tkm]+=npies[cpie];
		dp[cpie][skm][tkm]=max(dp[cpie][skm][tkm], dpm[skm][tkm]);
		return dp[cpie][skm][tkm];
	}
	if (cpie>n) return dpm[skm][tkm];
	dp[cpie][skm][tkm]=max(msugar(cpie+2, skm, tkm), msugar(cpie+3, skm, tkm));
	if (skm!=m+1) {
		dp[cpie][skm][tkm]=max(dp[cpie][skm][tkm], msugar(cpie+1, skm+1, tkm));
		if (cpie+1<=n) dp[cpie][skm][tkm]=max(dp[cpie][skm][tkm], msugar(cpie+3, skm, tkm-1)+mpies[tkm]);
	}
	dp[cpie][skm][tkm]+=npies[cpie];
	if (skm+1<=tkm){
		
		dp[cpie][skm][tkm]=max(dp[cpie][skm][tkm], msugar(cpie+1, skm, tkm-1)+mpies[tkm]);

	}
	return dp[cpie][skm][tkm];
}



int main(){
	int s;
	scanf("%i", &n);
	for(int i=1; i<=n; i++){
		scanf("%i", &npies[i]);
	}
	scanf("%i", &m);
	for(int i=0; i<m; i++){
		scanf("%i", &mpies[i]);
	}
	sort(mpies, mpies+m);
	s=m-1; pfx[0]=mpies[0];
	for(int i=1; i<m; i++){
		pfx[i]=pfx[i-1]+mpies[i];
	}
	for(int i=0; i<m; i++){
		for(int j=m-1; j>i; j--){
			dpm[i][j]=pfx[j]-pfx[i+((j-i+1)>>1)-1];
		}
		dpm[i][i]=mpies[i];
	}
		printf("%i\n", max(msugar(1, 0, m-1), max(msugar(2, 0, m-1), msugar(2, 0, m-2)+mpies[m-1])));

	return 0;
}