#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int m[5005];
unordered_set<long long int> dn;
int main(){
	long long int seed = 163;
	string s;
	cin>>s;
	int tt=0;
	for(int i=0; i<s.length(); i++){
		int a=i-1;
		long long int hash = 0;
		m[i]=i-1;
		for(int j=i+1; j<=s.length(); j++){
			while(a>=i && s[j-1]!=s[a]) { a = m[a]; }
			a++; m[j]=a; 
			hash = (hash*seed + s[j-1]-'a'+1)%MOD;
			if(a>i && (a-i)*2>= (j-i) && !dn.count(hash)){
				 int stv = a-i;
				 if(stv%(j-a)==0){ 
				     tt++; 
				     dn.insert(hash);
				 }
			}
		}
	}
	printf("%i", tt);
	return 0;
}