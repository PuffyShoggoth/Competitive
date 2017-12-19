#include <cstdio>
using namespace std;

int main() {
	int d, q, tp, mxd=0, mxq=0, mnd=9999999, mnq=9999999;
	scanf("%i", &d);
	for(int i=0; i<d; i++){
		scanf("%i", &tp);
		if (tp>mxd) mxd=tp;
		if (tp<mnd) mnd=tp;
	}
	scanf("%i", &q);
	for(int i=0; i<q; i++){
		scanf("%i", &tp);
		if (tp<mnq) mnq= tp;
		if (tp>mxq) mxq=tp;
	}
	if ((mnq*10 > mxd*25) && (mxq*10 < mnd*25)){
		printf("Neither coin is better");
	}
	else if (10*mnq > 25*mxd){printf("Dimes are better");}
	else if (25*mnd > 10*mxq){printf("Quarters are better");}
	else{printf("Neither coin is better");}
	return 0;
}