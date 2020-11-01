#include<iostream>
#include<map>
using namespace std;

int N;
int dp[5000][5000];
string a;


int main(){
    cin >> N >> a;
    for(int j = 0;j < N;j++){
        for(int i = j;i >= 0;i--){
            if(i==j)              dp[i][j] = 0;
            else if(j==i+1)       dp[i][j] = (a[i] == a[j]) ? 0: 1;
            else if(a[i] == a[j]) dp[i][j] = dp[i+1][j-1];
            else if(a[i] != a[j]) dp[i][j] = dp[i+1][j-1]+2;
        }
    }
    cout << dp[0][N-1] << endl;
    return 0;    
}
