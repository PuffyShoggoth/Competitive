#include <iostream>
#include <cstdio>

using namespace std;

long long int bit[100009];
long long int bst[100009];
int a[100009];
int n;

void update(long long int bt[], int i, long long int s){
	for(int k=i; k<=100000; k+=(k&-k)){
		bt[k]+=s;
	}
	return;
}

long long int sm(long long int bt[], int i){
	long long int s=0;
	for(int k=i; k>0; k-=(k&-k)){
		s+=bt[k];
	}
	return s;
}

int main(){
	int m, x, v, l, r, cn;
	char t;
	scanf("%i%i", &n, &m);
	for(int i=1; i<=n; i++){
		scanf("%i", &cn);
		a[i]=cn;
		update(bit, i, cn);
		update(bst, cn, 1);
	}
	for(int i=0; i<m; i++){
		scanf("%c", &t);
		while(t<'A'){scanf("%c", &t);}
		switch(t){
			case ('C'):
				scanf("%i%i", &x, &v);
				update(bst, a[x], -1);
				update(bst, v, 1);
				update(bit, x, (v-a[x]));
				a[x]=v;
				break;
			case ('S'):
				scanf("%i%i", &l, &r);
				printf("%lli\n", (sm(bit, r)-sm(bit, l-1)));
				break;
			case ('Q'):
				scanf("%i", &v);
				printf("%lli\n", sm(bst, v));
				break;
			}
	}
	return 0;
}