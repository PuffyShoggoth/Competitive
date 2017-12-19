#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int> > pnta, pntb;
vector<pair<int, int> > anga, angb;
int cprod(pair<int, int> a, pair<int, int> b, pair<int, int> m){
	return (a.first-m.first)*(b.second-m.second) - (a.second-m.second)*(b.first-m.first);
}
int dprod(pair<int,int> a, pair<int, int> b, pair<int, int> m){
	return (a.first-m.first)*(b.first-m.first) + (a.second-m.second)*(b.second-m.second);
}
int gcd(int a, int b){
	if (b==0) return a;
	return gcd(b, a%b);
}
bool eqp(pair<int, int> a, pair<int, int> b, int gca, int gcb){
	return a.first/gca == b.first/gcb && a.second/gca == b.second/gcb;
}
int dst(pair<int, int> a, pair<int, int> b){
	return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
}
int pa[500005];
int main(){
	int dnr;
	scanf("%i", &dnr);
	while(dnr--){
		int n, x, y, tpd, tpc, gca=-1, gcb=-1, tpg;
		int gd = -1;
		scanf("%i", &n);
		pnta.clear(); pntb.clear(); anga.clear(); angb.clear(); 
		memset(pa, 0, sizeof(pa));
		for(int i=0; i<n; i++){
			scanf("%i %i", &x, &y);
			pnta.push_back({x,y});
		}
		for(int i=0; i<n; i++){
			tpc = cprod(pnta[i], pnta[(i+2)%n], pnta[(i+1)%n]);
			tpd = dprod(pnta[i], pnta[(i+2)%n], pnta[(i+1)%n]);
			tpg = dst(pnta[i], pnta[(i+1)%n]);
			if (gca <0){ gca = tpg; }
			else{ gca = gcd(max(gca, tpg), min(gca, tpg)); }
			anga.push_back({tpc, tpd});
		}
		pa[0]=-1; int i=0, j=-1;
		while(i<n){
			while(j>=0 && eqp(anga[i],anga[j], gca, gca)!=1){j = pa[j]; }
			i++; j++; pa[i] = j;
		}
		for(int i=0; i<n; i++){
			scanf("%i %i", &x, &y);
			pntb.push_back({x,y});
		}
		for(int i=0; i<n; i++){
			tpc = cprod(pntb[i], pntb[(i+2)%n], pntb[(i+1)%n]);
			tpd = dprod(pntb[i], pntb[(i+2)%n], pntb[(i+1)%n]);
			angb.push_back({tpc, tpd});
			tpg = dst(pntb[i], pntb[(i+1)%n]);
			if (gcb <0){ gcb = tpg; }
			else{ gcb = gcd(max(gcb, tpg), min(gcb, tpg)); }
		}
		i=0; j=0;
		int mtch = -1;
		while(i-j<=n){
			while(j>=0 && eqp(anga[j], angb[(i%n)], gca, gcb)!=1){ j = pa[j]; }
			i++; j++; 
			if (j==n){mtch = i-j; break;}
		}
		mtch++; printf("%i\n", mtch);
	}
	return 0;

}