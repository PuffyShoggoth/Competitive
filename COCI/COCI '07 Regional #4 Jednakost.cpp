#include <bits/stdc++.h>
#define INF 9999999
using namespace std;
int dp[1005][5005];
int vls[1005];
int npl[1005][5005][2];
int n, avl;
int gmn(int cn, int ct){
	if (dp[cn][ct]>=0){ return dp[cn][ct]; }
	if(cn==n){ 
		if (ct==0) return 0;
		else return INF;
	}
	if (vls[cn]==0){ dp[cn][ct]=gmn(cn+1, ct); return dp[cn][ct];}
	dp[cn][ct]= INF;
	int tt = vls[cn];
	for(int i=cn+1; i<=n; i++){
		if(tt>ct){ break; }
		if(i==n){
			if(tt==ct){
				dp[cn][ct]=0;
				npl[cn][ct][0]=n;
				npl[cn][ct][1]=0;
			}
			break;
		}
		else{
			int tp = gmn(i, ct-tt)+1;
			if (tp<dp[cn][ct]){
				dp[cn][ct]=tp;
				npl[cn][ct][0]=i; npl[cn][ct][1]=ct-tt;
			}
			tt = tt*10+vls[i];
		}
	}
	return dp[cn][ct];
}
int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin>>s;
	for(int i=0; i<s.length(); i++){
		if (s[i]=='='){
			n = i; break;
		}
		else{
			vls[i]=s[i]-'0';
		}
	}
	avl =0;
	for(int i=n+1; i<s.length(); i++){
		avl = avl*10 + (s[i]-'0');
	}
	memset(dp, -1, sizeof(dp));
	gmn(0, avl);
	int ct = avl;
	for(int i=0; i<n; i++){
		if(s[i]=='0'){ cout<<'0'; continue; }
		int tp = npl[i][ct][0]; 
		for(int j=i; j<tp; j++){
			cout<<s[j];
		}
		if(tp<n){cout<<'+';}
		ct = npl[i][ct][1];
		i = tp-1;
	}
	cout<<s.substr(n, s.length());
	return 0;

}