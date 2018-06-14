#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int sptmn[20][50005], sptmx[20][50005];

int main() {
	int n, q;
	scanf("%i%i", &n, &q);
	for(int i=1; i<=n; i++){
		scanf("%i", &sptmn[0][i]);
		sptmx[0][i]=sptmn[0][i];
	}
	for(int i = 1; (1<<i)<n; i++){
		for(int j = 1; j+(1<<i)-1<=n; j++){
			sptmx[i][j] = max(sptmx[i-1][j], sptmx[i-1][j+(1<<(i-1))]);
			sptmn[i][j] = min(sptmn[i-1][j], sptmn[i-1][j+(1<<(i-1))]);
		}
	}
	for(int i = 0; i<q; i++){
		int l, r;
		scanf("%i%i", &l, &r);
		int mn = sptmn[0][r], mx = sptmx[0][r];
		if(l==r){printf("0\n"); continue;}
		int k = log2(r-l);
		for(int j = k; j>=0; j--){
			if(l+(1<<j)<=r){
				mn = min(mn, sptmn[j][l]);
				mx = max(mx, sptmx[j][l]);
				l+=(1<<j);
				if(l==r){break;}
			}
			
		}
		printf("%i\n", mx-mn);
	}
    return 0;
}