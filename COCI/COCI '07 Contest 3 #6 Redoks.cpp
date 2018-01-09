#include <bits/stdc++.h>
using namespace std;


int segtree[2000005][10];
int lzy[2000005];
int vls[500005];
void build(int ind, int l, int r){
	if (l==r){
		segtree[ind][vls[l]]=1;
	}
	else{
		build(ind*2, l, (l+r)/2);
		build(ind*2+1, (l+r)/2+1, r);
		for(int i=0; i<10; i++){
			segtree[ind][i] = segtree[ind*2][i]+segtree[ind*2+1][i];
		}
	}
}
void incn(int ind){
	int pvd = lzy[ind]%10;
	int tp[10];
	for(int i=0; i<10; i++){ tp[i]=segtree[ind][i]; }
	for(int i=0; i<10; i++){
		segtree[ind][(i+pvd)%10]=tp[i];
	}
	lzy[ind]=0;
}
void update(int ind, int cl, int cr, int l, int r){
	if(cl>r || cr<l){
		lzy[ind*2]+=lzy[ind]; lzy[ind*2+1]+=lzy[ind];
		incn(ind);
		 
		return;
	}
	else if(l<=cl && r>=cr){
		lzy[ind]+=1;
		lzy[ind*2]+=lzy[ind]; lzy[ind*2+1]+=lzy[ind]; 
		incn(ind);
		return;
	}
	else{
		update(ind*2, cl, (cl+cr)/2, l, r);
		update(ind*2+1, (cl+cr)/2+1, cr, l, r);
		for(int i=0; i<10; i++){
			segtree[ind][i]=segtree[ind*2][i]+segtree[ind*2+1][i];
		}
	}
}
int query(int ind, int cl, int cr, int l, int r){
	if(cl>r || cr<l) return 0;
	else if(l<=cl && r>=cr){
		if (lzy[ind]){
			lzy[ind*2]+=lzy[ind]; lzy[ind*2+1]+=lzy[ind]; 
			incn(ind);
		}
		int tt = 0;
		for(int i=0; i<10; i++){
			tt+=i*segtree[ind][i];
		}
		return tt;
	}
	else{
		lzy[ind*2]+=lzy[ind];
		lzy[ind*2+1]+=lzy[ind];
		incn(ind);
		int tp = query(ind*2, cl, (cl+cr)/2, l, r);
		tp+=query(ind*2+1, (cl+cr)/2+1, cr, l, r);
		return tp;
	}
}


int main(){
	int n, m;
	scanf("%i%i", &n, &m);
	for(int i=1; i<=n; i++){
		char c = getchar();
		while(c<'0' || c>'9'){ c=getchar(); }
		vls[i]=c-'0';
	}
	build(1, 1, n);
	int a, b;
	for(int i=0; i<m; i++){
		scanf("%i%i", &a, &b);
		printf("%i\n", query(1, 1, n, a, b));
		update(1, 1, n, a, b);
	}

}