#include <bits/stdc++.h>
using namespace std;
unordered_map<int, int> mds;

int main(){
	int n, m, c, tp;
	long long int tt=0, cs = 0;
	scanf("%i%i", &n, &m);
	mds[0]=1;
	for(int i=0; i<n; i++){
		scanf("%i", &c);
		cs+=c;
		tp = cs%m;
		tt+=mds[tp];
		mds[tp]++;
	}
	printf("%lli", tt);
}