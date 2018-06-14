#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int arr[5];
int arr2[5];
int main() {
	for(int i=1; i<5; i++){
		scanf("%i", &arr[i]);
		arr2[i-1]=arr[i];
	}
	for(int i=0; i<5; i++){
		vector<int> ans;
		int tt = 0;
		for(int j=i-1; j>=0; j--){
			tt+=arr2[j]; ans.push_back(tt);
		}
		reverse(ans.begin(), ans.end());
		for(int j: ans){printf("%i ", j);}
		printf("0 ");
		tt = 0;
		for(int j=i+1; j<5; j++){
			tt+=arr[j]; printf("%i ", tt);
		}
		printf("\n");
	}
    return 0;
}