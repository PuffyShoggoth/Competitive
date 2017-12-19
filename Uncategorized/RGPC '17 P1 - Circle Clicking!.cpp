#include <cstdio>


int main(){
	int n, d;
	scanf("%i%i", &n, &d);
	d=d*d;
	int lc=0, cc=0;
	int pvx, pvy, x, y;
	for(int i=0; i<n; i++){
		scanf("%i%i", &x, &y);
		if (!cc){
			cc=1;
		}
		else if ((pvx-x)*(pvx-x)+(pvy-y)*(pvy-y)>d){
			cc=0;
		}
		else{
			cc++;
		}
		lc=(cc>lc)?cc:lc;
		pvx=x; pvy=y;
	}
	printf("%i", lc);

}