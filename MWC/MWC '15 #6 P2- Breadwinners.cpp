#include <iostream>
#include <cstdio>
using namespace std;
bool primes[10009];
int main() {
	int n, c;
	for(int i=2; i<101; i++){
		if(primes[i]==0){
			for(int j=i*i; j<=10000; j+=i){
				primes[j]=1;
			}
		}
	}
	scanf("%i", &n);
	for(int i=0; i<n; i++){
		scanf("%i", &c);
		if (c<=2){printf("no can do\n");}
		else{c--; while(primes[c]){c--;} printf("%i\n", c);}
	}
	return 0;
}