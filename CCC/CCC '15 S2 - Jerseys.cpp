#include <iostream>
using namespace std;
char jer[1000009];
int flg[1000009];
int main() {
	int j, a, jrn, t=0;
	char jrs;
	cin>>j>>a;
	for (int i=1; i<=j; i++){
		cin>>jer[i];
	}
	for (int i=0; i<=a; i++){
		cin>>jrs>>jrn;
		if (flg[jrn]==0){
			switch(jrs){
				case 'S':
					if (jer[jrn]=='S'){
						flg[jrn]=1;
						t++;
					}
				case 'M':
					if (jer[jrn]=='M'){
						flg[jrn]=1; 
						t++;
					}
				case 'L':
					if (jer[jrn]=='L'){
						flg[jrn]=1;
						t++;}
			}
			}
		}
	cout<<t;
	return 0;
}