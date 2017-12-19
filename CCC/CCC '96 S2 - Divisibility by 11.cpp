#include <string>
#include <iostream>
#include <deque>
using namespace std;
deque<int> numb[2];
string nb;
int main() {
	int t, curr, prv, tp;
	cin>>t;
	for(int i=0; i<t; i++){
		cin>>nb; prv=0;
		numb[0].clear();
		for(int j=0; j<nb.size(); j++){
			numb[0].push_front(nb[j]-'0');
		}
		while(numb[prv].size()>2){
			for(int k=numb[prv].size()-1; k>=0; k--){
				cout<<numb[prv][k];
			}
			cout<<"\n";
			curr=(prv+1)%2;
			numb[curr].clear();
			tp=numb[prv].front();
			numb[prv].pop_front();
			if (tp>numb[prv].front()){
				numb[curr].push_back(numb[prv].front()+10-tp);
				numb[prv].pop_front();
				tp=1;
			}
			else{
				numb[curr].push_back(numb[prv].front()-tp);
				numb[prv].pop_front();
				tp=0;
			}
			while(tp!=0){
				if (numb[prv].front()==0){
					numb[curr].push_back(9);
					numb[prv].pop_front();
				}
				else{
					numb[curr].push_back(numb[prv].front()-1);
					numb[prv].pop_front();
					tp=0;
				}
			}
			while(!numb[prv].empty()){
				numb[curr].push_back(numb[prv].front()); numb[prv].pop_front();
			}
			while(numb[curr].back()==0){ numb[curr].pop_back(); }
			prv=curr;
		}
		for(int j=numb[prv].size()-1; j>=0; j--){
			cout<<numb[prv][j];
		}
		cout<<"\n";
		if (numb[prv].size()==2 && numb[prv].front()==numb[prv].back()){
			cout<<"The number "<<nb<<" is divisible by 11.\n";
		}
		else{
			cout<<"The number "<<nb<<" is not divisible by 11.\n";
		}
	}
	return 0;
}