#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
using namespace std;
int rnk[200005][2];
int sa[200005][2];
int cnt[200005];
char og[200005];
int pva[200005];
int t;
inline int rd(int dnr){ 
	return (dnr>t)?t+1:dnr;
}
void rdx(int sh, int c, int cr){
	int trrl=((t>30)?t:30);
	memset(cnt, 0, sizeof(cnt));
	for(int i=0; i<=t; i++){
		cnt[rnk[rd(sa[i][c]+sh)][cr]]++;
	}
	int pv=0;
	for(int i=0; i<=trrl; i++){
		pv+=cnt[i]; cnt[i]=pv-cnt[i];
	}
	int n=(c+1)%2;
	for(int i=0; i<=t; i++){
		sa[cnt[rnk[rd(sa[i][c]+sh)][cr]]][n]=sa[i][c];
		cnt[rnk[rd(sa[i][c]+sh)][cr]]++;
	}
	return;
}
int main() {
	scanf("%i", &t);
	getchar();
	string s;
	for(int i=0; i<t; i++){
		rnk[i][0]=1+getchar()-'a';
		og[i]=rnk[i][0];
		s+=(rnk[i][0]+'a'-1);
		sa[i][0]=i;
	}
	rnk[t][0]=0; sa[t][0]=t;
	int pv=0, curr, r;
	for(int i=0; i<=log2(t); i++){
		rdx(1<<i, 0, pv);
		rdx(0, 1, pv);
		curr=(pv+1)%2;
		r=0; rnk[sa[0][0]][curr]=0;
		for(int j=1; j<=t; j++){
			if (rnk[sa[j-1][0]][pv]!=rnk[sa[j][0]][pv] || rnk[rd(sa[j-1][0]+(1<<i))][pv]!=rnk[rd(sa[j][0]+(1<<i))][pv]){r++;}
			rnk[sa[j][0]][curr]=r;
		}
		if (rnk[sa[t][0]][curr]==t) break;
		pv=curr;
	}
	pva[sa[0][0]]=-1;
	for(int j=1; j<=t; j++){
		pva[sa[j][0]]=sa[j-1][0];
	}
	int ml=0, mx=0;
	for(int j=0; j<=t; j++){
		if (pva[j]==-1){
			ml=0; continue;
		}
		while(j+ml<t && (og[j+ml]==og[pva[j]+ml])){ ml++; }
		mx=(ml>mx)?(ml):(mx);
		if (ml>0){ ml-=1; }
	}
	printf("%i", mx);
	return 0;
}