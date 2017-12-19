#include <bits/stdc++.h>
using namespace std;
bool adj[21][21];
int main(){
	int n, m;
	scanf("%i%i", &n, &m);
	int a, b;
	for(int i=0; i<m; i++){
		scanf("%i%i", &a, &b);
		a--; b--;
		adj[a][b]=1; adj[b][a]=1;
	}
	int tt=0;
	for(int i=(1<<n)-1; i>=0; i--){
		bool vld = 1;
		for(int j=0; j<n; j++){
			for (int k=0; k<j; k++){
				if ((i&(1<<j)) && (i&(1<<k)) && adj[j][k]){
					vld=0; break;
				}
			}
			if (!vld){break; }
		}
		if (vld){ tt++; }
	}
	printf("%i", tt);
}