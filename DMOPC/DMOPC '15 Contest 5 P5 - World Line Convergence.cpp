#include <cstdio>
#include <vector>
#define MOD  1000000007 
using namespace std;
int visited[200005];
int bit[200005];
int ans[200005];
vector<int> ch[200005];
int n;
int sum(int cn){
	int sm=0;
	for(int i=cn; i>0; i-= (i&(-i))){
		sm = (bit[i]+sm)%MOD;
	}
	return sm;
}
void update(int cn, int val){
	if (cn==0) return;
	for(int i=cn; i<=n; i+=(i&(-i))){
		bit[i]=(bit[i]+val)%MOD;
	}
	return;
}
void smch(int cn){
	int old;
	old = sum(visited[cn]);
	for(int i=0; i<ch[cn].size(); i++){
		smch(ch[cn][i]);
	}
	ans[cn]=(sum(visited[cn])+1+MOD-old)%MOD;
	update(visited[cn], ans[cn]);
	return;
}
int main() {
	scanf("%i", &n);
	int par;
	for(int i=1; i<=n; i++){
		scanf("%i", &par);
		ch[par].push_back(i);
	}
	for(int i=1; i<=n; i++){
		scanf("%i", &par);
		visited[par]=i;
	}
	smch(0);
	for(int i=1; i<=n; i++){
		printf("%i ", ans[i]);
	}
	return 0;
}