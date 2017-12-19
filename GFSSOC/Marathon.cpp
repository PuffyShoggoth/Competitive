#include <iostream>
#include <stdio.h>
using namespace std;
int ps[500009];
int main(){
	int n, q, a, b, t;
	cin>>n>>q;
	for (int i=1; i<=n; i++){
		scanf("%i", &t); ps[i]+=ps[i-1]+t;
	}
	for (int i=0; i<q; i++){
		scanf("%i%i", &a, &b);
		printf("%i\n", (ps[a-1]+ps[n]-ps[b]));
	}
	return 0;
}