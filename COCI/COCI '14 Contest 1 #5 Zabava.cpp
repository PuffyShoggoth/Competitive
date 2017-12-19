#include <cstdio>
#include <functional>
using namespace std;
int drm[105];
long long int sm(long long int str, long long int end){
	return ((str+end)*(1+end-str))>>1;
}
long long int ttn[505];
int main() {
	int n, m, k, tpi;
	long long int tp;
	scanf("%i%i%i", &n, &m, &k);
	for(int i=0; i<n; i++){
		scanf("%i", &tpi);
		drm[tpi]++;
	}
	for(int i=1; i<=m; i++){
		for(int j=k; j>=0; j--){
			ttn[j]=sm(1, drm[i])+ttn[j];
			for(int l=0; l<j; l++){
				tp=(drm[i]/(1+j-l));
				ttn[j]=min(ttn[j], sm(1, tp)*(1+j-l-(drm[i]%(1+j-l)))+sm(1, tp+1)*(drm[i]%(1+j-l))+ttn[l]);
			}
		}
	}
	printf("%lli", ttn[k]);
	return 0;
}