#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
pair<int, int> dirs[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
map<long long int, int> hashs;
long long int seed = 131;
long long int MOD = 805306457;
int main() {
	int n;
	scanf("%i", &n);
	int tmx = 0;
	for(int i = 1; i<=n; i++){
		string s;
		cin>>s;
		long long int stv = 0, edv = 0;
		int mxpv = 1;
		long long int pw= 1;
		for(int j = 0; j<s.size(); j++){
			stv= (stv*seed+(s[j]));
			edv = (edv+(s[s.size()-j-1])*pw);
			pw = (pw*seed);

			if(stv==edv && hashs.count(stv)){
				mxpv = max(mxpv, hashs[stv]+1);
			}
		}
		tmx = max(tmx, mxpv);
		hashs[stv]=mxpv;
	}
	printf("%i", tmx);
    return 0;
}