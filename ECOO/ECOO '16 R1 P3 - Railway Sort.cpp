#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int nb[1009];
int bt[1009];
void update(int i){
	for (int k=i; k<1009; k+=(k&-k)){
		bt[k]+=-1;}
	return;
}
int sm(int i){
	int t=0;
	for(int k=i; k>0; k-=(k&(-k))){
		t+=bt[k];
	}
	return t;
}
int main() {
	for(int i=0; i<10; i++){
		int n, t, m=9999999, p=0, ttl=0;
		memset(nb, 0, 4036);
		memset(bt, 0, 4036);
		scanf("%i", &n);
		for(int k=0; k<n; k++){
			scanf("%i", &t);
			nb[t]=k;
		}
		for(int k=n; k>0; k--){
			if(m>nb[k]){m=nb[k];}
			else{p=k; break;}
		}
		if (p>0){ttl+=(p*((p-1)/2))+(p/2)*((p-1)%2);}
		for(int k=p; k>0; k--){
			ttl+=nb[k]+sm(nb[k]);
			update(nb[k]+1);
		}
		printf("%i\n", ttl);
	}
	return 0;
}