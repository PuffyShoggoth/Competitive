#include <bits/stdc++.h>
using namespace std;

pair<int, int> segtree1[400005], segtree2[400005];
pair<int, int> vls1[100005], vls2[100005];
void build(int ind, int l, int r, pair<int, int> segtree[400005], pair<int, int> vls[400005]){
	if (l==r){ segtree[ind]=vls[l]; return; }
	build(ind*2, l, (l+r)/2, segtree, vls); build(ind*2+1, (l+r)/2+1, r, segtree, vls);
	segtree[ind].first = max(segtree[ind*2].first, segtree[ind*2+1].first);
	segtree[ind].second = min(segtree[ind*2].second, segtree[ind*2+1].second);
}
pair<int, int> query(int ind, int l, int r, int a, int b, pair<int, int> segtree[400005]){
	if(l>=a && r<=b){ return segtree[ind];}
	else if (a>(l+r)/2){ return query(ind*2+1, (l+r)/2+1, r, a, b, segtree);}
	else if (b<=(l+r)/2){ return query(ind*2, l, (l+r)/2, a, b, segtree);}
	else{
		pair<int, int> tp1 = query(ind*2, l, (l+r)/2, a, b, segtree);
		pair<int, int> tp2 = query(ind*2+1, (l+r)/2+1, r, a, b, segtree);
		return make_pair(max(tp1.first, tp2.first), min(tp1.second, tp2.second));
	}
}
bool uncertain(pair<int, int> vlsa[100005], int n, int n2, pair<int, int> vlsb[100005], pair<int, int> segtree[400005], bool r){
	for(int i=1; i<=n; i++){
		auto tp = query(1, 1, n2, vlsa[i].first, vlsa[i].second, segtree);
		if (tp.second<i || tp.first>i){
			printf("nonsense\n");
			for(int k=vlsa[i].first; k<=vlsa[i].second; k++){

				if(vlsb[k].first>i || vlsb[k].second<i){
					if (r) printf("%i %i", k, i);
					else printf("%i %i", i, k);
					return 1;
				}
			}
		}
	}
	return 0;
}
int main(){
	int r, c;
	scanf("%i%i", &r, &c);
	int a, b;
	int pva=0, pvb=c;
	bool unconnected = 0;
	for(int i=1; i<=r; i++){
		scanf("%i%i", &a, &b);
		vls1[i]=make_pair(a,b);
		if(a>pvb || b<pva){ unconnected = 1; }
		pva = a; pvb = b;
	}
	pva = 0; pvb = r;
	for(int i=1; i<=c; i++){
		scanf("%i%i", &a, &b);
		vls2[i]=make_pair(a,b);
		if(a>pvb || b<pva){ unconnected = 1; }
		pva = a; pvb = b;
	}
	build(1, 1, c, segtree1, vls2); 
	build(1, 1, r, segtree2, vls1);

	
	if(!uncertain(vls1, r, c, vls2, segtree1, 0) && !uncertain(vls2, c, r, vls1, segtree2, 1)){
		if(unconnected) printf("nonsense\nunconnected");
		else printf("sense");
	}
	return 0;
}