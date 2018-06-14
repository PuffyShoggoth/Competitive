#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int sh[5];
double a[5];
int dff[2000];
int main() {
	int d, e;
	double h;
	scanf("%lf%i%i", &h, &d, &e);
	for(int i=0; i<d; i++){
		scanf("%lf%i", &a[i], &sh[i]);
		//printf("%lf\n", a[i]);
		a[i] = (100-a[i])/100.0;
		//printf("%lf\n", a[i]);
	}
	for(int i=0; i<e; i++){
		int tj, lj, xj;
		scanf("%i%i%i", &tj, &lj, &xj);
		dff[tj]+=xj;
		dff[tj+lj]-=xj;
	}
	int csm = 0;
	for(int i=0; i<=1005; i++){
		csm += dff[i];
		double cmn = csm;
		if(csm == 0){continue;}
		for(int j=0; j<d; j++){
			if(sh[j]>=csm){ cmn = 0; break;}
			else{
				cmn = min(cmn, (csm-sh[j])*a[j]);
			}
		}
		h-=cmn;
		if(h<0){break;}
	}
	if(h<0){ printf("DO A BARREL ROLL!"); }
	else{printf("%.2f", h);}
    return 0;
}