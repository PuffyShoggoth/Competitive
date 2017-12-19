#include <bits/stdc++.h>
using namespace std;

unordered_map<long long int, pair<int, int> > dp;
inline long long int hsh(long long int n, long long int m){
	return min(n,m)*1e9+max(n,m);
}
void gtvl(int n, int m){
	long long int hs;
	hs = max(n, m);
	m = min(n,m);
	n = hs;
	hs = hsh(n, m);
	int mn=100000000, mx=0;

	pair<int, int> tp;
	if (m==1){

		if(!(n%2)){ mn =n/2; mx=n/2;}
		else {mn=100000000; mx=0;}
	}
	else if (m<=0) {  printf("%i\n", n); mn=100000000; mx=0; }
	else if (m%2 && n%2){  mn=100000000; mx=0;}
	else if (dp.count(hs)){
//		printf("%i %i\n%lli %i\n", n, m, hs, dp[hs]);
		return;
	}
//	printf("%i %i\n", n, m);
	else if(n==m*2){
		mn=1; mx=1;
		if(!(m%2)){
			gtvl(n-m/2, m);
			tp = dp[hsh(n-m/2, m)];
			if (tp.second){ mx = tp.second+1; }
		}
		
	}
	else if (n>m*2) {
		if (!(n%(m*2))) {
			mn = n/(m*2);
			mx = mn;
		}
		else {
			gtvl(m, n%(m*2));
			tp = dp[hsh(m, n%(m*2))];
			if (tp.second){
				mn = n/(m*2) + tp.first; mx=n/(m*2) + tp.second;
			}
		}
		if (!(m%2)){
			int sm = ceil((n%(m*2))/((double)(m/2)));
			gtvl(m, m*2 + (n%(m*2)) - sm*(m/2));
			tp = dp[hsh(m, m*2 + (n%(m*2)) - sm*(m/2))];
			if (tp.second){
			//	printf("%i %i %i %i\n", mx, 4*(n/(m*2)-1),tp.second, sm);
				mn = min(mn, n/(m*2) - 1 + tp.first + sm);
				mx = max(mx, 4*(n/(m*2))-4+tp.second+sm);
			}
		}
	//	dp.insert({hs, {mn, mx}});
	//	return {mn, mx};
	}
	else{
		if (!(m%2)) {
			gtvl(n-m/2, m);
			tp = dp[hsh(n-m/2, m)];
			if (tp.second){
				mn = tp.first + 1; mx = tp.second+1;
			}
		}
		if (!(n%2)){
			gtvl(n, m-n/2);
			tp = dp[hsh(n, m-n/2)];
			if (tp.second){
				mn = min(mn, tp.first+1); mx = max(mx, tp.second+1);
			}
		}
	//	dp.insert({hs, {mn, mx}});
	//	return {mn, mx};
	}
	dp.insert({hs, {mn, mx}});
//	printf("%i %i %i %i\n", n, m, mn, mx);
	return;

}

int main(){
	int n, m;
	scanf("%i%i", &n, &m);
	gtvl(n,m);
	pair<int, int> tp = dp[hsh(n,m)];
	printf("%i %i", tp.first, tp.second);

	return 0;
}