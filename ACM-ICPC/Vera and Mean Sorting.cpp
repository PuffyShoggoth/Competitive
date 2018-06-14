#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int ans[105];
int main() {
	int n, k;
	scanf("%i%i",&n,&k);
	if(n>k*2){printf("0"); return 0;}
	int cnt = 1;
	for(int i=0; i<k; i++){
		if(i+k<n){ans[i+k]=cnt; cnt++;}
		ans[i]=cnt; cnt++;
	}
	for(int i=0; i<n; i++){printf("%i ", ans[i]);}
    return 0;
}