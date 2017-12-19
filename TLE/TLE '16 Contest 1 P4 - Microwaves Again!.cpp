#include <cstdio>
#include <algorithm>
#include <bitset>
using namespace std;
int mic[105];
bitset<105> nrby[105];
int adj[105][105];

int main() {
	int n, m, k, u, v, d, mxex=0, tpmx;
	bitset<105> tpa;
	scanf("%i%i%i", &n, &m, &k);
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			adj[i][j]=1000000000;
		}
		adj[i][i]=0;
	}
	for(int i=1; i<=n; i++){
		scanf("%i", &mic[i]);
	}
	for(int i=0; i<m; i++){
		scanf("%i%i%i", &u, &v, &d);
		adj[u][v]=d; adj[v][u]=d;
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			for(int l=1; l<=n; l++){
				adj[j][l]=min(adj[j][l], adj[j][i]+adj[i][l]);
				if (adj[j][l]<=k){ nrby[j][l]=1;}
			}
		}
	}
	if (n==1){
		mxex=mic[1];
	}
	else if (n==2){
		tpa=nrby[1]|nrby[2];
		for(int i=1; i<=n; i++){
			if (tpa[i]) mxex+=mic[i];
		}
	}
	else{
		for(int i=1; i<=n; i++){
			for(int j=1; j<i; j++){
				for(int l=1; l<j; l++){
					tpa.reset();
					tpmx=0;
					tpa|=nrby[i];
					tpa|=nrby[j];
					tpa|=nrby[l];
					for(int p=1; p<=n; p++){
						if (tpa[p]) tpmx+=mic[p];
					}
					mxex=max(tpmx, mxex);
				}
			}
		}
	}
	printf("%i", mxex);
	return 0;
}