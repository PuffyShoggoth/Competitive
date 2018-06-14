#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int gcd(int a, int b){
	if(b==0){ return a;}
	else{return gcd(b, a%b);}
}
int lcm(int a, int b){
	return a/gcd(max(a,b), min(a, b))*b;
}
//brute force
int vls[2000006];
bool dn[2000006];
vector<int> cvls;
int main() {
	int n;
	scanf("%i", &n);
	bool std = 0;
	bool b=1;
	double t1;
	for(int i=0; i<n; i++){
		long long int x, tx;
		scanf("%lli%lli", &x, &tx);
		if(x==0){
			if(tx!=0){b=0; break;}
			else{
			    continue;
			}
		}
		if(std){
			if(abs(t1*x - tx)<1e-15){
				continue;
			}
			else{
				b=0;
				break;
			}
		}
		else{
			t1 = tx/((double)x);
			std = 1;
		}
	}
	if(b){
		printf("yes");
	}
	else{
		printf("no");
	}
    return 0;
}