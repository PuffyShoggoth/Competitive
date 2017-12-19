#include <bits/stdc++.h>
using namespace std;

bitset <100005> sieve;
bitset <20000005> ans;
int main(){
	long long int n, m, tp, ttp;
	scanf("%lli%lli", &n, &m);
	sieve[0]=1; sieve[1]=1;
	for(long long int i=2; i<=sqrt(m); i++){
		if (sieve[i]){continue; }
		ttp = n/i;
		tp = i*ttp+((n%i)?i:0);
		if (i*i>tp){ tp = i*i; }
	    for(long long int j = tp; j<=m; j+=i){
	        ans[j-n]=1;
		}
		for(long long int j=i*i; j<=sqrt(m); j+=i){
			sieve[j]=1;
		}
	}
	if (n==1){ans[0]=1;}
	int sm=0;
	for(int i=0; i<m-n; i++){
		sm+=(!ans[i]);
	}
	printf("%i", sm);

}