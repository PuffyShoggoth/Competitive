#include <iostream>
#include <string>
using namespace std;
string s, t;
int prp[1000005];
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
	cin>>s>>t;
	prp[0]=-1;
	int i=0, j=-1;
	while(i<t.size()){
		while(j>=0 && t[i]!=t[j]){ j = prp[j]; }
		j++; i++; prp[i] = j;
	}
	int fmatch = -1;
	i=0; j=0;
	while(i<s.size()){
		while(j>=0 && t[j]!=s[i]){ j = prp[j]; }
		i++; j++; 
		if (j==t.size()){ fmatch = i-j; break;}
	}
	printf("%i", fmatch);
}