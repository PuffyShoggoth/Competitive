#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
bool sv[10005];
vector<int> gifts;
vector<int> primes;
int n, m, a, b, sm=0, tpa, tpb;
bool opt[105][10005];
int main() {
	scanf("%i%i", &n, &m);
	for(int i=0; i<m; i++){
		scanf("%i", &tpa);
		gifts.push_back(tpa);
	}
	for(int i=2; i<=n; i++){
		if (sv[i]==1){continue;}
		if (i<=(n/2)){primes.push_back(i);}
		for(int k=i*i; k<=n; k+=i){
			sv[k]=1;
		}
	}
	sort(gifts.begin(), gifts.end());
	opt[gifts.size()][0]=1;
	tpb=0;
	for(int i=gifts.size()-1; i>=0; i--){
		tpa=99999999;
		for(int l=tpb; l<=n-gifts[i]*2; l++){
			if (opt[i+1][l]==0){continue;}
			for(int k=0; k<primes.size(); k++){
				if (gifts[i]*primes[k]>n){break;}
				tpa=min(tpa, l+primes[k]*gifts[i]);
				opt[i][primes[k]*gifts[i]+l]=1;
			}
		}
		tpb=max(tpb, tpa);
	}
	bool pp=0;
	for(int i=2; i<=n; i++){
		if(sv[i]==1){continue;}
		if(opt[0][i]==1){ printf("its primetime"); pp=1; break;}
	}
	if (pp==0){printf("not primetime");}
	return 0;
}