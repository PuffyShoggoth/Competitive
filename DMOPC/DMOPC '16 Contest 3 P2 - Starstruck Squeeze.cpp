#include <cstdio>
#include <cstring>
using namespace std;
int inst[100005];
int cex[100005];
int ans[100005];
int main() {
	int n, k, d, cr=0;
	char t;
	scanf("%i%i%i", &n, &k, &d);
	for(int i=0; i<n; i++){
		getchar(); 
		if (getchar()=='T'){
			inst[i]=cr; cr++;
		}
		else{
			scanf("%i", &inst[i]);
			cex[i]=1;
		}
	}
	cr=1;
	for(int i=n-1; i>=0; i--){
		if (cex[i]){
			if (inst[i]*cr > d ) break;
			cr*=inst[i];
		}
		else{
			ans[inst[i]]=cr;
		}
	}
	for(int i=0; i<k; i++){
		if (!ans[i]) printf("dust\n", 1);
		else printf("%i\n", ans[i]);
	}
	return 0;
}