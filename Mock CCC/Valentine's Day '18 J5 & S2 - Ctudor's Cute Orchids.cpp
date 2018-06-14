#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int cst[15];
int dls[15][15];
int cdl[15];
int req[15];
int tpar[15];
int main() {
	int n, m;
	scanf("%i%i", &n, &m);
	for(int i=0; i<n; i++){
		scanf("%i", &cst[i]);
	}
	for(int i=0; i<m; i++){
		scanf("%i", &cdl[i]);
		for(int j=0; j<n; j++){
			scanf("%i", &dls[i][j]);
		}
	}
	for(int i=0; i<n; i++){
		scanf("%i", &req[i]);
	}
	int mn = INF;
	for(int i=0; i<(1<<m); i++){
		memset(tpar, 0, sizeof(tpar));
		int tpmn = 0;
		for(int j=0; j<m; j++){
			if(i&(1<<j)){
				for(int k=0; k<n; k++){
					tpar[k]+=dls[j][k];
				}
				tpmn+=cdl[j];
			}
		}
		for(int j=0; j<n; j++){
			if(tpar[j]>req[j]){
				tpmn = INF; break;
			}
			else{
				tpmn+=cst[j]*(req[j]-tpar[j]);
			}
		}
		mn=min(mn, tpmn);
	}
	printf("%i\n", mn);
    return 0;
}