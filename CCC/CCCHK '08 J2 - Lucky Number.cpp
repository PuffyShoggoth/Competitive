#include <bits/stdc++.h>

using namespace std;
int main() {
	int n, a, b;
	cin.sync_with_stdio(0);
    cin.tie(0);
	cin>>n;
	string s;
	while(n--){
		cin>>s;
		int tt = 0;
		for(int i=0; i<s.length(); i++){
			tt+=s[i]-'0';
		}
		while(tt>=10){
			int tt2=0;
			while(tt>0){
				tt2+=tt%10;
				tt=tt/10;
			}
			tt = tt2;
		}
		cout<<tt<<'\n';
	}
    return 0;
}