#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, sm;
	long long int x;
	scanf("%i", &t);
	while(t--){
		scanf("%lli", &x);
		sm=0;
		while(x){
			if (x%2 == 0){
				sm++; x=x>>1;
			}
			else if (x&2 && x!=3){
				x++; sm++;
			}
			else{
				x--; sm++;
			}
		}
		printf("%i\n", sm);
	}
	return 0;
}