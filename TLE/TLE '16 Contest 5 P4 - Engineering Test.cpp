#include <bits/stdc++.h>
using namespace std;
multiset <long long int> tbl;
multiset <long long int> ::iterator it;
long double lvl[2005][2005];
//Why didn't I write this BEFORE the contest ended?
int main() {
	int n, cl=0;
	bool dn=0;
	long long int k, tp;
	scanf("%lli%i", &k, &n);
	for(int i=0; i<n; i++){
		scanf("%lli", &tp);
		tbl.insert(tp);
	}
	while(!tbl.empty()){
		for(int i=1; i<=cl+1; i++){
			it=tbl.lower_bound(ceil((lvl[cl][i-1] + lvl[cl][i])/2));
			if (it==tbl.end()){
				dn=1; break;
			}
			else{
				lvl[cl+1][i]=(lvl[cl][i-1]+lvl[cl][i])/2 + k;
				tbl.erase(it);
			}
		}
		if (dn) break;
		cl++;
	}
	printf("%i", cl);
	return 0;
}