#include <cstdio>
#include <vector>
#define max(a,b) (a<b?b:a)
using namespace std;
int usaf[500002][2];
int unq[500002];
vector<int> infsp[500002];
void dfs(int cn, int par){
	int tp; usaf[cn][0]=1; usaf[cn][1]=1;
	for(int i=0; i<infsp[cn].size(); i++){
		if (infsp[cn][i]==par) continue;
		tp=infsp[cn][i];
		dfs(tp, cn);
		if (usaf[tp][0]+1>=usaf[cn][0]){
			usaf[cn][1]=usaf[cn][0]; usaf[cn][0]=usaf[tp][0]+1;
		}
		else if (usaf[tp][0]+1>=usaf[cn][1]){
			usaf[cn][1]=usaf[tp][0]+1;
		}
	}
	return;
}
void sm(int cn, int par, int pmx){
	int tp; unq[cn]=max(pmx,usaf[cn][0]);
	for(int i=0; i<infsp[cn].size(); i++){
		tp=infsp[cn][i];
		if (tp==par) continue;
		if (usaf[cn][0]==usaf[tp][0]+1){
			sm(tp, cn, max((pmx+1),(usaf[cn][1]+1)));
		}
		else{
			sm(tp, cn, unq[cn]+1);
		}
	}
	return;
}
int main() {
	int n, u, v;
	scanf("%i", &n);
	for(int i=0; i<n-1; i++){
		scanf("%i%i", &u, &v);
		infsp[u].push_back(v);
		infsp[v].push_back(u);
	}
	dfs(1, 0);
	sm(1, 0, 1);
	for(int i=1; i<=n; i++){
		printf("%i\n", unq[i]);
	}
	return 0;
}