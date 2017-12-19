#include <iostream>
#include <utility>

using namespace std;
int spots[1005][1005];
int dp[1005][1005];
int main()
{
    int x, y;
    cin>>x>>y;
    for (int i=0; i<y; i++){
        for (int j=0; j<x; j++){
            cin>>spots[i][j];
        }
    }
    int gx, gy;
    cin>>gx>>gy;
    dp[0][0]=spots[0][0];
    for (int j=1; j<x; j++){
        dp[0][j]=spots[0][j]+dp[0][j-1];}
    for (int i=1; i<=gy; i++){
        dp[i][0]=spots[i][0]+dp[i-1][0];
        for (int j=1; j<x; j++){
            dp[i][j]=spots[i][j]+min(dp[i-1][j], dp[i][j-1]);
        }
        dp[i][x-1]=spots[i][x-1]+min(dp[i][x-2], dp[i-1][x-1]);
        for (int j=1; j<x; j++){
            dp[i][x-j-1]=min(dp[i][x-j-1], spots[i][x-j-1]+min(dp[i-1][x-j-1], dp[i][x-j]));
        }
    }
    int best=dp[gy][gx];
    cout<<best<<endl;

    return 0;
    }