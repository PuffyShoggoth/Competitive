#include <bits/stdc++.h>

using namespace std;
bool cs[1005][1005];
bool res[1005][1005];
int main(){
	cin.sync_with_stdio(0);
    cin.tie(0);
    string s;
    int r, c;
    cin>>r>>c;
    for(int i=0; i<r; i++){
    	cin>>s;
    	for(int j=0; j<c; j++){
    		cs[i][j]= (s[j]=='X');
    	}
    }
    for(int i=0; i<r; i++){
    	for(int j=0; j<c; j++){
    		if(cs[i][j]){
    			for(int k=0; k<c; k++){
    				res[i][k]=1;
    			}
    			break;
    		}
    	}
    }
    for(int i=0; i<c; i++){
    	for(int j=0; j<r; j++){
    		if(cs[j][i]){
    			for(int k=0; k<r; k++){
    				res[k][i]=1;
    			}
    			break;
    		}
    	}
    }
    int q, a, b;
    cin>>q;
    for(int i=0; i<q; i++){
    	cin>>a>>b;
    	if(res[b-1][a-1]){
    		printf("Y\n");
    	}
    	else{
    		printf("N\n");
    	}
    }
}