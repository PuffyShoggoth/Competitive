#include <bits/stdc++.h>

using namespace std;
unordered_map<int, int> dn;
int hsh(int a, int b){
	return max(a, b)*10000+min(a,b);
}
int mnr(int a, int b){
	if (dn.count(hsh(a,b))>0){
		return dn[hsh(a,b)];
	}
	int mb = min(a, b);
	int ma = max(a,b);
	if (a==0 || b==0){ return 0; }
	int lg2 = log2(mb);
	if (a==b && mb==(1<<lg2)){
		return 1;
	}
	int mn=-1;
	int tpa = mnr((1<<lg2), a-(1<<lg2));
	int tpb = mnr((1<<lg2), b-(1<<lg2));
	int tpc = mnr(a-(1<<lg2), b);
	int tpd = mnr(b-(1<<lg2), a);
	if (tpa>-1 && tpd>-1){
		if (mn<0){ mn = tpa+tpd+1; }
		else{ mn = min(mn, tpa+tpd+1);}
	}
	if (tpb>-1 && tpc>-1){
		if (mn<0){ mn = tpb+tpc+1; }
		else{ mn = min(mn, tpb+tpc+1);}
	}
	dn[hsh(a,b)]=mn;
	//printf("%i %i %i\n", a, b, mn);
	return mn;
}
int main() {
	int n, m;
	for(int dnr=0; dnr<5; dnr++){
		scanf("%i%i", &n, &m);
		//printf("%i %i\n", n, m);
		printf("%i\n", mnr(n, m));
	}
    return 0;
}