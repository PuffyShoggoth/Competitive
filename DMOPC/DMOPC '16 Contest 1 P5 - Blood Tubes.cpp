#include <cstdio>
#include <algorithm>
int bit[500005];
int n;
int sum(int ind){
	int ts=0;
	for(int i=ind; i>0; i-=i&-i){
		ts+=bit[i];
	}
	return ts;
}
void update(int ind){
	for(int i=ind; i<=n; i+=i&-i){
		bit[i]+=1;
	}
}
int main(){
	scanf("%i", &n);
	long long int tt=0;
	int tp;
	for(int i=0; i<n; i++){
		scanf("%i", &tp);
		int tps = sum(tp);
		tt+=std::min(tps, i-tps);
		update(tp);
	}
	printf("%lli", tt);
	return 0;
}