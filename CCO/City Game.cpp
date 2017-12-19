#include <cstdio>
#include <utility>
#include <cmath>
#include <stack>
#define mp(a,b) make_pair(a,b)
using namespace std;
int cty[1005][1005];
stack<pair<int, int> > stk;
int m, n;
int hst(int cv){
	int tp, mx=0; cty[cv][n]=0;
	stk.push(mp(0, 0));
	for(int i=0; i<=n; i++){
		if (stk.top().first < cty[cv][i]){
			stk.push(mp(cty[cv][i], i));
		}
		else{
			tp = i;
			while(stk.top().first > cty[cv][i]){
				mx=max(mx, stk.top().first*(i-stk.top().second));
				tp=stk.top().second;
				stk.pop();
			}
			if (stk.top().first!=cty[cv][i]) stk.push(mp(cty[cv][i], tp));
			
		}
	}
	while(!stk.empty()) stk.pop();
	return mx;
}
int main() {
	int fdnr, tmax; char tp;
	scanf("%i", &fdnr);
	for(int donotreuse=0; donotreuse<fdnr; donotreuse++){
		scanf("%i%i", &m, &n); tmax=0;
		for(int i=0; i<m; i++){
			for(int j=0; j<n; j++){
				do{tp=getchar();}while(tp!='F' && tp!='R');
				if (tp=='F') cty[i][j]=1;
				else cty[i][j]=0;
			}
			
		}
		for(int i=0; i<m; i++){
			if (i!=0){
				for(int j=0; j<n; j++){
					if (cty[i][j]==0) {continue;}
					else cty[i][j] = cty[i-1][j]+1;
				}
			}
			tmax=max(tmax, hst(i));
		}
		printf("%i\n", tmax*3);
	}
	return 0;
}