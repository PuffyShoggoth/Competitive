#include <cstdio>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;
bool found[5764900];
int pw[8][8];
int tmp[7];
queue<pair<int, int> > thq;
int main() {
	for(int i=1; i<8; i++){
		pw[i][0]=1;
		for(int j=1; j<=i; j++){
			pw[i][j]=pw[i][j-1]*i;
		}
	}
	int n, ta, tb, fpos;
	pair<int, int> tpr;
	bool crdfound;
	scanf("%i", &n);
	while(n){
		memset(found, 0, pw[n][n]);
		crdfound=0; fpos=0; tb=0;
		for(int i=0; i<n; i++){
			fpos+=pw[n][i]*i;
		}
		for(int i=0; i<n; i++){
			scanf("%i", &ta);
			tb+=pw[n][ta-1]*i;
		}
		thq.push(make_pair(tb, 0));
		while(!thq.empty()){
			tpr=thq.front();
			tb=tpr.first;
			thq.pop();
			if(found[tb]){continue;}
			found[tb]=1;
			if(tb==fpos){
				crdfound=1;
				printf("%i\n", tpr.second);
				while(!thq.empty()){thq.pop();}
				break;
			}
			memset(tmp, n, n*4);
			for(int i=n-1; i>=0; i--){
				tmp[tb/pw[n][i]]=i;
				tb=tb%pw[n][i];
			}
			tb=tpr.first; ta=tpr.second+1;
			if (tmp[0]<tmp[1]){thq.push(make_pair(tb+pw[n][tmp[0]], ta));}
			if (tmp[n-1]<tmp[n-2]){thq.push(make_pair(tb-pw[n][tmp[n-1]], ta));}
			for(int i=1; i<n-1; i++){
				if (tmp[i]<tmp[i-1]){thq.push(make_pair((tb-pw[n][tmp[i]]), ta));}
				if (tmp[i]<tmp[i+1]){thq.push(make_pair((tb+pw[n][tmp[i]]), ta));}
			}
			
		}
		if(!crdfound){printf("IMPOSSIBLE\n");}
		scanf("%i", &n);
	}
	return 0;
}