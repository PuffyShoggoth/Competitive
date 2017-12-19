#include <bits/stdc++.h>
using namespace std;
set<int> ch[200010];
int nxt[200010], numh[200010], pvl[200010];
int n;
void update(int cn){
	for(auto it = ch[cn].begin(); it!=ch[cn].end(); ++it){
		nxt[*it]=nxt[cn]; numh[*it]=numh[cn]+1; update(*it);
	}
	return;
}
int qry(int cn){
	if (cn>=n){ return 0; }
	return numh[cn]+qry(nxt[cn]);
}
int main(){
	int k, sqt, q, x, v, tp;
	scanf("%i", &n);
	sqt = sqrt(n);
	for(int i=0; i<n; i++){
		scanf("%i", &k);
		pvl[i]=i+k;
		if (floor(i/sqt)==floor((i+k)/sqt) && i+k<n){
			ch[i+k].insert(i);
		}
	}
	for(int i=n-1; i>=0; i--){
		if (pvl[i]>=n || floor(pvl[i]/sqt)>floor(i/sqt)){
			numh[i]=1; nxt[i]=pvl[i];
		}
		else{
			numh[i]=numh[pvl[i]]+1; nxt[i] = nxt[pvl[i]];
		}
	}
	scanf("%i", &q);
	while(q--){
		scanf("%i", &tp);
		if (tp==1){
			scanf("%i", &x);
			printf("%i\n", qry(x));
		}
		else{
			scanf("%i%i", &x, &v);
			if (pvl[x]<n && floor(pvl[x]/sqt)==floor(x/sqt)){ ch[pvl[x]].erase(x); }
			pvl[x]=x+v;
			if (floor((v+x)/sqt)>floor(x/sqt) || v+x>=n){
				nxt[x]=x+v; numh[x]=1;
			}
			else{
				ch[x+v].insert(x);
				nxt[x]=nxt[x+v]; numh[x]=numh[x+v]+1;
			}
			update(x);
		}
	}
	return 0;
}