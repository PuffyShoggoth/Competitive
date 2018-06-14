#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
string s;
int dp[1005][1005];
int gmp(int st, int ed){
	if(st==ed){ return 1; }
	if(st>ed){ return 0; }
	if(dp[st][ed]){return dp[st][ed]; }
	dp[st][ed] = max(gmp(st+1, ed), gmp(st, ed-1));
	if(s[st]==s[ed]){
		dp[st][ed] = max(dp[st][ed], 2+gmp(st+1, ed-1));
	}
	return dp[st][ed];
}

int main() {
	for(int dnr = 0; dnr<5; dnr++){
		cin>>s;
		memset(dp, 0, sizeof(dp));
		printf("%i\n", gmp(0, s.length()-1));
	}
    return 0;
}