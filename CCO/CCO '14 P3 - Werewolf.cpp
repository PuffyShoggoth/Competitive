#include <cstdio>
#include <vector>
#define MOD 1000000007
using namespace std;
long long int dp[205][205][2];
int w;
vector<int> ad[205][2];
bool hsch[205];
void prcs(int cn){
	dp[cn][0][0]=1; dp[cn][1][1]=1;
	if (ad[cn][0].size()+ad[cn][1].size()==0) return;
	long long int tmpa, tmpb;
	for(int j=0; j<2; j++){
		for(int i=0; i<ad[cn][j].size(); i++){
			prcs(ad[cn][j][i]);
			for(int k=w; k>=0; k--){
				tmpa=0; tmpb=0;
				for(int l=0; l<=k; l++){
					tmpa=(((dp[cn][k-l][0]*((dp[ad[cn][j][i]][l][0]+dp[ad[cn][j][i]][l][1])%MOD))%MOD)+tmpa)%MOD;
					tmpb=(((dp[cn][k-l+1][1]*(dp[ad[cn][j][i]][l][j]))%MOD)+tmpb)%MOD;
				}
				dp[cn][k][0]=tmpa;
				dp[cn][k+1][1]=tmpb;
			}
		}
	}
	return;
}

int main() {
	int n, m, a, b;
	char tp;
	scanf("%i%i%i", &n, &w, &m);
	for(int i=0; i<m; i++){
		do{tp=getchar();}while(tp<'A' || tp>'D');
		scanf("%i%i", &a, &b);
		hsch[b]=1;
		if (tp=='A'){
			ad[a][0].push_back(b);
		}
		else{
			ad[a][1].push_back(b);
		}
	}
	for(int i=1; i<=n; i++){
		if (!hsch[i]){
			ad[0][0].push_back(i);
		}
	}
	prcs(0);
	printf("%lli", dp[0][w][0]);
	return 0;
}