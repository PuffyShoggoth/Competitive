#include <bits/stdc++.h>
using namespace std;

long long int oh[100005];
long long int lazy[800000];
int query(int ind, int l, int r, int t){
	if (l==r){
		return lazy[ind];
	}
	if(lazy[ind]){
		lazy[ind*2]+=lazy[ind];
		lazy[ind*2+1]+=lazy[ind];
		lazy[ind]=0;
	}
	
	int tm = (l+r)/2;
	if (tm>=t){
		return query(ind*2, l, tm, t);
	}
	else{
		return query(ind*2+1, tm+1, r, t);
	}
}
void update(int ind, int l, int r, int cl, int cr, int vl){
	if(cl<=l && cr>=r){
		lazy[ind]+=vl;
		return;
	}
	else{
		int tm = (l+r)/2;
		lazy[ind*2]+=lazy[ind];
		lazy[ind*2+1]+=lazy[ind];
		lazy[ind]=0;
		if (tm<cl){
			update(ind*2+1, tm+1, r, cl, cr, vl);
		}
		else if (tm>=cr){
			update(ind*2, l, tm, cl, cr, vl);
		}
		else{
			update(ind*2, l, tm, cl, cr, vl);
			update(ind*2+1, tm+1, r, cl, cr, vl);
		}
	}
}
long long int n, m, k;
bool pob(long long int mnv){
	long long int ni = 0;
	//printf("%i\n", mnv);
	for(int i=0; i<n; i++){
		//if (oh[i]+lazy[i]>=mnv){continue;}
		long long int tp = query(1, 0, n-1, i);
		//printf("%i %i ", i, tp);
		if (tp+oh[i]<mnv){
			ni+=mnv-tp-oh[i];
			//printf("%i", ni);
			if (ni>k) { return 0;}
			update(1, 0, n-1, i, min(i+m-1, n-1), mnv-tp-oh[i]);
		}
		//printf("\n");
	}
	return 1;
}

int main(){
	
	scanf("%lli%lli%lli", &n, &m, &k);
	long long int st=1000000000, ed=0;
	for(int i=0; i<n; i++){
		scanf("%lli", &oh[i]);
		ed = max(ed, oh[i]);
		st = min(st, oh[i]);
	}
	ed +=k+1;
	while(st<ed){
		memset(lazy, 0, sizeof(lazy));
		long long int mp = (st+ed)/2;
		if (pob(mp)){
			st = mp+1;
		}
		else{
			ed = mp;
		}
	}
	printf("%lli",st-1);
}