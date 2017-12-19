#include <iostream>
#include <string>
#include <cmath>
using namespace std;
long double dp[25][25][500];
int dicevals[6]={4, 6, 8, 10, 12, 20};
int main() {
	int t, h, s, x, y, z, tpi;
	long double tpd;
	string cdie;
	for(int dnrff=0; dnrff<6; dnrff++){
		tpi=dicevals[dnrff];
		tpd=tpi;
		dp[tpi][0][0]=1;
		for(int i=1; i<=20; i++){
			for(int j=1; j<=tpi; j++){
				for(int k=j; k<=tpi*i; k++){
					dp[tpi][i][k]+=dp[tpi][i-1][k-j];
				}
			}
			for(int j=1; j<=tpi*i; j++){
				dp[tpi][i][j]=dp[tpi][i][j]/tpd;
			}
		}
		for(int i=1; i<=20; i++){
			for(int j=tpi*i; j>=0; j--){
				dp[tpi][i][j]+=dp[tpi][i][j+1];
			}
		}
	}
	cin>>t;
	
	int cc, sgn;
	long double opt;
	for(int donotuse=1; donotuse<=t; donotuse++){
		cin>>h>>s; opt=0;
		for(int i=0; i<s; i++){
			cin>>cdie;
			x=(cdie[0]-'0');
			if (cdie[1]=='d'){ cc=2; }
			else{ cc=3; x = (x*10)+(cdie[1]-'0');}
			y=(cdie[cc]-'0');
			cc++;
			if (cc==cdie.length()){ z=0; }
			else {
				if ((cdie[cc]!='-') && (cdie[cc]!='+')){ y= (y*10) + (cdie[cc]-'0'); cc++;}
				if (cc==cdie.length()){z=0;}
				else{
					if (cdie[cc]=='-'){ sgn=-1; }
					else { sgn=1; }
					z=0; cc++;
					while(cc<cdie.length()){
						z= (z*10) + (cdie[cc]-'0'); cc++;
					}
					z=(z*sgn);
				}
			}
			if (z>=h){ opt=1; }
			else if ((h-z)>(y*x)){ continue; }
			else{
				opt = max(opt, dp[y][x][h-z]);
			}
			
		}
		cout<<"Case #"<<donotuse<<": "<<opt<<"\n";
	}
	return 0;
}