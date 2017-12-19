#include <cstdio>
#define min(a,b) ((a<b)?a:b)
using namespace std;
int lrc[355][355][355];
int best[122505];
int main() {
	int r, c, m, u, v;
	scanf("%i%i%i", &r, &c, &m);
	for(int i=1; i<=r; i++){
		for(int j=1; j<=c; j++){
			lrc[1][i][j]=m;
		}
	}
	if (c*r>m){best[m]=1;}
	best[m-1]=1;
	for(int i=0; i<m; i++){
		scanf("%i%i", &u, &v);
		lrc[1][u][v]=i;
	}
	for(int i=2; i<=min(r,c); i++){
		for(int j=i; j<=r; j++){
			for(int k=i; k<=c; k++){
				lrc[i][j][k]=min(min(lrc[i-1][j-1][k-1], lrc[i-1][j][k]), min(lrc[i-1][j-1][k], lrc[i-1][j][k-1]));
				best[lrc[i][j][k]]=i;
			}
		}
	}
	for(int i=m-1; i>=0; i--){
		if (best[i+1]>best[i]) best[i]=best[i+1];
	}
	for(int i=1; i<=m; i++){
		printf("%i\n", best[i]);
	}
	return 0;
}