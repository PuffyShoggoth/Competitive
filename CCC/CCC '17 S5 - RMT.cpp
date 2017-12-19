#include <bits/stdc++.h>
using namespace std;
vector<int> lines[150005];
int ind[150005];
int cnt[150005];
int sblock[405];
int lblock[150005][405];
int nps[150005];
int mbln[150005];
using namespace std;
int main(){
	int n, m, q, sqt, tp, d, l, r, x;
	scanf("%i%i%i", &n, &m, &q);
	sqt=sqrt(n);
	memset(lblock, -1, sizeof(lblock));
	for(int i=0; i<n; i++){
		scanf("%i", &tp);
		mbln[i]=tp;
		ind[i] = lines[tp].size();
		lblock[tp][i/sqt] = ind[i];
		lines[tp].push_back(i);
	}
	for(int i=0; i<n; i++){
		scanf("%i", &nps[i]);
		sblock[i/sqt]+=nps[i];
	}
	
	for(int i=0; i<q; i++){
		scanf("%i", &d);
		if (d==1){
			scanf("%i%i", &l, &r);
			l--; r--;
			int sm=0;
			for(int j=l/sqt; j<r/sqt; j++){
				sm+=sblock[j];
			}
			for(int j= floor(l/sqt)*sqt; j<l; j++){
				tp=mbln[j];
				sm-=nps[lines[tp][(ind[j]-cnt[tp]+lines[tp].size())%lines[tp].size()]];
			}
			for(int j=floor(r/sqt)*sqt; j<=r; j++){
				tp=mbln[j];
				sm+=nps[lines[tp][(ind[j]-cnt[tp]+lines[tp].size())%lines[tp].size()]];
			}
			printf("%i\n", sm);
		}
		else{
			scanf("%i", &x);
			int fb, pv; fb = -1; pv=0;
			for(int j=0; j<=sqt+1; j++){
				if (lblock[x][j]<0){ continue; }
				if (fb==-1){ fb = j; }
				sblock[j]+=pv;
				pv=nps[lines[x][(lblock[x][j]-cnt[x]+lines[x].size())%lines[x].size()]];
				sblock[j]-=pv;
				
			}
			if (fb>-1){sblock[fb]+=pv; }
			for(int j=0; j<=sqt+1; j++){
				if (lblock[x][j]<0){continue; }
			}
			cnt[x] = (cnt[x]+1)%lines[x].size();
		}
	}


}