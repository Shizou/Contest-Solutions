#include<iostream>
#include<algorithm>
using namespace std;

int N;
int a[1005];
int dp[1005][1005];
int sum;

int main(){
    cin >> N;
    for(int i = 0;i < N;i++){
        cin >> a[i];
        sum += a[i];
    }
    for(int j = 0;j < N;j++){
        for(int i = j;i >= 0;i--){
            if(i==j)dp[i][j] = a[i];
            else if(j==i+1)dp[i][j] = max(a[i], a[j]);
            else{
                dp[i][j] = max(a[i]+min(dp[i+2][j], dp[i+1][j-1]),
                               a[j]+min(dp[i][j-2], dp[i+1][j-1]));
            }
        }
    }
    int ans = dp[0][N-1];
    cout << ans << " " << sum-ans << endl;
    return 0;
}
