/** DISCLAIMER, FAILS ON LAST TESTCASE*/
#include<iostream>
#include<cstdio>
#include<cctype>
#define max(a,b) a>b?a:b

using namespace std;

int R,C;
char g[100][100];
int dp[2][100][100];

void reset(){
    for(int i = 0;i < 2;i++)
        for(int j = 0;j < 100;j++)
            for(int k = 0; k < 100;k++)
                dp[i][j][k] = 0;
}
int main(){
    //freopen("in.txt","r",stdin);
    while(true){
        scanf("%d%d",&R,&C);
        if(R == 0 && C == 0)break;

        for(int i = 0; i < R;i++)
            for(int j = 0; j < C;j++)
                scanf(" %c",&g[i][j]);
        reset();
        for(int j = 0; j < C;j++){
            //up
            for(int i = R-1;i >= 0;i--){
                if(g[i][j] == '*')
                    continue;
                if(i+1 <= R-1 && j-1 >= 0)
                    dp[0][i][j]   = max(dp[0][i+1][j],dp[0][i][j-1]);
                else if(i+1 <= R-1)
                    dp[0][i][j]   = dp[0][i+1][j];
                else if(j-1 >= 0)
                    dp[0][i][j] = dp[0][i][j-1];
                if(isdigit(g[i][j]))
                    dp[0][i][j] += (g[i][j] - '0');
            }

            if(j != 0){
                //down
                for(int i = 0;i < R;i++){
                    if(g[i][j] == '*')
                        continue;
                    if(i-1 >= 0 && j-1 >= 0)
                        dp[1][i][j]   = max(dp[1][i-1][j],dp[1][i][j-1]);
                    else if(i-1 >= 0)
                        dp[1][i][j]   = dp[1][i-1][j];
                    else if(j-1 >= 0)
                        dp[1][i][j] = dp[1][i][j-1];
                    if(isdigit(g[i][j]))
                        dp[1][i][j] += (g[i][j] - '0');
                }
            }
            for(int i = 0;i < R;i++){
                dp[0][i][j] = dp[1][i][j] = max(dp[0][i][j], dp[1][i][j]);
            }
        }
       /* for(int i = 0;i < R;i++){
            for(int j = 0; j < C;j++){
                cout << dp[0][i][j] << " ";
            }
            cout << endl;
        }*/
        printf("%d\n",dp[0][R-1][C-1]);
    }
    return 0;
}
