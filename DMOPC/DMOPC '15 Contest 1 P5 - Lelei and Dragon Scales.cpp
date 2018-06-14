#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
pair<int, int> dirs[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int pfx[300][300];

int main() {
	int w, h, n;
	scanf("%i%i%i", &w, &h, &n);
	for(int i = 1; i<=h; i++){
		int cvl = 0;
		for(int j=1; j<=w; j++){
			scanf("%i", &pfx[i][j]);
			cvl += pfx[i][j];
			pfx[i][j]=cvl+pfx[i-1][j];
		}
	}
	int mxs = 0;
	for(int i = 1; i<=min(n, h); i++){
		int tw = min(w, n/i);
		for(int j = h; j>=i; j--){
			for(int k = w; k>=tw; k--){
				mxs = max(mxs, pfx[j][k]-pfx[j-i][k]-pfx[j][k-tw]+pfx[j-i][k-tw]);
			}
		}
	}
	printf("%i", mxs);
    return 0;
}