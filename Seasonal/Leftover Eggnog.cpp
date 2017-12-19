#include <cstdio>
#include <utility>
#include <string>
#include <vector>
#include <queue>
#define mp(a,b) make_pair(a,b)
using namespace std;
pair<int, int> pva[1001][1001];
bool vst[1001][1001];
queue <pair<pair<int, int>, pair<int, int> > >nxt;
vector<string> res;
int main() {
	int m, a, b, af, as; bool dn=0;
	pair<int, int> tpf, tps, ans;
	scanf("%i%i%i", &a, &b, &m);
	if (m>a && m>b) {printf("Not possible\n");}
	else{
	nxt.push(mp(mp(a, 0), mp(0, 0))); nxt.push(mp(mp(0, b), mp(0, 0))); 
	vst[0][0]=1; 
	while(!nxt.empty()){
		tpf=nxt.front().first; tps=nxt.front().second;
		nxt.pop();
		if (vst[tpf.first][tpf.second]) continue;
		vst[tpf.first][tpf.second]=1;
		pva[tpf.first][tpf.second]=tps;
		if ((tpf.first == m)|| (tpf.second==m)){
			ans=tpf; dn=1; break;
		}
		nxt.push(mp(mp(a, tpf.second), tpf));
		nxt.push(mp(mp(tpf.first, b), tpf));
		nxt.push(mp(mp(0, tpf.second), tpf));
		nxt.push(mp(mp(tpf.first, 0), tpf));
		if (tpf.first+tpf.second <= a) nxt.push(mp(mp(tpf.first+tpf.second, 0), tpf));
		else nxt.push(mp(mp(a, tpf.second-a+tpf.first), tpf));
		if (tpf.first+tpf.second <=b) nxt.push(mp(mp(0, tpf.second+tpf.first), tpf));
		else nxt.push(mp(mp(tpf.first-b+tpf.second, b), tpf));
	}
	if (!dn){printf("Not possible\n");}
	else{
		do{
			af=ans.first; as=ans.second;
			if (pva[af][as].first==af){
				if (as){
					res.push_back("fill B\n");
				}
				else{
					res.push_back("chug B\n");
				}
			}
			else if (pva[af][as].second==as){
				if (af){
					res.push_back("fill A\n");
				}
				else{
					res.push_back("chug A\n");
				}
			}
			else{
				if (pva[af][as].first<af){
					res.push_back("pour B A\n");
				}
				else{
					res.push_back("pour A B\n");
				}
			}
			ans=pva[af][as];
		}
		while (ans.first || ans.second);
		for(auto it = res.rbegin(); it!=res.rend(); ++it){
			printf("%s", it->c_str());
		}
	}
	}
	return 0;
}