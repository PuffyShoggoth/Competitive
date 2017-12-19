#include <iostream>
#include <cstdio>
using namespace std;
int primes[1000001];
int main() {
	int n, f, s;
	for (int i=2; i<=1000000; i++){
		primes[i]=1;
	}
	for (int i=2; i<=1000; i++){
		if (primes[i]==0){continue;}
		for (int k=i*i; k<=1000000; k+=i){
			primes[k]=0;
		}
	}
	for (int i=2; i<=1000000; i++){
		primes[i]+=primes[i-1];
	}
	scanf("%i", &n);
	for (int i=0; i<n; i++){
		scanf("%i%i", &f, &s);
		printf("%i\n", (primes[s-1]-primes[f-1]));
	}
	return 0;
}