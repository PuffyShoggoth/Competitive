#include <iostream>
#include <string>
using namespace std;
int s[67];

int main(){
    int n;
    cin>>n;
    int h;
    for (int i=0; i<n; i++){
        cin>>h;
        s[h]+=1;
    }
    if (n==0){cout<<0;}
    else{
       for (int i=n; i>=0; i--){
          if (i==0){
              if (s[0]==0){cout<<0;}
             else{cout<<"Paradox!";}
             break;}
          if  (s[i]==i){
             cout<<i;
             break;}
       }
    }
    return 0;
}