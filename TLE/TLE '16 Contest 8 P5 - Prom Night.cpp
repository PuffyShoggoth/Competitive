#include <bits/stdc++.h>

using namespace std;

int pr[105];
int n, m;
bool dn[105], lk[105];
vector<int> grl[105];
bool hung(int cn){
	if (dn[cn]) return 0;
	dn[cn]=1;
	for(int i:grl[cn]){
		if (pr[i]==0 || hung(pr[i])){
			pr[i] = cn; return 1;
		}
	}
	return 0;
}
int main(){

	scanf("%i%i", &n, &m);
	int t, id;
	scanf("%i", &t);
	for(int j=0; j<t; j++){
		scanf("%i", &id);
		lk[id]=1;
	}
	for(int i=2; i<=n; i++){
		scanf("%i", &t);
		for(int j=0; j<t; j++){
			scanf("%i", &id);
			if (lk[id]){
				grl[i].push_back(id);
			}
		}
	}
	for(int i=2; i<=n; i++){
		memset(dn, 0, sizeof(dn));
		hung(i);
	}
	int sm=0;
	for(int i=1; i<=m; i++){
		if (lk[i] && !pr[i]){sm++; }
	}
	printf("%i", sm);
	return 0;
}