#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int dst[20][20];
int dp[17][131100];
int n;
int mxpth(int c, int vst){
	if (dp[c][vst]!=-1){return dp[c][vst];}
	int cmx=dst[c][n-1];
	if (cmx<0){cmx-=1;}
	int tvst=(vst|(1<<c)), tp;
	for(int i=1; i<n-1; i++){
		if((!(tvst&(1<<i))) && dst[c][i]>=0){
			tp=mxpth(i, tvst);
			if (tp>=0){cmx=max(cmx, tp+dst[c][i]);}
		}
	}
	dp[c][vst]=cmx;
	return cmx;
}
	
int main(){
	memset(dst, -1, 1600);
	memset(dp, -1, 8914800);
	int m, s, d, l;
	scanf("%i%i", &n, &m);
	for(int i=0; i<m; i++){
		scanf("%i%i%i", &s, &d, &l);
		dst[s][d]=l;
	}
	printf("%i", mxpth(0, 0));
	return 0;
}