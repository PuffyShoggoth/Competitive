#include <bits/stdc++.h>
using namespace std;
long long int fct[34];

int main() {
	fct[0]=1;
	long long int mod = 1LL<<32;
	for(int i=1; i<34; i++){
		fct[i]=(fct[i-1]*i)%mod;
	}
	int n; unsigned long long int nf; 
	scanf("%i", &n);
	for(int i=0; i<n; i++){
		scanf("%llu", &nf);
		if (nf>33) printf("0\n");
		else printf("%lli\n", fct[nf]);
	}
	return 0;
}