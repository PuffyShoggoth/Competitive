#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
multiset<long long int> slices;
multiset<long long int>::iterator it;
long long int pfs[100009];
int main() {
	int n, k;
	long long int mx=0, tp;
	scanf("%i%i", &n, &k);
	for(int i=1; i<=n; i++){
		scanf("%lli", &tp);
		pfs[i]=pfs[i-1]+tp;
	}
	slices.insert(pfs, pfs+k);
	for(int i=k; i<=n; i++){
		it=slices.begin(); 
		mx=max(pfs[i]-*it, mx);
		it=slices.find(pfs[i-k]);
		slices.erase(it);
		slices.insert(pfs[i]);
	}
	for(int i=1; i<k; i++){
		it=slices.begin();
		mx=max(pfs[i]+pfs[n]-*it, mx);
		it=slices.find(pfs[n-k+i]);
		slices.erase(it);
		slices.insert(pfs[i]+pfs[n]);
	}
	printf("%lli", mx);
	return 0;
}