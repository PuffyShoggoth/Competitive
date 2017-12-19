#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
bool sv[31625];
vector<int> primes;
int a, b, c, d, sm=0, tps, tpe;
int main() {
	for(int i=2; i<31624; i++){
		if (sv[i]==1){continue;}
		primes.push_back(i);
		for(int k=i*i; k<31624; k+=i){
			sv[k]=1;
		}
	}
	bool pp=1;
	scanf("%i%i%i%i", &a, &b, &c, &d);
	for (int i=a; i<=b; i++){
		pp=1;
		for(int k=0; k<primes.size(); k++){
			if (primes[k]*primes[k]>i){break;}
			if (i%primes[k]==0){pp=0; break;}
		}
		if (pp==1){
			tps=(c/i)+((c%i)!=0);
			tpe=(d/i);
			sm+=(((((tps+tpe)*(tpe-(tps-1)))/2)%2016420)*(i%2016420))%2016420;
			sm=sm%2016420;
		}
	}
	printf("%i", sm);
	return 0;
}