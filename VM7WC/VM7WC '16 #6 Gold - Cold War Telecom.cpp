#include <cstdio>
#include <vector>
#include <algorithm>
#define min(a,b) ((a<b)?a:b)
using namespace std;
int dfsl[100005], dfsu[100005], dfscnt=1;
vector<int> edges[100005];
vector<int> apoint;

void artic(int cn, int par){
	dfsl[cn]=dfscnt; dfsu[cn]=dfscnt;
	dfscnt++; int pcnt=0, nleaf=0; bool at=0;
	for(int i=0; i<edges[cn].size(); i++){
		int tmp=edges[cn][i];
		if (tmp==par) continue;
		if (!dfsu[tmp]){
			artic(tmp, cn);
			if (dfsu[cn]<=dfsl[tmp]) {at=1;}
			dfsl[cn]=min(dfsl[cn], dfsl[tmp]);
			pcnt++;
		}
		else{
			dfsl[cn]=min(dfsl[cn], dfsu[tmp]);
		}
	}
	if (cn==1){
		if (pcnt>1) apoint.push_back(cn);
	}
	else if (at){
		apoint.push_back(cn);
	}
	return;
}
int main() {
	int n, m, a, b;
	scanf("%i%i", &n, &m);
	for(int i=0; i<m; i++){
		scanf("%i%i", &a, &b);
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	artic(1, 0);
	sort(apoint.begin(), apoint.end());
	printf("%i\n", apoint.size());
	for(int i=0; i<apoint.size(); i++){
		printf("%i\n", apoint[i]);
	}
	return 0;
}