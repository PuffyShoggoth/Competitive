#include <cstdio>
#include <bitset>
using namespace std;
bitset<1550> adj[5][1550];

int main() {
	int n, m, k, a, b;
	scanf("%i%i%i", &n, &m, &k);
	for(int i=0; i<m; i++){
		scanf("%i%i", &a, &b);
		adj[0][a][b]=1; adj[0][b][a]=1;
	}
	for(int i=1; i<=n; i++){
		adj[0][i][i]=1;
	}
	for(int i=1; i<k; i++){
		for(int j=1; j<=n; j++){
			for(int l=1; l<=n; l++){
				if (adj[i-1][j][l]){
					adj[i][j]|=adj[0][l];
				}
			}
			
		}
	}
	for(int i=1; i<=n; i++){
		int tt=0;
		for(int j=1; j<=n; j++){
			if (adj[k-1][i][j]) tt++;
		}
		printf("%i\n", tt);
	}
	
	return 0;
}