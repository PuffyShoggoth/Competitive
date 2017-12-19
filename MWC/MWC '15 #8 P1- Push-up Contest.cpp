#include <iostream>
#include <cstdio>
using namespace std;
int main() {
	long long int n;
	long long int t;
	long long int s;
	scanf("%lli", &n);
	t=(n*(n+1))/2;
	for(int i=0; i<n-1; i++){
		scanf("%lli", &s); t-=s;
	}
	printf("%lli", t);
	return 0;
}