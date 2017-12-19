#include <cstdio>

using namespace std;
inline int lch(int i){
	return i<<1;
}

inline int max(long long int a, long long int b){
	return (a<b?b:a);
}
inline int min(long long int a, long long int b){
	return (a<b?max(a,0):max(b,0));
}
inline int rch(int i){
	return (i<<1)+1;
}
inline int mid(int a, int b){
	return (a+b)>>1;
}
long long int sgtree[120002];
int bblith[30002];
long long int lzy[120002];
void build(int s, int e, int ind){
	if (s==e){
		sgtree[ind]=bblith[s];
		return;
	}
	build(s, mid(s, e), lch(ind));
	build(mid(s, e)+1, e, rch(ind));
	sgtree[ind]=min(sgtree[lch(ind)],sgtree[rch(ind)]);
	return;
}
long long int updt(int s, int e, int ind, int a, int b, int c){
	sgtree[ind]-=lzy[ind];
	if (s!=e){
		lzy[lch(ind)]+=lzy[ind]; lzy[rch(ind)]+=lzy[ind];
	}
	lzy[ind]=0;
	if (s>b || e<a){return 2000000000;}
	if (s==e){
		sgtree[ind]-=c; 
		return sgtree[ind];
	}
	else if (s>=a && e<=b){
		sgtree[ind]-=c;
		lzy[lch(ind)]+=c; lzy[rch(ind)]+=c;
		return sgtree[ind];
	}
	long long int tpa, tpb;
	tpa=updt(s, mid(s, e), lch(ind), a, b, c);
	tpb=updt(mid(s, e)+1, e, rch(ind), a, b, c);
	sgtree[ind]=min(sgtree[lch(ind)], sgtree[rch(ind)]);
	return min(tpa, tpb);
}
int main() {
	int n, q, a, b, c;
	long long int tp;
	scanf("%i%i", &n, &q);
	for(int i=1; i<=n; i++){
		scanf("%i", &bblith[i]);
	}
	build(1, n, 1);
	for(int i=0; i<q; i++){
		scanf("%i%i%i", &a, &b, &c);
		tp=updt(1, n, 1, a, b, c);
		printf("%i %i\n", max(tp, 0), max(sgtree[1], 0));
	}
	return 0;
}