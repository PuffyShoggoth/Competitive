#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<string> as, av, ao;
int main() {
	int n, s, v, o;
	string tp;
	cin>>n; 
	while(n--){
		cin>>s>>v>>o; getchar();
		for(int i=0; i<s; i++){
			getline(cin, tp); as.push_back(tp);
		}
		for(int i=0; i<v; i++){
			getline(cin, tp); av.push_back(tp);
		}
		for(int i=0; i<o; i++){
			getline(cin, tp); ao.push_back(tp);
		}
		for(int i=0; i<s; i++){
			for(int j=0; j<v; j++){
				for(int k=0; k<o; k++){
					cout<<as[i]<<" "<<av[j]<<" "<<ao[k]<<".\n";
				}
			}
		}
		cout<<"\n";
		av.clear(); as.clear(); ao.clear();
	}
	return 0;
}