#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
//int fib[100];
long long int vls[1000005];
//bool tkn[100];
//int dp[100][2];
long long int dp[1000005];
//wow, did I ever misread this problem statement
int main() {
	int k, n;
	scanf("%i %i", &k, &n);
	/*fib[0]=1; fib[1]=1;
	int fnum=1;
	for(int i=2; i<100; i++){
		fib[i]=fib[i-1]+fib[i-2];
		if(fib[i]>k){fnum=i; break;}
	}*/
	for(int i=0; i<n; i++){
		//if(i>fnum){break;}
		scanf("%lli", &vls[i]);
	}
	//sum of first n fibonacci numbers is 
	//fib[n]+fib[n-1]-1+fib[n]=fib[n]+fib[n+1]-1=fib[n+2]-1
	if(k>=n+2){
		printf("-1"); return 0;
	}
	int tt=0;
	dp[0]=vls[0]; dp[1]=max(vls[1], vls[0]);
	for(int i=2; i<n; i++){
		dp[i]=max(dp[i-2]+vls[i-1], vls[i]);
	}
	if(k==n+1){
		if(n==1){printf("%lli", vls[0]);}
		else{printf("%lli", dp[n-2]+vls[n-1]);}
	}
	else{printf("%lli", dp[max(k-1,1)]);}
    return 0;
}