#include <bits/stdc++.h>
using namespace std;

int ai[10];
vector<long long int> noise[2];
vector<long long int> org;
int main(){
	int n, a;
	long long int x;
	scanf("%i", &n);
	int tt=1;
	for(int i=0; i<n; i++){
		scanf("%i", &ai[n-1-i]);
		tt*=ai[n-1-i];
	}
	for(int i=0; i<tt; i++){
		scanf("%lli", &x);
		noise[1].push_back(x);
		noise[0].push_back(0);
		org.push_back(x);
	}
	long long int d=1;
	for(int i=0; i<n; i++){
		for(int j=0; j<tt; j++){
			noise[i%2][j]=noise[(i+1)%2][j];
			if(j>=d && (j-d)/(d*ai[i]) == j/(d*ai[i])){
				noise[i%2][j]+=noise[(i+1)%2][j-d];
			}
			if((j+d)/(d*ai[i]) == j/(d*ai[i])){
				noise[i%2][j]+=noise[(i+1)%2][j+d];
			}
		}
		d*=ai[i];
	}
	for(int i=0; i<tt; i++){
		printf("%lli\n", noise[(n-1)%2][i]-org[i]);
	}
	return 0;
}