#include <cstdio>
#include <vector>
#include <utility>
using namespace std;
int llength=0;
long long int nroutes=0;
bool visited[400050];
vector<int> edges[400050];
pair<int, long long int> nmaxp(int cst){
	visited[cst]=1;
	int cmpath=0; long long int nmpaths=1;
	pair<int, long long int> tpa;
	for(int i=0; i<edges[cst].size(); i++){
		if (visited[edges[cst][i]]) continue;
		tpa=nmaxp(edges[cst][i]);
		if (tpa.first+cmpath +1> llength){
			llength=tpa.first+cmpath+1;
			nroutes=nmpaths*tpa.second;
		}
		else if (tpa.first+cmpath+1==llength){
			nroutes+=nmpaths*tpa.second;
		}
		if (tpa.first>cmpath){
			cmpath=tpa.first; nmpaths=tpa.second;
		}
		else if (tpa.first==cmpath){
			nmpaths+=tpa.second;
		}
	}
	return make_pair(cmpath+1, nmpaths);
}
	
	

int main() {
	int n, ta, tb;
	scanf("%i", &n);
	for(int i=1; i<n; i++){
		scanf("%i%i", &ta, &tb);
		edges[ta].push_back(tb);
		edges[tb].push_back(ta);
	}
	nmaxp(1);
	printf("%i %lli", llength, nroutes);
	
	return 0;
}