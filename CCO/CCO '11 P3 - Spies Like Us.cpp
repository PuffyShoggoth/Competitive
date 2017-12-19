#include <bits/stdc++.h>
using namespace std;

bitset<2005> adj[2005];
vector<int> edges[2005];
bitset<2005> tpbset, tpbset2; 
int main(){
	int n, m, k;
	scanf("%i%i%i", &n, &m, &k);
	int tpn, tpm;
	for(int i=0; i<k; i++){
		scanf("%i%i", &tpn, &tpm);
		edges[tpn].push_back(tpm);
		adj[tpm][tpn]=1;
	}
	bool pos = 1;
	for(int i=1; i<=n; i++){
		tpbset.reset();
		for(int j:edges[i]){
			tpbset2 = adj[j]&tpbset;
			if (tpbset2.count() > 1){ pos = 0; break; }
			tpbset |= adj[j];
		}
		if (!pos){ break;}
	}
	if (pos) printf("YES"); 
	else printf("NO");
	return 0;
}