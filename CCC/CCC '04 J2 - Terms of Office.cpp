#include <iostream>

using namespace std;

int main(){
	int startyear, endyear;
	
	cin>>startyear>>endyear;

	for(int i=startyear; i<=endyear; i+=60){
		cout<<"All positions change in year "<<i<<"\n";
	}
	return 0;
}