#include <iostream>
using namespace std;
int t[403][403];
int riceballs[403];
int mx=0;
int main() {
	int n, tc=0;
	cin>>n;
	for (int i=1; i<=n; i++){
		cin>>riceballs[i];
		t[i][i]=riceballs[i];
		riceballs[i]+=riceballs[i-1];
	}
	for (int i=0; i<n; i++){
		for (int f=1; f<=n; f++){
			if ((f+i)>n){break;}
			tc=0;
			for (int a=f; a<f+i; a++){
				if (tc==1){break;}
				if (riceballs[a]-riceballs[f-1]>riceballs[f+i]-riceballs[a]){
					break;
				}
				if (t[f][a]==0){continue;}
				if (t[f][a]==t[a+1][f+i]){
					t[f][f+i]=t[f][a]+t[a+1][f+i];
					break;
				}
				for (int b=a+2; b<=f+i; b++){
					if (riceballs[a]-riceballs[f-1]>riceballs[f+i]-riceballs[b-1]){
					break;
					}
					if (t[a+1][b-1]==0){continue;}
					if (t[f][a]==t[b][f+i]){
						t[f][f+i]=t[f][a]+t[a+1][b-1]+t[b][f+i];
						tc=1;
						break;}
				}
				
			}
			mx=max(t[f][f+i], mx);
		
		}
	}
	cout<<mx;
	return 0;
}