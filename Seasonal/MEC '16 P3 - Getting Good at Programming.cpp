#include <iostream>
#include <utility>
#include <cstdio>
using namespace std;

pair<int, int>lvl[109][109];
int mx[109][109];

int main(){
	int n, t, l, ti, xi, mxm=0;
	scanf("%i%i", &n, &t);
	for(int i=1; i<=n; i++){
		scanf("%i", &l);
		lvl[i][0]=make_pair(l, 0);
		scanf("%i%i", &ti, &xi);
		lvl[i][1]=make_pair(ti, xi);
		for(int j=2; j<=l; j++){
			scanf("%i%i", &ti, &xi);
			lvl[i][j]=make_pair(ti+lvl[i][j-1].first, xi+lvl[i][j-1].second);
		}
	}
	for(int i=1; i<=n; i++){
		l=lvl[i][0].first;
		for(int j=1; j<=l; j++){
			for (int k=lvl[i][j].first; k<=t; k++){
				mx[i][k]=max(max(mx[i][k], mx[i-1][k]), mx[i-1][k-lvl[i][j].first]+lvl[i][j].second);
			}
		}
		for(int j=0; j<lvl[i][1].first; j++){
			mx[i][j]=mx[i-1][j];
		}
		mxm=max(mxm, mx[i][t]);
	}

	printf("%i", mxm);
	return 0;
}