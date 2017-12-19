#include <cstdio>
#include <cstring>
#include <map>
#define MOD 1000000007
using namespace std;

int nk[4005];

long long int cb[4005];
map<int, long long int> vk[4005];
map<int, long long int>:: iterator ita, itb, itp;
void merge(int p, int c){
	map<int, long long int> tp=vk[p];
	long long int ta;
	for(ita=vk[c].begin(); ita!=vk[c].end(); ++ita){
		itb=vk[p].find(ita->first);
		if (itb!=vk[p].end()){itb->second=(itb->second+ita->second)%MOD;}
		else{vk[p][ita->first]=ita->second;}
		for(itp=tp.begin(); itp!=tp.end(); ++itp){
			itb=vk[p].find(ita->first+itp->first);
			ta=(ita->second*itp->second)%MOD;
			if (itb!=vk[p].end()){itb->second=(itb->second+ta)%MOD;}
			else{vk[p][ita->first+itp->first]=ta;}
		}
	}
	return;
}

void sm(int st){
	int i=st+1, cw=nk[st]-st-1;
	long long int tt=cb[cw], ta;
	while(i<nk[st]){
		if (nk[i]){
			sm(i);
			merge(st, i);
			i=nk[i];
		}
		i++;
	}
	
	for(ita=vk[st].begin(); ita!=vk[st].end(); ++ita){
		ta=ita->second;
		tt=(tt+ta*cb[cw-ita->first])%MOD;
	}
	vk[st][cw+2]=tt;

	return;
}
	
int main(){
	int n, k, a, b; long long int tpa, tpb;
	scanf("%i%i", &n, &k);
	cb[0]=1;
    for(int i=2; i<=n; i+=2){
        for(int j=2; j<=i; j+=2){
            cb[i]=(cb[i]+(cb[i-j]*cb[j-2])%MOD)%MOD;
        }
    }
    nk[0]=n+1;
	for(int i=0; i<k; i++){
		scanf("%i%i", &a, &b);
		if ((a+b)%2){ nk[a]=b;}
	}
	sm(0);
	printf("%lli", vk[0][n+2]);
	return 0;
}