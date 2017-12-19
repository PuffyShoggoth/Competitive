#include <cstdio>
using namespace std;
int sgtree[2100000];
int pos[1050000];
int sit[1050000];
int win[1050000];
void build(int s, int e, int ind){
	if (s==e){
		sgtree[ind]=s;
		sit[s]=ind;
	}
	else{
		int ta=ind<<1, tb;
		tb=ta+1;
		build(s, (s+e)>>1, ta);
		build(((s+e)>>1)+1, e, tb);
		if (pos[sgtree[ta]]>pos[sgtree[tb]]){
			sgtree[ind]=sgtree[ta];
			win[sgtree[ta]]+=1;}
		else{
			sgtree[ind]=sgtree[tb];
			win[sgtree[tb]]+=1;
		}
	}
	return;
}
void updatesg(int cpos, int nw){
	int wn=1, tpts, ta, tb;
	pos[cpos]=nw; tpts=sit[cpos]>>1;
	for(int i=tpts; i>0; i=(i>>1)){
		ta=sgtree[i<<1]; tb=sgtree[(i<<1)+1];
		if (pos[ta]>pos[tb]){
			sgtree[i]=ta; win[ta]=wn; win[tb]=wn-1;
		}
		else{
			sgtree[i]=tb; win[tb]=wn; win[ta]=wn-1;
		}
		wn+=1;
	}
	return;
}
int main(){
	int n, m, tp, ti, ts;
	char ctp;
	scanf("%i%i", &n, &m);
	tp=1<<n;
	for(int i=1; i<=tp; i++){
		scanf("%i", &pos[i]);
	}
	build(1, tp, 1);
	for(int i=0; i<m; i++){
		do{ctp=getchar();} while(ctp<'R' || ctp>'W');
		switch(ctp){
			case 'R':
				scanf("%i%i", &ti, &ts);
				updatesg(ti, ts);
				break;
			case 'S':
				scanf("%i", &ti);
				printf("%i\n", win[ti]);
				break;
			case 'W':
				printf("%i\n", sgtree[1]);
				break;
		}
	}
	return 0;
}