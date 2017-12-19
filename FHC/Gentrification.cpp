#include <cstdio>
#include <vector>
#include <cstring>
#define min(a,b) ((a<b)?a:b)
using namespace std;
bool edges[505][505];

bool done[505];
int par[505];
void clearall(){
	memset(edges, 0, sizeof(edges));
	memset(done, 0, sizeof(done));
	memset(par, -1, sizeof(par));
	return;
}
bool hung(int cn, int n){
	for(int i=0; i<n; i++){
		if (!edges[cn][i] || done[i]) continue;
		done[i]=1;
		if (par[i]<0 || hung(par[i], n)){
			par[i]=cn; return 1;
		}
	}
	return 0;
}
void fw(int n){
	for(int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			for(int k=0; k<n; k++){
				if (edges[j][i]&&edges[i][k]) edges[j][k]=1;
			}
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if (edges[i][j]==edges[j][i]){
				edges[i][j]=0; edges[j][i]=0;
			}
		}
	}
	return;
}

int main() {
	int t, n, m, a, b, ttm;
	scanf("%i", &t);
	for(int donotuseaccidentally=1; donotuseaccidentally<=t; donotuseaccidentally++){
		scanf("%i%i", &n, &m);
		clearall();
		for(int i=0; i<m; i++){
			scanf("%i%i", &a, &b);
			edges[a][b]=1;
		}
		fw(n);
		ttm=0;
		for(int i=0; i<n; i++){
			memset(done, 0, sizeof(done));
			ttm+=hung(i, n);
		}
		printf("Case #%i: %i\n", donotuseaccidentally, n-ttm);
	}
	
	return 0;
}