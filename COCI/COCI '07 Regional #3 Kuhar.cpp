#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int mvl;
int mpr;
int x[100], y[100], sm[100], pm[100], sv[100], pv[100];
int main() {
	int n, m;
	scanf("%i%i", &n, &m);
	//int x, y, sm, pm, sv, pv;
	//int curr=0, pv=1;
	int cmx = m;
	for(int dnr=0; dnr<n; dnr++){
		//curr=pv; pv=(pv+1)%2;
		scanf("%i%i%i%i%i%i", &x[dnr], &y[dnr], &sm[dnr], &pm[dnr], &sv[dnr], &pv[dnr]);
	}
	int st=0, ed=m;
	int mx=0;
	while(st<=ed){
		int cmp = 0;
		
		int i = (st+ed)/2;
		int mvl=0;
		for(int k=0; k<n; k++){
			int mpr=0;
			//pr=ceil((x*i-y)/((double) sv))*pv;
			int mx = floor((x[k]*i-y[k])/sv[k]);
			mpr=(mx+1)*pv[k];
			for(int j=0; j<=mx; j++){
				mpr=min((double)mpr, pv[k]*j+ceil((x[k]*i-y[k]-sv[k]*j)/((double) sm[k]))*pm[k]);
			}
			mvl+=mpr;
			if(mvl>m){break;}
			
		}
		if(mvl<=m){
			mx = max(mx, i);
			st = i+1;
		}
		else{
			ed = i-1;
		}
		//putchar('\n');
	}
	printf("%i", mx);
    return 0;
}