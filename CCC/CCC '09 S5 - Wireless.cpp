#include <iostream>
#include <cmath>
using namespace std;
int p[1005][30005];
int main() {
	int m, n, k;
	cin>>m>>n>>k;
	int temp[4];
	for (int i=0; i<k; i++){
		cin>>temp[0]>>temp[1]>>temp[2]>>temp[3];
		int cury;
		int lmtt;
		if ((temp[0]+temp[2]<=n) || (temp[0]-temp[2]>=1)){lmtt=temp[2];}
		else{ lmtt=n;}
		int r=temp[2]*temp[2];
		p[temp[0]][min(temp[1]+temp[2], m)]+=temp[3];
		p[temp[0]][max(temp[1]-temp[2], 1)-1]-=temp[3];
		for (int qwee=1; qwee<=lmtt; qwee++){
			cury=sqrt(r-qwee*qwee)+temp[1];
			int f, g;
			f=min(cury, m);
			g=max(temp[1]*2-cury, 1)-1;
			if (temp[0]+qwee<=n){
				p[temp[0]+qwee][f]+=temp[3];
			p[temp[0]+qwee][g]-=temp[3];}
			if (temp[0]-qwee>=1){
			
			p[temp[0]-qwee][f]+=temp[3];
			p[temp[0]-qwee][g]-=temp[3];}}
	

	}
	//for (int i=m; i>=1; i--){
	//	for (int j=50; j<=74; j++){
	//	    if (p[j][i]<0){
	//		cout<<p[j][i]<<" ";}
	//		if (p[j][i]==0){
	//		cout<<p[j][i]<<"    ";}
	//		if (p[j][i]>0){
	//		cout<<p[j][i]<<"  ";}}
	//		cout<<"\n";
	//		}
		
	int maxb=0, shops=0, rowsum=0;
	for (int i=1; i<=n; i++){
		rowsum=0;
		for (int j=m; j>=1; j--){
			rowsum+=p[i][j];
			if (rowsum==maxb){shops+=1;}
			else if (rowsum>maxb){maxb=rowsum; shops=1;}
			}
		}
	cout<<maxb<<"\n"<<shops;
			
			
			
		
	
	return 0;
}