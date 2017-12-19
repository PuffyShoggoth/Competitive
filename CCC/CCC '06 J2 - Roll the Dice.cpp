#include <iostream>
#include <string>
using namespace std;

int main(){
   int n, m, s;
   s=0;
   cin >> n;
   cin >> m;
   if (n>10) {
       n=10;
    }
   if (m>10) {
       m=10;
   }
   for (int i=1; i<=m; i++){
       for (int k=1; k<=n; k++){
           if ((i+k)==10){
               s++;}
       }
   }
   if (s==1){
       cout<<"There is "<<s<<" way to get the sum 10.";
   }
   else {
       cout<<"There are "<<s<<" ways to get the sum 10.";}
   return 0;
}