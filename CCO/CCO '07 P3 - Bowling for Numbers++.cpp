#include <bits/stdc++.h>
using namespace std;
int dp[10005][505][2];
int w, np;
int vl[10505], bv[10505];
int mball(int p, int n, bool pv){
	if (n<1 || p>np){ /*cout<<"bleh\n";*/ return 0; }
	else if (dp[p][n][pv]>-1) { return dp[p][n][pv]; }
	int tmp=0, cv=0;
	tmp=mball(p+1, n, 1);
	if (!pv){
		tmp=max(tmp, mball(p, n-1, 0));
		for(int i=p; i<p+w; i++){
			cv+=vl[i];
			tmp=max(tmp, mball(i+1, n-1, 0)+cv);
		}
	}
	cv=bv[p];
	tmp=max(tmp, mball(p+w, n-1, 0)+cv);
	dp[p][n][pv]=tmp;
//	cout<<tmp<<" "<<p<<" "<<n<<" "<<pv<<"\n";
	return tmp;
}

int main() {
	int t, k;
	scanf("%i", &t);
	while(t--){
		memset(vl, 0, sizeof(vl));
		memset(dp, -1, sizeof(dp));
		scanf("%i%i%i", &np, &k, &w);
		for(int i=0; i<np; i++){
			scanf("%i", &vl[i]);
		}
		int pv=0;
		for(int i=np-1; i>=0; i--){
			pv+=vl[i]-vl[i+w];
			bv[i]=pv;
		}
		printf("%i\n", mball(0, k, 0));
	}
	return 0;
}