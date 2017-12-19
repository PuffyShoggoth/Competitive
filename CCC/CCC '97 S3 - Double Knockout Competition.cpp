#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, t;
	cin>>n; 
	while(n--){
		cin>>t;
		int u=t, o=0, e=0, cnt=0;
		while (1){
			printf("Round %i: %i undefeated, %i one-loss, %i eliminated\n", cnt, u, o, e);
			cnt++;
			if (u<2 && o<2) { break; }
			e+=o/2;
			o-=o/2;
			o+=u/2;
			u-=u/2;
		}
		printf("Round %i: 0 undefeated, 2 one-loss, %i eliminated\n", cnt, e);
		printf("Round %i: 0 undefeated, 1 one-loss, %i eliminated\n", cnt+1, e+1);
		printf("There are %i rounds.\n\n", cnt+1);
	}
	return 0;
}