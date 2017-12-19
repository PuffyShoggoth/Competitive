#include <cstdio>
#include <cstring>
using namespace std;
char strg[1000050];
int n, l, *rnk, cnt[1000050], *sfxar, *tmp;

void rdxps(int k){
	memset(cnt, 0, 4000200);
	for(int i=0; i<=n; i++){
		if (sfxar[i]+k>n){cnt[0]+=1;}
		else{cnt[rnk[sfxar[i]+k]]+=1;}
	}
	int sm=0;
	for(int i=0; i<=((n<86)?86:n); i++){
		sm+=cnt[i]; cnt[i]=sm-cnt[i];
	}
	for(int i=0; i<=n; i++){
		if (sfxar[i]+k>n){
			tmp[cnt[0]]=sfxar[i]; cnt[0]+=1;
		}
		else{
			tmp[cnt[rnk[sfxar[i]+k]]]=sfxar[i]; cnt[rnk[sfxar[i]+k]]+=1; 
		}
	}
	int *tp = sfxar;
	sfxar=tmp; tmp=tp;
	return;
}
	



int main() {
	n = (int) strlen(gets(strg));
	scanf("%i", &l);
	strg[n]='$';
	sfxar = new int[n+1]; tmp = new int[n+1];
	rnk = new int[1000050];
	for(int i=0; i<=n; i++){
		rnk[i]=strg[i]-'$'; sfxar[i]=i;
	}
	int r, *tp; 
	for(int i=1; i<=(n<<1); i=(i<<1)){
		rdxps(i);
		rdxps(0);
		r=0; tmp[sfxar[0]]=0;
		for(int j=1; j<=n; j++){
			if (((rnk[sfxar[j]]!=rnk[sfxar[j-1]]))|| (rnk[(((sfxar[j]+i)<=n)?(sfxar[j]+i):0)]!=rnk[(((sfxar[j-1]+i)<=n)?(sfxar[j-1]+i):0)])){r++;}
			tmp[sfxar[j]]=r;
		}
		tp=rnk;
		rnk=tmp;
		tmp=tp;
		if (rnk[sfxar[n]]==n) break;
	}
	for(int i=0; i<=n; i++){
		if (n-sfxar[i]<l) continue;
		for(int j=sfxar[i]; j<sfxar[i]+l; j++){
			putchar(strg[j]);
		}
		break;
	}
	
	return 0;
}