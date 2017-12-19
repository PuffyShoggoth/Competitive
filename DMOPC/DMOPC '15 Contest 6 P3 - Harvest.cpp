#include <iostream>
#include <cstdio>
using namespace std;
int potatoes[200019];
int main() {
	int m, n, a, b, w=999999, si=1, t, s;
	long long int k, tt=0;
	scanf("%i%i", &n, &m); cin>>k;
	t=m; s=m;
	for(int i=1; i<=m; i++){
		scanf("%i%i", &a, &b);
		potatoes[a]-=1; potatoes[b+1]+=1;
	}
	for(int i=1; i<=n; i++){
		t+=potatoes[i];
		tt+=t;
		while((tt-(s+potatoes[si]))>=k){
			s+=potatoes[si];
			si+=1;
			tt-=s;
		}
		if ((tt)>=k){
			w=min(w, i-si+1);
		}
	}
	if (w!=999999){cout<<w;}
	else{cout<<-1;}
	return 0;
}