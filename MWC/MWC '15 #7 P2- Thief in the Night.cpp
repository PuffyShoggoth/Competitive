#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
pair<int, int> dirs[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
long long int pfx[10][10005];

int main() {
	int f, r;
	scanf("%i%i", &f, &r);
	for(int i = 1; i<=f; i++){
		for(int j = 1; j<=r; j++){
			scanf("%lli", &pfx[i][j]);
			pfx[i][j]+=pfx[i][j-1];
		}
	}
	int q;
	scanf("%i", &q);
	for(int i = 0; i<q; i++){
		int a, b, c;
		scanf("%i%i%i", &a, &b, &c);
		printf("%lli\n", pfx[c][b]-pfx[c][a-1]);
	}
    return 0;
}