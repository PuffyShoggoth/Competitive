#include <iostream>
#include <cstdio>
#include <utility>
#include <cstring>
using namespace std;
int mlr[1700000];
int glr[1700000];
int qlr[1700000];
int a[100009];
int indx[100009];
int gcd(int a, int b){
	if (b==0){return a;}
	else{return gcd(b, a%b);}
}
int nqlr(int i, int ia, int ib, int va, int vb){
	if (i==ia && ia==ib){return va+vb;}
	else if(i==ia){return va;}
	else if(i==ib){return vb;}
	return 0;
}
void bmlr(int s, int e, int cn){
	if (s==e){
		mlr[cn]=a[s];
		indx[s]=cn;
		glr[cn]=a[s];
		qlr[cn]=1;
	}
	else{
		bmlr(s, ((e+s)>>1), cn<<1);
		bmlr(1+((e+s)>>1), e, 1+(cn<<1));
		mlr[cn]=min(mlr[cn<<1], mlr[1+(cn<<1)]);
		glr[cn]=gcd(max(glr[cn<<1], glr[1+(cn<<1)]), min(glr[cn<<1], glr[1+(cn<<1)]));
		qlr[cn]=nqlr(glr[cn], glr[cn<<1], glr[1+(cn<<1)], qlr[cn<<1], qlr[1+(cn<<1)]);
	}
	return;
}

void update(int i){
	if (i==0){return;}
	else{
		mlr[i]=min(mlr[i<<1], mlr[1+(i<<1)]);
		glr[i]=gcd(max(glr[i<<1], glr[1+(i<<1)]), min(glr[i<<1], glr[1+(i<<1)]));
		qlr[i]=nqlr(glr[i], glr[i<<1], glr[1+(i<<1)], qlr[i<<1], qlr[1+(i<<1)]);
		update(i>>1);
	}
}
pair<int, int> fgcd(int st, int ed, int cns, int cne, int cn){
	pair <int, int> tpa, tpb;
	int tgcd;
	if (st<=cns && ed>=cne){return make_pair(glr[cn], qlr[cn]);}
	if (st<=((cns+cne)>>1)){
		tpa=fgcd(st, ed, cns, (cns+cne)>>1, cn<<1);
		if (ed>((cns+cne)>>1)){
			tpb=fgcd(st, ed, 1+((cns+cne)>>1), cne, 1+(cn<<1));
			tgcd=gcd(max(tpa.first, tpb.first), min(tpa.first, tpb.first));
			return make_pair(tgcd, nqlr(tgcd, tpa.first, tpb.first, tpa.second, tpb.second));
		}
		else{return tpa;}
	}
	else {return fgcd(st, ed, 1+((cns+cne)>>1), cne, 1+(cn<<1));}
}
int rmq(int st, int ed, int cns, int cne, int cn){
	int tpa, tpb;
	if (st<=cns && ed>=cne){return mlr[cn];}
	if (st<=((cns+cne)>>1)){
		tpa=rmq(st, ed, cns, (cns+cne)>>1, cn<<1);
		if (ed>((cns+cne)>>1)){
			tpb=rmq(st, ed, 1+((cns+cne)>>1), cne, 1+(cn<<1));
			return min(tpb, tpa);
		}
		else{return tpa;}
	}
	else {return rmq(st, ed, 1+((cns+cne)>>1), cne, 1+(cn<<1));}
}
int main() {
	int n, m, tr, tl;
	char x;
	scanf("%i%i", &n, &m);
	for(int i=1; i<=n; i++){
		scanf("%i", &a[i]);
	}
	bmlr(1, n, 1);
	for(int i=0; i<m; i++){
		do{x=getchar();}while(x<=' ');
		scanf("%i%i", &tr, &tl);
		switch(x){
			case 'C':
				mlr[indx[tr]]=tl; glr[indx[tr]]=tl;
				update(indx[tr]>>1);
				break;
			case 'M':
				printf("%i\n", rmq(tr, tl, 1, n, 1));
				break;
			case 'G':
				printf("%i\n", fgcd(tr, tl, 1, n, 1).first);
				break;
			case 'Q':
				printf("%i\n", fgcd(tr, tl, 1, n, 1).second);
				break;
		}
	}
	return 0;
}