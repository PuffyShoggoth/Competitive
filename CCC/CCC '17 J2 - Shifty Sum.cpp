#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, k, tt=0;
	scanf("%i%i", &n, &k);
	for(int i=0; i<=k; i++){
		tt+=n;
		n*=10;
	}
	printf("%i", tt);
}