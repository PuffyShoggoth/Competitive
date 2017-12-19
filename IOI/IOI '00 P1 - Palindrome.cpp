#include <iostream>
#include <functional>
#include <string>

using namespace std;

int df[2][5005];
int main() {
	int n;
	string a;
	cin>>n>>a;
	int cc, prv=0;
	for(int i=0; i<n; i++){
		if (a[i]==a[n-1-i]) df[0][i]=1;
	}
	for(int i=1; i<n; i++){
		cc=(prv+1)%2;
		if (a[i]==a[n-1]) df[cc][0]=1;
		else df[cc][0]=df[prv][0];
		for(int j=1; j<n; j++){
			if (a[i]==a[n-1-j]){
				df[cc][j]=df[prv][j-1]+1;
			}
			else{
				df[cc][j]=max(df[prv][j], df[cc][j-1]);
			}
		}
		prv=cc;
	}
	cout<<n-df[prv][n-1];
	return 0;
}