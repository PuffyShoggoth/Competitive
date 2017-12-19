#include <cstdio>
#define min(a,b) ((a<b)?a:b)
using namespace std;

int pv[100005];
int atsq[100005];
int dfd[100005];
int dp[100005];
int ch[100005];

int main(){
	int n, m, tmp;
	scanf("%i%i", &n, &m);
	for(int i=0; i<n; i++){
		scanf("%i", &atsq[i]);
	}
	for(int i=1; i<=m; i++){
		scanf("%i", &dfd[i]);
	}
	for(int i=n-1; i>=0; i--){
		tmp=atsq[i];
		if (pv[tmp]==0 || (pv[tmp]>dfd[tmp]+i+1)){
			if (dfd[tmp]+i+1>=n){
				ch[i]=n-1-i;
			}
			else{
				ch[i]=dfd[tmp]+dp[i+dfd[tmp]+1];
			}
		}
		else{
			if (dfd[tmp]+i+1>=n){
				ch[i]=ch[pv[tmp]]+pv[tmp]-i-1;
			}
			else{
				ch[i]=min(ch[pv[tmp]]+pv[tmp]-i-1, dfd[tmp]+dp[i+dfd[tmp]+1]);
			}
		}
		dp[i] = min(dp[i+1]+1, ch[i]);
		pv[tmp]=i;
	}
	printf("%i", n-dp[0]);
	return 0;
}