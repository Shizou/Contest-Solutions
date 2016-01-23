#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int M = 32;
int N,a,b,c,d;
bool dp[M][M][M][M];


bool AABDD(int a,int b,int c,int d){return a>=2 && b>=1 && d>=2;}
bool ABCD (int a,int b,int c,int d){return a>=1 && b>=1 && c>=1 && d>=1;}
bool CCD  (int a,int b,int c,int d){return c>=2 && d>=1;}
bool BBB  (int a,int b,int c,int d){return b>=3;}
bool AD   (int a,int b,int c,int d){return a>=1 && d>=1;}

int main(){
    // If any of the moves from the current position lead to a winning position that means
    // that patrick will lose because he is sending roland to a winning position. Otherwise
    // if any any of the current moves lead to a loosing position then patrick wins.
    for(a = 0;a < M;++a){
      for(b = 0;b < M;++b){
        for(c = 0;c < M;++c){
          for(d = 0;d < M;++d){
              bool win = false;
              if(AABDD(a,b,c,d) && !dp[a-2][b-1][c][d-2])
                win = true;
              if(ABCD(a,b,c,d)  && !dp[a-1][b-1][c-1][d-1])
                win = true;
              if(CCD(a,b,c,d)   && !dp[a][b][c-2][d-1])
                win = true;
              if(BBB(a,b,c,d)   && !dp[a][b-3][c][d])
                win = true;
              if(AD(a,b,c,d)    && !dp[a-1][b][c][d-1])
                win = true;
              dp[a][b][c][d] = win;
          }
        }
      }
    }
    scanf("%d",&N);
    for(int i = 0;i < N;i++){
        scanf("%d%d%d%d",&a,&b,&c,&d);
        printf("%s\n",dp[a][b][c][d] ? "Patrick":"Roland");
    }
}
