#include <cstdio>

long long int bit[100005];
int pos[1000005];
int n;
void update(int ind, long long int val){
	for(int i=ind; i<=n; i+=i&-i){
		bit[i]+=val;
	}
	return;
}
long long int sum(int ind){
	long long int sm=0;
	for(int i=ind; i>0; i-=i&-i){
		sm+=bit[i];
	}
	return sm;
}
int main(){
	int q;
	long long int m, va, vb, tp;
	scanf("%i%lli%i", &n, &m, &q);
	for(int i=1; i<=n; i++){
		scanf("%lli", &va);
		pos[va]=i;
		update(i, va);
	}
	for(int i=0; i<q; i++){
		scanf("%lli%lli", &va, &vb);
		if (pos[va]>pos[vb]){
			tp=sum(pos[va])-sum(pos[vb]-1);
		}
		else{
			tp=sum(pos[vb])-sum(pos[va]-1);
		}
		if (tp>=m*2){printf("Enough\n");}
		else{printf("Not enough\n");}
	}
	return 0;
}