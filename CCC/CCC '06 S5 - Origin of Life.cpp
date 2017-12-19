#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <cstring>
#define mp(a,b) make_pair(a, b)
#define f first
#define s second
using namespace std;
int m, n, a, b, c, board;
int dp[1050000]; 
vector<int>prv[1050000];
pair<int, int> nbc[8]={mp(-1, -1), mp(0, -1), mp(1, -1), mp(-1, 0), mp(1, 0), mp(-1, 1), mp(0, 1), mp(1, 1)};
int nrstgard(int cb){
	if(dp[cb]!=-2){return dp[cb];}
	if(prv[cb].size()==0){dp[cb]=0; return 0;}
	dp[cb]=-1;
	int tp=99999999, tmp;
	for(int i=0; i<prv[cb].size(); i++){
		tmp=nrstgard(prv[cb][i]);
		if (tmp!=-1){tp=min(tp, tmp+1);}
	}
	if (tp!=99999999){dp[cb]=tp;}
	return dp[cb];
}
int nextg(int cg){
    int lc[6][7];
    memset(lc, 0, 168);
    int ng=0;
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(((1<<((i-1)*n+j-1))&cg)==0){continue;}
            for(int k=0; k<8; k++){
                lc[i+nbc[k].s][j+nbc[k].f]+=1;
            }
        }
    }
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(((1<<((i-1)*n+j-1))&cg)==0){
                if (lc[i][j]>c){ng+=(1<<(n*(i-1)+j-1));}
            }
            else{
                if (a<=lc[i][j] && b>=lc[i][j]){ng+=(1<<((i-1)*n+j-1));}
            }
        }
    }
    return ng;
}
                    


int main()
{    
  scanf("%i%i%i%i%i", &m, &n, &a, &b, &c);
  char tp;
  for(int i=0; i<m*n; i++){
      do{tp=getchar();}while(tp=='\n');
      if (tp=='*'){board+=(1<<i);}
  }
  for(int i=0; i<(1<<(m*n)); i++){
      prv[nextg(i)].push_back(i);
      dp[i]=-2;
  }
  nrstgard(board);
  printf("%i", dp[board]);
  return 0;    
}