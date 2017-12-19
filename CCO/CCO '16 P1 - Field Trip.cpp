#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int edges[1000010][2];
bool dn[1000010];
int sz;
bool cyc(int cn, int par){
	if (dn[cn]) return 1;
	dn[cn]=1;
	sz++;
	bool iscyc=0;
	for(int i=0; i<2; i++){
		if (edges[cn][i]!=par && edges[cn][i]) iscyc=cyc(edges[cn][i], cn);
		if (iscyc){ return 1;}
	}
	return iscyc;
}
int main(){
	int a, b, tt=0, mn=0;
	scanf("%i%i%i", &n, &m, &k);
	for(int i=0; i<m; i++){
		scanf("%i%i", &a, &b);
		if (edges[a][0]){
			edges[a][1]=b;
		}
		else{edges[a][0]=b;}
		if (edges[b][0]){
			edges[b][1]=a;
		}
		else{edges[b][0]=a;}
	}
	bool tmp;
	for(int i=1; i<=n; i++){
		if (dn[i]) continue;
		sz=0;
		tmp = cyc(i, 0);
		tt+= (sz/k)*k;
		if (sz <= k) continue;
		if (tmp){
			if (sz%k){
				mn+=sz/k + 1;
			}
			else{
				mn+=sz/k;
			}
		}
		else{
			if (sz%k){
				mn+=sz/k;
			}
			else {
				mn+=sz/k -1;
			}
		}
	}
	printf("%i %i", tt, mn); 
}