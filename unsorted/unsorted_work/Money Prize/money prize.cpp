#include<iostream>
#include<fstream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int n;
vector<int>wu;
int dp[300][300];
bool v[300][300];
void rec(int r, int c,int val){
    if(r > n-1 || c > n-1)
        return;
    else if(r == n-1 && c == n-1){
        wu.push_back(val);
        cout << val << endl;
        return;
    }

    if(r+1 < n)
        rec(r+1,c,dp[r+1][c] + val);
    if(c+1 < n)
        rec(r,c+1,dp[r][c+1]+ val);

}
int main(){
    freopen("input.txt","r",stdin);
    cin >> n;
    for(int i = n-1;i >= 0;i--){
        for(int j = 0;j < n;j++){
            cin >> dp[i][j];
        }
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(j >= n-4 && i>=n-4)continue;
            if(i-1 >= 0 && j-1 >= 0)
                dp[i][j] = dp[i][j] + max(dp[i-1][j],dp[i][j-1]);
            else if(i-1 >= 0)
                dp[i][j] = dp[i][j] + dp[i-1][j];
            else if(j-1 >= 0)
                dp[i][j] = dp[i][j] + dp[i][j-1];
        }
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    int t = n-1;
    rec(t-4,t-4,dp[t-4][t-4]);
    rec(t-4,t-3,dp[t-4][t-3]);
    rec(t-4,t-2,dp[t-4][t-2]);
    rec(t-4,t-1,dp[t-4][t-1]);
    rec(t-4,t,dp[t-4][t]);

    rec(t-4,t-4,dp[t-4][t-4]);
    rec(t-3,t-4,dp[t-3][t-4]);
    rec(t-2,t-4,dp[t-2][t-4]);
    rec(t-1,t-4,dp[t-1][t-4]);
    rec(t,t-4,dp[t][t-4]);
    sort(wu.begin(),wu.end());
    for(int i = 0;i < 5;i++)
        cout << wu[i] << endl;
    //cout << wu[1] << endl;
    //cout << dp[n][n] << endl;




    fclose(stdin);
    return 0;
}
