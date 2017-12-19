#include <bits/stdc++.h>
using namespace std;
vector<long long int> planets[2005];
long long int nv[12];
int n;
long long int vl(int x){
	long long int tp=0, cvl;
	cvl=1; tp=0;
	for(int i=1; i<=n; i++){
		cvl=cvl*x; tp+=nv[i]*cvl;
	}
	return tp;
}
double dst(double xa, double ya, double xb, double yb){
	return sqrt((xa-xb)*(xa-xb)+(ya-yb)*(ya-yb));
}
int main() {
	int p, v, r, x, y, tpcnt=0;
	scanf("%i%i%i%i", &p, &n, &v, &r);
	for(int i=0; i<p; i++){
		scanf("%i%i", &x, &y);
		planets[x].push_back(y);
	}
	long long int pav;
	long long int tpv;
	for(int i=n; i>0; i--){
		scanf("%lli", &nv[i]);
	}
	pav=vl(v);
	for(int i=0; i<v; i++){
		tpv=vl(i);
		for(int j=0; j<planets[i].size(); j++){
			if (planets[i][j]==tpv || (dst(i, planets[i][j], v, pav)<=r)){ 
				tpcnt+=1;}
		}
	}
	for(int i=v; i <= min(v+r, 2000); i++){
		for(int j=0; j<planets[i].size(); j++){
			if (ceil(dst(i, planets[i][j], v, pav))<= r) tpcnt+=1;
		}
	}
	printf("%i", tpcnt);
	return 0;
}