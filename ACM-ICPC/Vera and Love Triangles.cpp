#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int cycid[200005];
int cycl[200005];
int cycpos[200005];
int pfx[200005];
bool odd[200005];
vector<int> cycpfx[200005];
long long int n, m, a, b;
int ccyc=0;
void gcyc(int crr, int pos){
	if(cycid[crr]){
		cycl[ccyc]=pos;
		return;
	}
	cycpos[crr]=pos;
	cycid[crr]=ccyc;
	if(pos){cycpfx[ccyc].push_back(cycpfx[ccyc].back()+odd[crr]);}
	else{cycpfx[ccyc].push_back(odd[crr]);}
	gcyc((crr+n)%(m-1), pos+1);
}
int main() {
	
	scanf("%lli%lli%lli%lli", &n, &m, &a, &b);
	long long int st = 1, tp;
	long long int tt = n*(n-1)*(n-2)/6;
	//printf("%i\n", tt);
	a = a % m;
	for(int i=0; i<m-1; i++){
		tp = st*a%m;
		st = st*b % m;
		if(__builtin_popcount(tp)%2){
			odd[i]=1;
		}
		if(i){pfx[i]=pfx[i-1]+(odd[i]?0:1);}
		else{pfx[i]=(odd[i]?0:1);}
	}
	for(int i=0; i<n; i++){
		int im = i%(m-1);
		if(!cycid[im]){
			ccyc++;
			gcyc(im, 0);
		}
		int nr=0, nmod=0;
		int cid=cycid[im];
		long long int tls=0;
		if(i){
			nmod = i%cycl[cid];
			nr = i/cycl[cid];
			tls+=cycpfx[cid].back()*nr;
			if(cycpos[im]){
				if(nmod+cycpos[im]-1>=cycl[cid]){
					tls+=cycpfx[cid].back()-cycpfx[cid][cycpos[im]-1]+cycpfx[cid][(nmod+cycpos[im]-1)%cycl[cid]];
				}
				else{
					tls+=cycpfx[cid][nmod+cycpos[im]-1]-cycpfx[cid][cycpos[im]-1];
				}
			}
			else if (nmod){
				tls+=cycpfx[cid][nmod-1];
			}
		}
		//printf("%i ", tls);
		nr=(n-1-i)/(m-1);
		nmod=(n-1-i)%(m-1);
		im= (n*i+i)%(m-1);
		tls+=nr*pfx[m-2];
		//printf("%i %i %i ", nr, nmod, im);
		if (im+nmod<(m-1)){
			tls+=pfx[im+nmod]-pfx[im];
		}
		else{
			tls+=pfx[m-2]-pfx[im]+pfx[(im+nmod)%(m-1)];
		}
		//printf("%i\n", tls);
		if(tls>1){tt-=(tls)*(tls-1)/2;}
		
	}
	printf("%lli", tt);

    return 0;
}