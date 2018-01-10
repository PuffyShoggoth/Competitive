#include <bits/stdc++.h>
using namespace std;
struct node{
	int par, l, r, vl, ch, p;
	node():ch(1),p(rand()){};
	void clear(){par=0; l=0; r=0; ch = 1; p = rand();}
} treap[100005];
int dsj[100005];
int rnk[100005];
int rt[100005];
int root(int cn){
	while(dsj[cn]) cn=dsj[cn];
	return cn;
}
void rot(int cn, int par){
	if(treap[par].l==cn){
		treap[par].l=treap[cn].r;
		treap[treap[cn].r].par=par;
		treap[cn].r=par;
	}
	else{
		treap[par].r=treap[cn].l;
		treap[treap[cn].l].par=par;
		treap[cn].l=par;
	}
	treap[cn].par=treap[par].par;
	if(treap[par].vl<treap[treap[par].par].vl){
		treap[treap[par].par].l=cn;
	}
	else{
		treap[treap[par].par].r=cn;
	}
	treap[par].par=cn;
	treap[par].ch=treap[treap[par].l].ch+treap[treap[par].r].ch+1;
	treap[cn].ch = treap[treap[cn].l].ch+treap[treap[cn].r].ch+1;
}
void insert(int cn, int ti, int rti){
	treap[cn].ch+=1;
	if(treap[cn].vl<treap[ti].vl){
		if(treap[cn].r){ insert(treap[cn].r, ti, rti); }
		else{
			treap[cn].r=ti;
			treap[ti].clear();
			treap[ti].par=cn;
			while(treap[ti].par && treap[treap[ti].par].p<treap[ti].p){
				rot(ti, treap[ti].par);
				if(!treap[ti].par){rt[rti]=ti;}
			}
			return;
		}
	}
	else{
		if(treap[cn].l){ insert(treap[cn].l, ti, rti); }
		else{
			treap[cn].l=ti;
			treap[ti].clear();
			treap[ti].par=cn;
			while(treap[ti].par && treap[treap[ti].par].p<treap[ti].p){
				rot(ti, treap[ti].par);
				if(!treap[ti].par){rt[rti]=ti;}
			}
			return;
		}
	}
}
int mdsj(int a, int b){
	if (rnk[a]>rnk[b]){
		dsj[b]=a;
		return a;
	}
	else if (rnk[a]==rnk[b]){
		dsj[b]=a;
		rnk[a]++;
		return a;
	}
	else{
		dsj[a]=b;
		return b;
	}
}
void insall(int cn, int ind){
	if(cn){
		insall(treap[cn].l, ind);
		insall(treap[cn].r, ind);
		insert(rt[ind], cn, ind);
	}
}
void merge(int a, int b){
	a = root(a); b = root(b);
	if (a==b) return;
	if(treap[rt[a]].ch<treap[rt[b]].ch){
		int tp = a; a = b; b = tp;
	}
	int fd=mdsj(a,b);
	int rb=rt[b];
	rt[fd]=rt[a];
	insall(rb, fd);

}
int search(int cn, int k){
	if(treap[cn].l && treap[treap[cn].l].ch>=k){
		return search(treap[cn].l, k);
	}
	else{
		k-=treap[treap[cn].l].ch;
		if(k==1){
			return cn;
		}
		else{
			return search(treap[cn].r, k-1);
		}
	}
}
int qry(int k, int id){
	id = root(id);

	if(k>treap[rt[id]].ch){
		return -1;}
	else{
		return search(rt[id], k);
	}
}
int main(){
	int n, m;
	scanf("%i%i", &n, &m);
	treap[0].ch=0;
	for(int i=1; i<=n; i++){
		scanf("%i", &treap[i].vl);
		rt[i]=i;
	}
	int x, v;
	for(int i=0; i<m; i++){
		scanf("%i%i", &x, &v);
		merge(x, v);
	}
	int q;
	scanf("%i", &q);
	for(int i=0; i<q; i++){
		char c;
		do{c = getchar();}while(c!='Q' && c!='B');
		scanf("%i%i", &x, &v);
		if(c=='Q'){
			printf("%i\n", qry(v, x));
		}
		else{
			merge(x,v);
		}
	}
}