#include <bits/stdc++.h>
using namespace std;

int cnt;
typedef struct _node{
	int p, nm, nch;
	long long int vl, vch;
	_node *l, *r;
	~_node(){ delete l; delete r;}
	_node(long long int _vl, int _nm):vl(_vl), nm(_nm),p(rand()),nch(_nm),vch(_nm*_vl),l(0),r(0){}
	void calc(){
		nch = nm;
		vch = vl*nm;
		if(l){nch+=l->nch; vch+=l->vch;}
		if(r){nch+=r->nch; vch+=r->vch;}
	}

} *Node;

Node root=0;
long long int ofst;

Node merge(Node a, Node b){

	
	if(!a || !b){ return a?a:b;}
	if(a->p > b->p){
		a->r = merge(a->r, b);
		a->calc();
		return a;
	}
	else{
		b->l = merge(a, b->l);
		b->calc();
		return b;
	}
}
void split(Node cn, long long int vl, Node &l, Node&r){
	l = r = 0;
	if(!cn) {return;}
	if(vl>cn->vl+ofst){
		split(cn->r, vl, cn->r, r);
		l=cn;
	}
	else{
		split(cn->l, vl, l, cn->l);
		r=cn;
	}
	cn->calc();
}
long long int mxvl;
long long int greq(Node cn, int rq){
	if(rq==0 || cn==0){return 0;}
	if(cn->l && cn->l->nch>=rq){
		return greq(cn->l, rq);
	}
	else{
		long long int fvl = 0;
		mxvl = max(mxvl, cn->vl+ofst);
		if(cn->l){rq-=cn->l->nch; fvl+=cn->l->vch+ofst*(cn->l->nch); }
		if(rq<=cn->nm){
			return fvl+rq*(cn->vl+ofst);
		}
		else{
			return greq(cn->r, rq-cn->nm)+fvl+(cn->nm)*(cn->vl+ofst);
		}
	}
}
int main(){
	int n;
	long long int k;
	srand(9291);
	scanf("%i%lli", &n, &k);
	int cr;
	long long int tv;
	int nmo = 0;
	fstream otf;
	for(int i=1; i<=n; i++){
		scanf("%i", &cr);
		if(nmo>=cr-1){
			nmo = 0;
			printf("%lli\n", k);
			ofst = 0;
			if (i==1){root = new _node(k, 1);}
			else{ root = merge(new _node(0, i-1), new _node(k, 1));}
			continue;
		}
		Node l=0,r=0; cnt=0;
		mxvl = -ofst-1;
		tv = greq(root, cr-1-nmo);
		if (tv+cr-1-nmo>k){
			nmo++;
			printf("-1\n");
		}
		else{
			
			printf("%lli\n", k-tv-cr+1+nmo);
			split(root,mxvl, l, r);
			root = merge(l, new _node(mxvl-ofst, cr-1-nmo-(l?l->nch:0)));
			l=0; r=0;
			ofst++;
			split(root, k-tv-cr+1+nmo, l, r);
			root = merge(merge(l, new _node(k-tv-cr+1+nmo-ofst, 1)), r);

			split(root, 0, l, r);
			Node newnode = new _node(-ofst, i-cr+nmo);
			l=merge(l, newnode);
			root = merge(l, r);
			nmo = 0;

		}
	}
}