#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#define MOD 1000000007
using namespace std;
vector<int> unlock[100009];

long long int fact(long long int s, long long int e){
	long long int tt=1;
	for(int i=s+1; i<=e; i++){
		long long int tp=i;
		while(tp%MOD==0){tp/=MOD;}
		tt=(tt*tp)%MOD;
	}
	return tt;
}
long long int exeuc(long long int fn){
	long long int q=fn/MOD, ft=1, st=0, tp, pr=MOD, sn=fn%MOD;
	while(sn>0){
		tp=ft-st*q;
		ft=st; st=tp;
		q=pr/sn;
		tp=sn; sn=pr-sn*q; pr=tp;
	}
	if (st<0){return st+MOD;}
	else{return st;}
}
int comb(long long int n, long long int r){
	long long int num=fact(n, n+r);
	long long int dnm=exeuc(fact(1, r));
	return (num*dnm)%MOD;
}

pair<long long int, long long int> croot(int i){
	long long int ch=0, pr=1;
	pair<long long int, long long int> tmp;
	for(int k=0; k<unlock[i].size(); k++){
		tmp=croot(unlock[i][k]);
		pr=((pr%MOD)*(tmp.second%MOD))%MOD;
		pr=((pr%MOD)*comb(max(ch, tmp.first), min(ch, tmp.first)))%MOD;
		ch+=tmp.first;
	}
	return make_pair(ch+1, pr);
}
int main() {
	int n, pr;
	scanf("%i", &n);
	for(int i=1; i<=n; i++){
		scanf("%i", &pr);		
		unlock[pr].push_back(i);
	}
	printf("%lli", croot(0).second);
	return 0;
}