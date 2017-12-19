#include <bits/stdc++.h>
#define lch(a) (a<<1)
#define rch(a) ((a<<1)+1)
#define ls(a,b) ((a+b)>>1)
#define rs(a,b) (((a+b)>>1)+1)
using namespace std;
long long int lzy[800005];
long long int sgt[800005];
void ulzy(int cn){
	sgt[cn]+=lzy[cn];
	lzy[rch(cn)]+=lzy[cn];
	lzy[lch(cn)]+=lzy[cn];
	lzy[cn]=0;
}
void update(int cn, int st, int ed, int ups, int upe, int vl){
	if (ups<=st && upe>=ed){lzy[cn]+=vl;}
	if (st==ed){ sgt[cn]+=lzy[cn]; lzy[cn]=0; return; }
	ulzy(cn);
	if (ups<=st && upe>=ed){return;}
	if (ups>ed || upe<st){ return; }
	update(lch(cn), st, ls(st,ed), ups, upe, vl);
	update(rch(cn), rs(st,ed), ed, ups, upe, vl);
	sgt[cn]=max(sgt[rch(cn)], sgt[lch(cn)]);
	return;
}
long long int qry(int cn, int st, int ed, int l, int r){
	if (ed<l || st>r){ return 0; }
	else if (st==ed){ return sgt[cn]+lzy[cn]; }
	ulzy(cn);
	if (l<=st && r>=ed){ return sgt[cn]; }
	return max(qry(lch(cn), st, ls(st,ed), l, r), qry(rch(cn), rs(st,ed), ed, l, r));

}
int main(){
	int n, k, q;
	scanf("%i%i%i", &n, &k, &q);
	k--;
	for(int i=0; i<q; i++){
		int ins, a, b;
		scanf("%i%i%i", &ins, &a, &b);
		if (ins==0){
			if (a<n){
				if (a<k){
					update(1, 0, n-1, 0, a, b);
				}
				else{
					update(1, 0, n-1, a-k, a, b);
				}
			}
		}
		else{
			printf("%lli\n", qry(1, 0, n-1, a, b));
		}
	}
	return 0;
}