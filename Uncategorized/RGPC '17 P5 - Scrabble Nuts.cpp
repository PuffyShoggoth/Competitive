#include <vector>
#include <utility>
#include <cmath>
#include <deque>
#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
string a, b;
long long int mv[10005][2];

int main(){
	int n, m;
	cin>>n>>m;
	cin>>a>>b;
	for(int i=0; i<n; i++){
		mv[i][0]=i+1;
	}
	int curr, prv=0;
	long long int tt=0;
	for(int i=0; i<m-1; i++){
		curr=(prv+1)%2;
		if (b[i]==a[0]){
			mv[0][curr]=i;
		}
		else{
			mv[0][curr]=i+1;
		}
		for(int j=1; j<n; j++){
			if (b[i]==a[j]){
				mv[j][curr]=mv[j-1][prv];
			}
			else{
				mv[j][curr]=min(mv[j-1][prv], min(mv[j-1][curr], mv[j][prv]))+1;
			}
		}
		tt+=mv[n-1][curr];
		prv=curr;
	}
	printf("%lli", tt);
	return 0;
}