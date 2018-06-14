#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
vector<int> arr[3];
vector<int> ans;
int main() {
	int n;
	scanf("%i", &n);
	for(int i=0; i<n; i++){
		int tmp;
		scanf("%i", &tmp);
		arr[tmp%3].push_back(tmp);
	}
	if(arr[0].size()==0){
	    if(arr[1].size()>0 && arr[2].size()>0){
	        printf("impossible");
	    }
	    else{
		for(int i:arr[1]){printf("%i ", i);}
		for(int i:arr[2]){printf("%i ", i);}
	    }
		return 0;
	}
	else if(arr[0].size()*2-1>n){
		printf("impossible");
		return 0;
	}
	else{
		int dvs=arr[0].back();
		arr[0].pop_back();
		int fv=arr[0].size();
		for(int i=0; i<arr[0].size(); i++){
			if(i>=arr[1].size()){
				fv=i; break;
			}
			else{
				ans.push_back(arr[1][i]);
				ans.push_back(arr[0][i]);
			}
		}
		if(fv<arr[0].size()){
			int fv2=arr[0].size();
			printf("%i ", dvs);
			for(int i:ans){printf("%i ", i);}
			for(int i=0; i+fv<arr[0].size(); i++){
				printf("%i %i ", arr[2][i], arr[0][i+fv]);
			}
			for(int i=fv2-fv; i<arr[2].size(); i++){printf("%i ", arr[2][i]);}
		}
		else{
		    if(fv==arr[1].size()){printf("%i ", dvs);}
			for(int i: ans){printf("%i ", i);}
			for(int i=fv; i<arr[1].size(); i++){
				printf("%i ", arr[1][i]);
			}
			if(fv!=arr[1].size()){printf("%i ", dvs);}
			for(int i: arr[2]){printf("%i ", i);}
		}
	}
    return 0;
}