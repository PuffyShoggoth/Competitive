#include <iostream>
#include <cstdio>
#include <utility>
using namespace std;
pair<int, int> st[20][500009];

pair<int, int>mxt(int a, int b){
	int cs=b-a, pt=0;
	if (a>b){return make_pair(0, 0);}
	pair<int, int> ts=st[0][a];
	while (((1<<pt)+a)<=b){
			if ((cs & (1<<pt))>0){
			a+=(1<<pt);
			if (ts.first==st[pt][a].first){
				ts.second+=st[pt][a].second;
			}
			if (ts.first<st[pt][a].first){
				ts=st[pt][a];}
			}
			pt+=1;
			
	}
	return ts;
}
int main(){
	int n, q, tq, pt=1, ca, cb;
	pair <int, int> ta, tb;
	cin>>n>>q;
	for (int i=1; i<=n; i++){
		scanf("%i", &tq);
		st[0][i]=make_pair(tq, 1);
	}
	while((1<<pt)<=n){
		for (int i=(1<<pt); i<=n; i++){
			if (st[pt-1][i].first==st[pt-1][i-(1<<(pt-1))].first){
				st[pt][i]=make_pair(st[pt-1][i].first, st[pt-1][i].second+st[pt-1][i-(1<<(pt-1))].second);
			}
			else {if (st[pt-1][i].first>st[pt-1][i-(1<<(pt-1))].first){
				st[pt][i]=st[pt-1][i];}
				else{st[pt][i]=st[pt-1][i-(1<<(pt-1))];}
			}
		}
		pt+=1;
	}
	for (int i=0; i<q; i++){
		scanf("%i%i", &ca, &cb);
		ta=mxt(1, ca-1); tb=mxt(cb+1, n);
		if (ta.first==tb.first){printf("%i %i\n", ta.first, (ta.second+tb.second));}
		else{ if (ta.first>tb.first){printf("%i %i\n", ta.first, ta.second);}
			else{printf("%i %i\n", tb.first, tb.second);} }
			
	}
	return 0;
}