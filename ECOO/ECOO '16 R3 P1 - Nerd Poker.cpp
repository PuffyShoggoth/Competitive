#include <bits/stdc++.h>
using namespace std;
double odds[510];
int main(){
	int t, n;
	double s, nt, cv, pv;
	t = 10;
	while(t--){
		cin>>n>>s;
		memset(odds, 0, sizeof(odds));
		odds[0]=1; nt=0; cv=1; pv=0;
		for(int i=1; i<=500; i++){
			cv*=(s-1)/s; odds[i] = 1 - cv;
		}
		for(int i=1; i<=500; i++){
			cv=1;
			for(int j=0; j<n; j++){  cv*=odds[i]; }
			nt+=i*(cv-pv);
			pv=cv;
		}
		if (nt-floor(nt)<1e-6){ cout<<floor(nt)<<"\n"; }
		else{ cout<<ceil(nt)<<"\n"; }
	}
	return 0;
}