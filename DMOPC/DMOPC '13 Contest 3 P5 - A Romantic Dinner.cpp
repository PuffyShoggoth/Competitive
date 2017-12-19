#include <iostream>
#include <utility>

using namespace std;
int dates[155][305][105];
int rants[155][3];
int main()
{
  int tm, food, rest;
  cin>>tm>>food>>rest;
  for (int i=1; i<=rest; i++){
     cin>>rants[i][0]>>rants[i][1]>>rants[i][2];
  }
  for (int i=1; i<=rest; i++){
      for (int j=0; j<=tm-rants[i][1]; j++){
          for (int k=0; k<=food-rants[i][2]; k++){
              dates[i][j+rants[i][1]][k+rants[i][2]]=max(dates[i-1][j+rants[i][1]][k+rants[i][2]], dates[i-1][j][k]+rants[i][0]);
              dates[i][j][k]=max(dates[i][j][k], dates[i-1][j][k]);
          }
          for (int k=food-rants[i][2]+1; k<=food; k++){
              dates[i][j][k]=max(dates[i][j][k], dates[i-1][j][k]);}
      for (int j=tm-rants[i][1]+1; j<=tm; j++){
          for (int k=0; k<=food; k++){
              dates[i][j][k]=max(dates[i][j][k], dates[i-1][j][k]);}
      }
      }
  }
   int biggy=0;
   for (int j=1; j<=tm; j++){
          for (int k=0; k<=food; k++){
             biggy=max(biggy, dates[rest][j][k]);} 
   }
   cout<<biggy;
   return 0;
  
}