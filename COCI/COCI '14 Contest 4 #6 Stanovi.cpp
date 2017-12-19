#include <iostream>
#include <cmath>
using namespace std;
long long int s1[305][305];
long long int s2[305][305];
long long int s3[305][305];
long long int s4n[305], s4m[305];
int main() {
	long long int n, m, k;
	cin>>n>>m>>k;
	long long int tp, f;
	f=max(n, m);
	for(int i=1; i<=f; i++){
		for(int j=1; j<=f; j++){
			tp=(i*j-k)*(i*j-k);
			for(int l=1; l<j; l++){
				tp = min(tp, s1[i][l]+s1[i][j-l]);
			}
			s1[i][j]=tp;
		}
	}
	for(int i=1; i<=f; i++){
		for(int j=1; j<=f; j++){
			tp=s1[i][j];
			for(int l=1; l<i; l++){
				tp=min(tp, s1[l][j]+s1[i-l][j]);
			}
			for(int l=1; l<j; l++){
				tp=min(tp, s2[i][l]+s2[i][j-l]);
			}
			s2[i][j]=tp;
		}
	}
	for(int i=1; i<=f; i++){
		for(int j=1; j<=f; j++){
			tp=s1[j][i];
			for(int l=1; l<i; l++){
				tp=min(tp, s1[j][l]+s3[i-l][j]);
			}
			for(int l=1; l<=j; l++){
				tp=min(tp, s3[i][j-l]+s1[i][l]);
			}
			s3[i][j]=tp;
			
		}
	}
	for(int i=1; i<=n; i++){
		tp=s1[m][i];
		for(int j=i; j<=m; j++){
			for(int l=j; l<=m; l++){
				tp=min(tp, s3[j][i]+s1[i][l-j]+s3[m-l][i]);
			}
		}
		s4m[i]=tp;
	}
	for(int i=1; i<=m; i++){
		tp=s1[n][i];
		for(int j=1; j<=n; j++){
			for(int l=j; l<=n; l++){
				tp=min(tp, s3[j][i]+s1[i][l-j]+s3[n-l][i]);
			}
		}
		s4n[i]=tp;
	}
	tp=min(s2[n][m], s2[m][n]);
	for(int i=1; i<=m; i++){
		for(int j=i; j<=m; j++){
			tp=min(tp, s4n[i]+s2[n][j-i]+s4n[m-j]);
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=i; j<=n; j++){
			tp=min(tp, s4m[i]+s2[m][j-i]+s4m[n-j]);
		}
	}
	cout<<tp;
	return 0;
}