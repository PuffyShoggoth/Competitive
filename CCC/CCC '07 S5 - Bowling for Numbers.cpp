#include <iostream>
#include <numeric>
#include <functional>
using namespace std;

int main(){
    int times;
    cin>>times;
    for (int k=0; k<times; k++){
      int a, b, w;
      cin>>a>>b>>w;
      int s[a], su[a/w+(a-a/w)];
      for (int j=0; j<a; j++){
          cin>>s[j];
      }
      for (int i=0; i<a-w; i++){
          su[i]=accumulate(s+i, s+i+w, 0);
      }
      for (int i=a-w; i<a; i++){
          su[i]=accumulate(s+i, s+a, 0);
      }
      int derp[b][a/w+(a-a/w)];
      derp[0][0]=su[0];
      for (int p=1; p<a/w+(a-a/w); p++){
           derp[0][p]=max(derp[0][p-1], su[p]);
           }
      for (int q=1; q<b; q++){
            derp[q][0]=derp[q-1][0];
      		for (int p=1; p<a/w+(a-a/w); p++){
                if (p-w<0){ 
                  derp[q][p]=max(derp[q-1][p], derp[q][p-1]);}
                else{
                  derp[q][p]=max(derp[q-1][p-w]+su[p], derp[q][p-1]);
                  }
             }
           }
      cout<<derp[b-1][a/w+(a-a/w)-1]<<endl;
      }
      
}