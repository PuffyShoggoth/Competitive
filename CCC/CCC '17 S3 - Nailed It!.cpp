#include <cstdio>
#define min(a,b) ((a<b)?(a):(b))
using namespace std;
int hght[2005];
int main(){
	int n;
	int sc, tp, mx=0, mxn=0;
	scanf("%i", &n);
	for(int i=0; i<n; i++){
		scanf("%i", &sc);
		hght[sc]++;
	}
	for(int i=4000; i>0; i--){
		tp=0;
		if (!(i%2)){
			tp+=hght[i/2]/2;
		}
		for(int j=min(2000, i-1); i-j<j; j--){
			tp+=min(hght[j],hght[i-j]);
		}
		if (tp==mx){mxn++; }
		else if (tp>mx){mxn=1; mx=tp; }
	}
	printf("%i %i", mx, mxn);

}