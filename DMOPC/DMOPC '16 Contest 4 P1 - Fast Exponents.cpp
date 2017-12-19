#include <cstdio>
using namespace std;

int main() {
	int n;
	scanf("%i", &n);
	long long int i; bool pt;
	while(n--){
		scanf("%lli", &i);
		pt=0;
		while(!pt){
			pt=i&1LL;
			i>>=1;
		}
		if (i)printf("F\n");
		else printf("T\n");
	}
	return 0;
}