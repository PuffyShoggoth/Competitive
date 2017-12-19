#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int main(){
    int c;
    cin>>c;
    string p, q, r;
    int d[c][c];
    for (int i=0; i<c; i++){
        cin>>p;
        for (int j=0; j<c; j++){
            if (p[j]=='#'){
                d[i][j]=1;
            }
            else{
                d[i][j]=0;
            }
        }
    }
     for (int k=c-2; k>=0; k--){
        for (int l=1; l<c-1; l++){
            if (d[k][l]==1){
                d[k][l]=d[k][l]+min(d[k+1][l-1], min(d[k+1][l], d[k+1][l+1]));
            }
        }
    }
    long long sum = 0;
    for (int p=0; p<c; p++){
        for (int y=0; y<c; y++){
            sum+=d[p][y];
        }
    }
    cout<<sum;
    return 0;
}