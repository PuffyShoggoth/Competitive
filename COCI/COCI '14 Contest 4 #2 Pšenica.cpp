#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int stalks[100009];
int main() {
	int n, mirk, slav, mim=0, slm=0, high, low;
	scanf("%i", &n);
	mirk=1; slav=n-2;
	for(int i=0; i<n; i++){
		scanf("%i", &stalks[i]);
	}
	sort(stalks, stalks+n);
	low=stalks[0]; high=stalks[n-1];
	if (n==1){printf("Slavko \n%i %i", stalks[0], stalks[0]);}
	else if (stalks[slav]==stalks[mirk]){
		if (stalks[n-1]!=stalks[mirk] && stalks[0]!=stalks[slav]){ printf("Mirko \n%i %i", stalks[mirk], stalks[n-1]);}
		else{ printf("Slavko \n%i %i", stalks[0], stalks[n-1]);}
	}
	else{
		while (stalks[slav]!=stalks[mirk]){
			if (mim<=slm){
				slm-=mim;
				while (mirk<n-1 && stalks[mirk-1]==stalks[mirk]){mirk+=1;}
				mim=mirk;
				low=stalks[mirk-1];
				stalks[mirk-1]=stalks[mirk];
			}
			else{
				mim-=slm;
				while (slav>0 && stalks[slav+1]==stalks[slav]){slav-=1;}
				slm=n-1-slav;
				high=stalks[slav+1];
				stalks[slav+1]=stalks[slav];
			}
		}
		if (mim <= slm){printf("Mirko\n%i %i", stalks[mirk], high);}
		else{printf("Slavko\n%i %i", low, stalks[slav]);}
	}	
	return 0;
}