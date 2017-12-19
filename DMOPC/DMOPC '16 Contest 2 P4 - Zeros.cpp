#include <cstdio>
using namespace std;
long long int zrs(long long int k){
	long long int sm=0;
	while(k>0){
		k=k/5;
		sm+=k;
	}
	return sm;
}
long long int bsrch(unsigned int k){
	long long int s=1, e=4000000050, m;
	while(s<=e){
		m=zrs((s+e)>>1);
		if (m<k){
			s=((s+e)>>1)+1;
		}
		else{
			e=((s+e)>>1)-1;
		}
	}
	return s;
}
int main() {
	long long  int a, b;
	scanf("%lli%lli", &a, &b);
	printf("%lli", bsrch(b+1)-bsrch(a));

	return 0;
}