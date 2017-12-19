#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<long long int> bshot, twdth, ttc;

//Comments from friends and relatives: "It's inappropriate!" "They let you on this site at school?" "This objectifies women!"
//"Um... it's for Comp Sci..."
//-__-
//-___-
//-____-
//-_____-
//-______-

int main(){
	int n;
	long long int w, p, c;
	scanf("%i%lli", &n, &w);
	char tp;
	bshot.push_back(0); twdth.push_back(0); ttc.push_back(0);
	while(n--){
		getchar(); tp=getchar();
		if (tp=='D'){
			bshot.pop_back(); twdth.pop_back(); ttc.pop_back();
		}
		else{
			scanf("%lli%lli", &p, &c);
			ttc.push_back(ttc.back()+c);
			twdth.push_back(twdth.back()+p);
			if (w>=twdth.back()){
				bshot.push_back(ttc.back());
			}
			else{
				bshot.push_back(max(bshot.back(), ttc.back()-(ttc[lower_bound(twdth.begin(), twdth.end(), twdth.back()-w)-twdth.begin()])));
			}
			printf("%lli\n", bshot.back());
		}
	}
}