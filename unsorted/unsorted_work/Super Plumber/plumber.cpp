#include<iostream>
#include<cstdio>
#include<cctype>
#define max(a,b) a>b?a:b

using namespace std;

int R,C;
char g[100][100];
bool v[100][100];
int dp[2][100][100];

void reset(){
    for(int i = 0;i < 2;i++)
        for(int j = 0;j < 100;j++)
            for(int k = 0; k < 100;k++)
                dp[i][j][k] = 0;
    for(int i = 0; i < 100;i++)
        for(int j = 0;j < 100;j++)
            v[i][j] = false;
}
void r(int x, int y){
    if(x < 0 || y < 0 || x > R-1 || y > C-1 || v[x][y])return;
    v[x][y] = true;
    if(g[x][y] == '*')return;
    r(x-1,y);
    r(x+1,y);
    r(x,y+1);
}
int main(){
    freopen("S5.4.data","r",stdin);
    while(true){
        scanf("%d%d",&R,&C);
        if(R == 0 && C == 0)break;

        for(int i = 0; i < R;i++)
            for(int j = 0; j < C;j++)
                scanf(" %c",&g[i][j]);
        reset();
        r(R-1,0);
        for(int j = 0; j < C;j++){
            //up
            for(int i = R-1;i >= 0;i--){
                if(g[i][j] == '*' || !v[i][j])
                    continue;
                if(i+1 <= R-1 && j-1 >= 0){
                    if(v[i][j-1] && v[i+1][j])
                        dp[0][i][j]   = max(dp[0][i+1][j],dp[0][i][j-1]);
                    else if(v[i+1][j])
                        dp[0][i][j]   = dp[0][i+1][j];
                    else
                        dp[0][i][j] = dp[0][i][j-1];
                }
                else if(i+1 <= R-1 && v[i+1][j])
                    dp[0][i][j]   = dp[0][i+1][j];
                else if(j-1 >= 0 && v[i][j-1])
                    dp[0][i][j]   = dp[0][i][j-1];
                if(isdigit(g[i][j]))
                    dp[0][i][j]  += (g[i][j] - '0');
            }

            if(j != 0){
                //down
                for(int i = 0;i < R;i++){
                    if(g[i][j] == '*' || !v[i][j])
                        continue;
                    if(i-1 >= 0 && j-1 >= 0){
                        if(v[i][j-1] && v[i-1][j])
                            dp[1][i][j]   = max(dp[1][i-1][j],dp[1][i][j-1]);
                        else if(v[i-1][j])
                            dp[1][i][j] = dp[1][i-1][j];
                        else
                            dp[1][i][j] = dp[1][i][j-1];
                    }
                    else if(i-1 >= 0 && v[i-1][j])
                        dp[1][i][j]   = dp[1][i-1][j];
                    else if(j-1 >= 0 && v[i][j-1])
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
                printf("%c",(v[i][j]) ? '1':'0');
            }
            cout << endl;
        }*/
        printf("%d\n",dp[0][R-1][C-1]);
    }
    return 0;
}
