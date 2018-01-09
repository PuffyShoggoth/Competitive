#include <bits/stdc++.h>
#include "secret.h"
using namespace std;

int arr[1005];
int segtree[4005][1005];
int fn;
void build(int ind, int l, int r){
	if (l==r){segtree[ind][l]=arr[l]; return;}
	int m = (l+r)/2;
	segtree[ind][m]=arr[m];
	build(ind*2, l, m);
	build(ind*2+1, m+1, r);
	for(int i=m-1; i>=l; i--){
		segtree[ind][i]=Secret(arr[i], segtree[ind][i+1]);
	}
	segtree[ind][m+1]=arr[m+1];
	for(int i=m+2; i<=r; i++){
		segtree[ind][i]=Secret(segtree[ind][i-1], arr[i]);
	}
}
int squery(int ind, int l, int r, int cl, int cr){
	int m = (l+r)/2;
	if (cr==m){
		return segtree[ind][cl];
	}
	else if(cl==m+1){
		return segtree[ind][cr];
	}
	else if (cr<m){
		return squery(ind*2, l, m, cl, cr);
	}
	else if (cl>m){
		return squery(ind*2+1, m+1, r, cl, cr);
	}
	else{
		return Secret(segtree[ind][cl], segtree[ind][cr]);
	}
}
int Query(int L, int R){
	return squery(1, 0, fn-1, L, R);
}
void Init(int N, int A[]){
	for(int i=0; i<N; i++){
		arr[i]=A[i];
	}
	fn = N;
	build(1, 0, N-1);
}