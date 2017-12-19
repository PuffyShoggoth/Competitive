#include <bits/stdc++.h>
using namespace std;

long long int bit[255][255][255];
int cvl[255][255][255];
int n;
void update(int x, int y, int z, int l){
	int nvl = l-cvl[x][y][z];
	for(int i=x; i<=n; i+=i&-i){
		for(int j=y; j<=n; j+=j&-j){
			for(int k=z; k<=n; k+=k&-k){
				bit[i][j][k]+=nvl;
			}
		}
	}
	cvl[x][y][z] = l;
}
long long int asum(int x, int y, int z){
	long long int sm = 0;
	for(int i=x; i>0; i-=i&-i){
		for(int j=y; j>0; j-=j&-j){
			for(int k=z; k>0; k-=k&-k){
				sm+=bit[i][j][k];
			}
		}
	}
	return sm;
}
long long int sum(int x1, int y1, int z1, int x2, int y2, int z2){
	long long int tt, s1, s2, s3, b1, b2, b3, cn;
	tt = asum(x2, y2, z2);
	s1 = asum(x2, y2, z1-1); s2 = asum(x2, y1-1, z2); s3 = asum(x1-1, y2, z2);
	b1 = asum(x2, y1-1, z1-1); b2 = asum(x1-1, y2, z1-1); b3 = asum(x1-1, y1-1, z2);
	cn = asum(x1-1, y1-1, z1-1);
	return tt-s1-s2-s3+b1+b2+b3-cn;
}
int main(){
	int q;
	scanf("%i", &n);
	scanf("%i", &q);
	int x1, y1, z1, x2, y2, z2;
	long long int tt=0;
	for(int i=0; i<q; i++) {
		getchar();
		if (getchar()=='C'){
			scanf("%i%i%i%i", &x1, &y1, &z1, &x2);
			update(x1, y1, z1, x2);
		}
		else{
			scanf("%i%i%i%i%i%i", &x1, &y1, &z1, &x2, &y2, &z2);
			tt+=sum(x1, y1, z1, x2, y2, z2);
		}

	}
	printf("%lli", tt);
	return 0;
}