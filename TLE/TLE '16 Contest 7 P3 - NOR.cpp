#include <bits/stdc++.h>
using namespace std;
bool a[1000005];
int pv[1000005];

int main(){
	int n, tpv=0, tpi;
	scanf("%i", &n);
	for(int i=1; i<=n; i++){
		scanf("%i", &tpi);
		pv[i]=tpi;
		if (tpi){ tpv = i; }
		pv[i] = tpv;
	}
	int q, x, y;
	scanf("%i", &q);
	while(q--){
		scanf("%i%i", &x, &y);
		if (pv[y]<x){
			if ((y-x+1)%2==0){printf("1\n");}
			else{printf("0\n");}
		}
		else if (pv[y]==x){
			if ((y-x)%2==0){printf("1\n");}
			else{printf("0\n");}
		}
		else{
			if ((y-pv[y]+1)%2==0){printf("1\n");}
			else{printf("0\n");}
		}
	}
	return 0;
}