#include <cstdio>
#include <set>
#include <vector>
#define MOD 1000000007
#define min(a,b) ((a<b)?a:b)
#define max(a,b) ((a>b)?a:b)
using namespace std;
int val[500005];
int pval[500005];
int dfsl[500005];
int dfsv[500005];
bool vst[500005];
int grp[500005];
set<int> pedges[500005];
vector<int> edges[500005];
int dfsn=1, ctn=1, pvn=-1, n, pvf=-1;
vector<int> stack;
void ccc(int cn){
	int tmpa, tmp=dfsn; dfsv[cn]=dfsn; dfsn++;
	stack.push_back(cn);
	for(int i=0; i<edges[cn].size(); i++){
		tmpa=edges[cn][i];
		if (vst[tmpa]) continue;
		if (!dfsv[tmpa]){
			ccc(tmpa);
			tmp=min(tmp, dfsl[tmpa]);
		}
		else{
			tmp=min(tmp, dfsv[tmpa]);
		}
	}
	dfsl[cn]=tmp;
	if (dfsv[cn]==tmp){
		int tpcn=0;
		while(tpcn!=cn){
			tpcn=stack.back();
			stack.pop_back();
			vst[tpcn]=1;
			grp[tpcn]=ctn;
			pval[ctn]+=val[tpcn];
			if (tpcn==n) {
				pvn=ctn;
			}
			if (tpcn==1){
				pvf=ctn;
			}
		}
		ctn++;
	}
	return;
}
int dp[500005][2];
int nmv[500005][2];
bool dn[500005];
void fmp(int cn){
	dn[cn]=1;
	if (cn==pvn) {
		dp[cn][1]=pval[cn];
		nmv[cn][1]=1; nmv[cn][0]=1;
		return;
	}
	for(set<int>::iterator it=pedges[cn].begin(); it!=pedges[cn].end(); ++it){
		if (!dn[*it]) fmp(*it);
		if (!nmv[*it][0]) continue;
		if (dp[*it][1]>dp[cn][0]){
			dp[cn][0]=dp[*it][1]; nmv[cn][0]=nmv[*it][1];
		}
		else if (dp[*it][1] == dp[cn][0]){
			nmv[cn][0]= (nmv[cn][0]+nmv[*it][1])%MOD;
		}
		if (dp[*it][0] + pval[cn] >dp[cn][1]){
			dp[cn][1]=dp[*it][0]+pval[cn]; nmv[cn][1] = nmv[*it][0];
		}
		else if (dp[*it][0]+pval[cn] == dp[cn][1]){
			nmv[cn][1]= (nmv[*it][0]+nmv[cn][1])%MOD;
		}
		if (dp[*it][0] >dp[cn][0]){
			dp[cn][0] = dp[*it][0]; nmv[cn][0]=nmv[*it][0];
		}
		else if (dp[*it][0] == dp[cn][0]) {
			nmv[cn][0]= (nmv[*it][0]+nmv[cn][0])%MOD;
		}
	
	}
	return;
}
	
	

int main() {
	int m, a, b;
	scanf("%i%i", &n, &m);
	for(int i=1; i<=n; i++){
		scanf("%i", &val[i]);
	}
	for(int i=0; i<m; i++){
		scanf("%i%i", &a, &b);
		edges[a].push_back(b);
	}
	ccc(1);
	for(int i=1; i<=n; i++){
		if (!grp[i]) continue;
		for(int j=0; j<edges[i].size(); j++){
			if (grp[edges[i][j]] && (grp[edges[i][j]]!=grp[i])){
				pedges[grp[i]].insert(grp[edges[i][j]]);
			}
		}
	}
	fmp(pvf);
	if (dp[pvf][0]>dp[pvf][1]){
		printf("%i %i", dp[pvf][0], nmv[pvf][0]);
	}
	else if (dp[pvf][0]<dp[pvf][1]){
		printf("%i %i", dp[pvf][1], nmv[pvf][1]);
	}
	else{
		printf("%i %i", dp[pvf][0], (nmv[pvf][1]+nmv[pvf][0])%MOD);
	}
	return 0;
}