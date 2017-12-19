#include <iostream> 
#include <algorithm> 

using namespace std; 
int main(){
	int bowls[3];
	cin>>bowls[0]>>bowls[1]>>bowls[2]; 
	sort(bowls, bowls+3); 
	cout<<bowls[1]; 
	return 0; 
}