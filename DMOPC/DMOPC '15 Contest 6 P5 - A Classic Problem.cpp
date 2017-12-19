#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int arn[3000019];
int main() {
	int n, s=1, m=9999999, mx=-9999999, k;
	long long int tt=0;
	cin>>n>>k;
	for(int i=1; i<=n; i++){
		scanf("%i", &arn[i]);
		if (arn[i]<=mx and arn[i]>=m){
			tt+=i-s+1;
		}
		else{if (arn[i]<m){
			if ((mx-arn[i])<=k){m=arn[i]; tt+=i-s+1;}
			else{m=arn[i]; mx=arn[i];
			for (int p=i; p>=s; p--){
			if ((arn[p]-m)>k){s=p+1; break;}
			mx=max(mx, arn[p]);
			tt+=1;}}
		}
		else if (arn[i]>mx){
			if ((arn[i]-m)<=k){mx=arn[i]; tt+=i-s+1;}
			else{mx=arn[i]; m=arn[i];
			for (int p=i; p>=s; p--){
			if ((mx-arn[p])>k){s=p+1; break;}
			m=min(m, arn[p]);
			tt+=1;
			}}
		}	
		}
	}
	cout<<tt;
	return 0;
}