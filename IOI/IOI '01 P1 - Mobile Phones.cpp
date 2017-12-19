#include <cstdio>
using namespace std;
int s;
int bit[1030][1030];
void update(int x, int y, int val){
	for(int i=x; i<=s; i+=i&-i){
		for(int j=y; j<=s; j+=j&-j){
			bit[i][j]+=val;
		}
	}
	return;
}
int sm(int x, int y){
	int tp=0;
	for(int i=x; i>0; i-=i&-i){
		for(int j=y; j>0; j-=j&-j){
			tp+=bit[i][j];
		}
	}
	return tp;
}
int main() {
	int tp, ni, x, y, a, l, b, r, t;
	scanf("%i%i", &tp, &s);
	scanf("%i", &ni);
	while(ni!=3){
		if (ni==1){
			scanf("%i%i%i", &x, &y, &a);
			update(x+1, y+1, a);
		}
		else{
			scanf("%i%i%i%i", &l, &b, &r, &t);
			printf("%i\n", sm(r+1, t+1)-sm(l, t+1)-sm(r+1, b)+sm(l, b));
		}
		scanf("%i", &ni);
	}
	return 0;
}