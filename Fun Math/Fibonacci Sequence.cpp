#include <iostream>
#include <cstdio>
using namespace std;
unsigned long long int fib[64][3];
unsigned long long int n;
unsigned long long int cm[3];
unsigned long long int tp[3];
int main() {
	fib[0][0]=1; fib[0][1]=1; fib[0][2]=0;
	for(int i=1; i<64; i++){
		fib[i][0]=((fib[i-1][0]*fib[i-1][0])%1000000007+(fib[i-1][1]*fib[i-1][1])%1000000007)%1000000007;
		fib[i][1]=((fib[i-1][0]*fib[i-1][1])%1000000007+(fib[i-1][1]*fib[i-1][2])%1000000007)%1000000007;
		fib[i][2]=((fib[i-1][1]*fib[i-1][1])%1000000007+(fib[i-1][2]*fib[i-1][2])%1000000007)%1000000007;
	}
	scanf("%llu", &n);
	int p=0, f=0;
	while(f==0){
		if (n&1>0){
			cm[0]=fib[p][0];
			cm[1]=fib[p][1];
			cm[2]=fib[p][2];
			f=1;
		}
		p+=1;
		n>>=1;
	}
	while (n>0){
		if (n&1>0){
			tp[0]=cm[0]; tp[1]=cm[1]; tp[2]=cm[2];
			cm[0]=((fib[p][0]*tp[0])%1000000007+(fib[p][1]*tp[1])%1000000007)%1000000007;
			cm[1]=((fib[p][1]*tp[0])%1000000007+(fib[p][2]*tp[1])%1000000007)%1000000007;
			cm[2]=((fib[p][1]*tp[1])%1000000007+(fib[p][2]*tp[2])%1000000007)%1000000007;
			f=1;
		}
		p+=1;
		n>>=1;
	}
	printf("%llu", cm[1]);
	return 0;
}