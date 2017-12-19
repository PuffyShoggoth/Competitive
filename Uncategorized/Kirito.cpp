#include <bits/stdc++.h>
#define lft(a) (a<<1)
#define rght(a) ((a<<1)+1)
using namespace std;
int r, c;
int trie[10000005][2];
int pos[2005][5005];
struct node{
	int st, ed, vl, mp, fr, fl;

};

int cmn(int a, int b){
	int st=0, ed = c;
	while(st<ed){
		int m = ((st+ed)>>1)+(st+ed)%2;
		if (pos[a][m] == pos[b][m]){
			st = m;
		}
		else{
			ed = m-1;
		}
	}
//	printf("%ied\n", st);
	return ed;
}
int id[2005];
int pn[2005];
node sgt[10005];
void rst(int ind){
	sgt[ind].fl = sgt[lft(ind)].fl; sgt[ind].fr = sgt[rght(ind)].fr;
	sgt[ind].vl = cmn(sgt[lft(ind)].fr, sgt[rght(ind)].fl);
	sgt[ind].mp = min(sgt[lft(ind)].mp, min(sgt[rght(ind)].mp, sgt[ind].vl));
}
void update(int ind, int val){
	sgt[ind].fl = val; sgt[ind].fr = val;
	ind = ind >>1;
	while(ind>0){
		rst(ind);
		ind = ind>>1;
	}
	return;
}
int qry(int ind, int cs, int ce, int s, int e){
	if (cs>=s && ce <=e){ return sgt[ind].mp; }
	else if (s>((cs+ce)>>1)){return qry(rght(ind), ((cs+ce)>>1)+1, ce, s, e);}
	else if (e<=((cs+ce)>>1)){ return qry(lft(ind), cs, (cs+ce)>>1, s, e);}
	else{
		return min(sgt[ind].vl, min(qry(rght(ind), ((cs+ce)>>1)+1, ce, s, e), qry(lft(ind), cs, (cs+ce)>>1, s, e)));
	}
}
void build(int ind, int st, int ed){
	sgt[ind].st=st; sgt[ind].ed= ed;
	if (st == ed){
		pn[st] = ind;
		sgt[ind].vl = c; sgt[ind].mp = c; sgt[ind].fr = id[st]; sgt[ind].fl=id[st]; return;
	}
	build(lft(ind), st, (st+ed)>>1);
	build(rght(ind), ((st+ed)>>1)+1, ed);
	rst(ind);
	return;
}
int main(){
	int count = 1;
	scanf("%i%i", &r, &c);
	memset(id, -1, sizeof(id));
	for(int i=1; i<=r; i++){
		id[i] = i;
		getchar(); int curr = 0;
		for(int j=1; j<=c; j++){
			char tp = getchar() - '0';
			if (trie[curr][tp] == 0){ trie[curr][tp] = count; curr = count; count++; }
			else{ curr = trie[curr][tp];}
			pos[i][j] = curr;
		}
	}
	build(1, 1, r); 
	int q, f, s;
	scanf("%i", &q);
	for(int i=0; i<q; i++){
		scanf("%i%i", &f, &s);
		printf("%i\n", qry(1, 1, r, f, s)*(s-f+1));
		update(pn[f], id[s]);
		update(pn[s], id[f]);
		int tmp = id[f];
		id[f] = id[s];
		id[s] = tmp;
	}
	return 0;
}