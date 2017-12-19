#include <cstdio>
#include <vector>
using namespace std;
vector<int> th;
vector<int> te;
vector<int> tp;
int dp[2][1005];
int tm[2][1005];
int main() {
	int n, h, e, p, s, tph, tpt, tmx, tnt, tmn;
	scanf("%i", &n);
	for(int i=0; i<n; i++){
		scanf("%i%i%i", &h, &e, &p);
		th.push_back(h); te.push_back(e);
		tp.push_back(p);
	}
	scanf("%i", &s);
	int crr, prv=0;
	for(int i=0; i<n; i++){
		crr=(prv+1)%2;
		for(int j=0; j<=s; j++){
			tmx=0; tmn=0;
			tph=th[i]; tpt=0; tnt=0;
			for(int k=j; k>=0; k-=tp[i]){
				if(dp[prv][k]+tpt>tmx){
					tmx=dp[prv][k]+tpt;
					tmn=tnt+tm[prv][k];
				}
				else if (dp[prv][k]+tpt==tmx && tnt+tm[prv][k]<tmn){ tmn=tnt+tm[prv][k]; }
				if (tph<=0) break;
				tpt+=tph; tph-=te[i]; tnt++;
			}
			dp[crr][j]=tmx;
			tm[crr][j]=tmn;
		}
		prv=crr;
	}
	tmx=0; tmn=0;
	for(int i=0; i<=s; i++){
		if (dp[prv][i]>tmx) { tmx=dp[prv][i]; tpt=tm[prv][i]; }
		else if (dp[prv][i]==tmx && tm[prv][i]<tpt) { tpt=tm[prv][i]; }
	}
	printf("%i\n%i\n", tmx, tpt);
}