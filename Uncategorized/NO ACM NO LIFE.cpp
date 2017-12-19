#include <bits/stdc++.h>
using namespace std;

vector<int> edges[305];

int lbl[305];
int dist[305][305];
int sz[305][305];
double fct[305];
double nck[305][305];
void gdst(int cn, int par, int st, int dst, map<int, int> & lb){
	dist[st][cn]=dst;
	lb[lbl[cn]]++;
	sz[st][cn]=lb.size();
	for(int i: edges[cn]){
		if (i!=par) gdst(i, cn, st, dst+1, lb);
	}
	lb[lbl[cn]]--;
	if (!lb[lbl[cn]]){
		lb.erase(lbl[cn]);
	}
	return;
}
int gcm(int cn, int par, int st, int dst){
	if (dist[st][cn]>dist[st][dst] ||  dist[dst][cn]>dist[st][dst]) { return 0; }
	if(dist[st][dst]==dist[st][cn]){
		if (cn>=dst) return 1;
		else return 0;
	}
	else if (dist[st][dst]==dist[dst][cn] && cn!=st){
		if(cn>st) return 1;
		else return 0;
	}
	int tt = 1;
	for(int i: edges[cn]){
		if (i!= par) tt+=gcm(i, cn, st, dst);
	}
	return tt;
}
int main(){
	int t;
	scanf("%i", &t);
	nck[0][0]=1;
	for(int i=1; i<=300; i++){
		double t2=1;
		nck[i][0]=1;
		for(int j=1; j<=i/2+1; j++){
			nck[i][j] = i*nck[i-1][j-1]/j;
		}
		for(int j=i; j>=i/2+1; j--){
			nck[i][j]=nck[i][i-j];
		}
	}
	while(t--){
		int n, k;
		scanf("%i%i", &n, &k);
		memset(lbl, 0, sizeof(lbl));
		for(int i=1; i<=n; i++){edges[i].clear();}
		int tpfct = 1, tpkfct=1, kfct=1;
		for(int i=1; i<n; i++){
			int a, b;
			scanf("%i%i", &a, &b);
			edges[a].push_back(b);
			edges[b].push_back(a);
		}
		for(int i=1; i<=n; i++){
			scanf("%i", &lbl[i]);
		}
		for(int i=1; i<=n; i++){
			map<int, int> mp;
			gdst(i, 0, i, 0, mp);
		}
		double tt=0;
		for(int i=1; i<n; i++){
			for(int j=i+1; j<=n; j++){
				int lt = gcm(i, 0, i, j);
				tt+=nck[lt-2][k-2]*sz[i][j]/nck[n][k];
			}
		}
		printf("%f\n", tt);
	}
}