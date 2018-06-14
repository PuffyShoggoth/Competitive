#include <bits/stdc++.h>
using namespace std;
bool cameras[100005];
int main() {
    int n, k, r;
    scanf("%i%i%i", &n, &k, &r);
    int tp;
    for(int i = 0; i<k; i++){
        scanf("%i", &tp); cameras[tp]=1;
    }
    int tn = 0;
    int tt = 0;
    for(int i = 1; i<=r; i++){tn+=cameras[i]; }
    if(tn==0){tt+=2; cameras[r]=1; cameras[r-1]=1; tn = 2;}
    else if(tn==1){ tt++; if(!cameras[r]){cameras[r]=1;}else{cameras[r-1]=1;} tn=2;}
    for(int i = r+1; i<=n; i++){
        if(cameras[i-r]){tn--;}
        tn+=cameras[i];
        if(tn==1){cameras[i]=1; tt++; tn++;}
    }
    printf("%i", tt);
    return 0;
}