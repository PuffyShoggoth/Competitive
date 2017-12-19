#include <bits/stdc++.h>
using namespace std;
//let's start with brute force
short int ch[5000][200]; //(p,q)-(p, q+1)
short int cv[5000][200];//(p,q)-(p+1),q
int r, c;
int segtree[1500][200][200];
int dr[205];
int dl[205];
int pv[205][205][2];
int d2[205][205];
int mxind = 1500;
void merge(int ind, int l, int r){
	int mn;
	int m = (l+r)/2;

	for(int i=0; i<c; i++){
		mn = segtree[ind*2][i][0]+segtree[ind*2+1][0][i]+cv[m][0];
		for(int j=0; j<c; j++){
			if(segtree[ind*2][i][j]+segtree[ind*2+1][j][i]+cv[m][j]<=mn){
				dr[i]=j;
				dl[i]=j;
				mn = segtree[ind*2][i][j]+segtree[ind*2+1][j][i]+cv[m][j];
			}
		}
		segtree[ind][i][i]=mn;
	}
	for(int i=1; i<c; i++){
		for(int j=0; j<c-i; j++){
			mn = segtree[ind*2][j][dr[j]]+segtree[ind*2+1][dr[j]][j+i]+cv[m][dr[j]];
			for(int k=dr[j]+1; k<=dr[j+1]; k++){
				if(segtree[ind*2][j][k]+segtree[ind*2+1][k][j+i]+cv[m][k]<=mn){
					mn = segtree[ind*2][j][k]+segtree[ind*2+1][k][j+i]+cv[m][k];
					dr[j] = k; 
				}
			}
			segtree[ind][j][j+i]=mn;
		}
		for(int j=c-1; j>=i; j--){
			mn = segtree[ind*2][j][dl[j]]+segtree[ind*2+1][dl[j]][j-i]+cv[m][dl[j]];
			for(int k=dl[j]-1; k>=dl[j-1]; k--){
				if(segtree[ind*2][j][k]+segtree[ind*2+1][k][j-i]+cv[m][k]<=mn){
					mn = segtree[ind*2][j][k]+segtree[ind*2+1][k][j-i]+cv[m][k];
					dl[j] = k; 
				}
			}
			segtree[ind][j][j-i]=mn;
		}
	}
}
void bruteforce(int ind, int l, int r){
	memset(pv, 0, sizeof(pv));
	memset(dr, 0, sizeof(dr));
	int curr = 1; int prv = 0;
	for(int i=0; i<c; i++){
		pv[i][i][curr]=0;
		for(int j=i-1; j>=0; j--){
			pv[i][j][curr]=pv[i][j+1][curr]+ch[r][j];
		}
		for(int j=i; j<c-1; j++){
			pv[i][j+1][curr]=pv[i][j][curr]+ch[r][j];
		}
	}
	for(int i=r-1; i>=l; i--){
		prv=curr;
		curr=(curr+1)%2;
		for(int j=0; j<c; j++){
			d2[0][j]=pv[0][j][prv]+cv[i][0];
		}
		for(int j=1; j<c; j++){
			for(int k=0; k<c; k++){
				d2[j][k]=min(d2[j-1][k]+ch[i][j-1], pv[j][k][prv]+cv[i][j]);
			}
		}
		for(int j=0; j<c; j++){
			pv[c-1][j][curr]=d2[c-1][j];
		}
		for(int j=c-2; j>=0; j--){
			for(int k=0; k<c; k++){
				pv[j][k][curr]=min(d2[j][k], pv[j+1][k][curr]+ch[i][j]);
			}
		}
	}
	for(int i=0; i<c; i++){
		for(int j=0; j<c; j++){
			segtree[ind][i][j]=pv[i][j][curr];
		}
	}
}
void build(int ind, int l, int r){
	
	if(ind*2+1<mxind && l!=r){
		build(ind*2, l, (l+r)/2);
		build(ind*2+1, (l+r)/2+1, r);
		merge(ind, l, r);
		return;
	}
	else{
		bruteforce(ind, l, r);
		return;
	}
}
void update(int ind, int l, int r, int v){
	if(r<v || l>v) return;
	if(ind*2+1<mxind && l!=r){
		int m = (l+r)/2;
		update(ind*2, l, m, v);
		update(ind*2+1, m+1, r, v);
		merge(ind, l, r);
		return;
	}
	else{
		bruteforce(ind, l, r);
		return;
	}
}
void init(int R, int C, int H[5000][200], int V[5000][200]){
	r = R; c = C;
	for(int i=0; i<R; i++){
		for(int j=0; j<C-1; j++){
			ch[i][j]=H[i][j];
		}
	}
	for(int i=0; i<R-1; i++){
		for(int j=0; j<C; j++){
			cv[i][j]=V[i][j];
		}
	}
	build(1, 0, R-1);
}
void changeH(int P, int Q, int W){
	ch[P][Q]=W;
	update(1, 0, r-1, P);
}
void changeV(int P, int Q, int W){
	cv[P][Q]=W;
	update(1, 0, r-1, P);
}
int escape(int V1, int V2){
	return segtree[1][V1][V2];
}