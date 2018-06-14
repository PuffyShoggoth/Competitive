#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int main() {
	string s1, s2;
	int n;
	cin>>n;
	cin>>s1>>s2;
	int tt =0;
	for(int i=0; i<n; i++){
		if(s1[i]=='C'&& s2[i]=='C'){tt++;}
	}
	printf("%i", tt);
    return 0;
}