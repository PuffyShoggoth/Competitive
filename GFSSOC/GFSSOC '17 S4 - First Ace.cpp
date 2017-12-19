#include <cstdio>
#include <vector>
#include <utility>
using namespace std;
int dp[1005];
vector<pair<int, int> > stu[1005];
int main() {
	int n, v, s, t, vl=0;
	//melted chedder is good on buns
	scanf("%i", &n);
	for(int i=0; i<n; i++){
		scanf("%i%i%i", &v, &s, &t);
		stu[t].push_back({s, v});
	}
	for(int i=1; i<=1000; i++){
		dp[i]=dp[i-1];
		for(pair<int, int> tp: stu[i]){
			for(int j=i; j>=tp.first; j--){
				dp[j]=(dp[j]<dp[j-tp.first]+tp.second)?(dp[j-tp.first]+tp.second):dp[j];
			}
		}
	}
	printf("%i", dp[1000]);
	return 0;
}