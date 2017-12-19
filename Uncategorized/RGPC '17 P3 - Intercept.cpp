#include <vector>
#include <utility>
#include <cmath>
#include <deque>
#include <cstdio>
#include <cstring>
using namespace std;

vector<pair<int, int> > edges[1005];
vector<int> topsort;
long long int coef[15];
long long int rt[15];
int n;
long long int clc(int cr, int rm){
	if (!rm){
		return rt[cr];
	}
	rm--;
	long long int tmp=0;
	for(int i=cr-1; i>=rm; i--){
		tmp+=rt[cr]*clc(i, rm);
	}
	return tmp;
}
int main(){
	int q;
	long long int x, y, tt, pv;
	scanf("%i", &q);
	while(q--){
		scanf("%i", &n);
		for(int i=0; i<n; i++){
			scanf("%lli", &rt[i]);
		}
		pv=1;
		coef[0]=1;
		for(int i=1; i<=n; i++){
			coef[i]=0;
			
			for(int j=n-1; j>=i-1; j--){
				coef[i]+=clc(j, i-1);
			}
			pv=pv*(-1);
			coef[i]=coef[i]*pv;
			
		}
		scanf("%lli%lli", &x, &y);
		pv=1; tt=0;
		for(int i=n; i>=0; i--){
			tt+=coef[i]*pv; pv=x*pv;
		}
		double an=y/tt;
		for(int i=0; i<=n; i++){
			coef[i]=coef[i]*an;
			printf("%lli ", coef[i]);
		}
		printf("\n");

	}
	
	return 0;
}