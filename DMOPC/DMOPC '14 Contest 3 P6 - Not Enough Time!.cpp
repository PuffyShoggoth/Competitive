#include <cstdio>
#include <algorithm>
using namespace std;


int tt[10005];

int main(){
	int n, t, pp, vp, pa, va, pg, vg;
	scanf("%i%i", &n, &t);
	for(int i=0; i<n; i++){
		scanf("%i%i%i%i%i%i", &pp, &vp, &pa, &va, &pg, &vg);
		for(int j=t; j>=pg; j--){
			tt[j]=max(max(tt[j], tt[j-pp]+vp), max(tt[j-pa]+va, tt[j-pg]+vg));
		}
		for(int j=pg-1; j>=pa; j--){
			tt[j]=max(tt[j], max(tt[j-pp]+vp, tt[j-pa]+va));
		}
		for(int j=pa-1; j>=pp; j--){
			tt[j]=max(tt[j], tt[j-pp]+vp);
		}
	}
	printf("%i", tt[t]);
	return 0;
}