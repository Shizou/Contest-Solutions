#include<iostream>
#include<cmath>
#include<string.h>

using namespace std;

int n,t;
int dp[26][1441];

int main(){
       t = 5;
        while(t--){
            cin >> n;
            int f[n+1];
            for(int i = 1;i <= n;i++)cin >> f[i];
            for(int i = 0;i <= 1440;i++)dp[0][i] = 0;
            for(int i = 0;i <= n;i++)dp[i][0] = 0;

            for(int x = 1;x <= n;x++){
                for(int y = 0;y <= 1440 ;y++){
                    if(f[x] <= y ) dp[x][y] = max( dp[x-1][y], f[x] + dp[x-1][ y-f[x]] );
                    else          dp[x][y] = dp[x-1][y];
                }
            }
            cout << 1440-dp[n][1440] << endl;
            memset(dp,0,sizeof dp);
        }
    return 0;
}
