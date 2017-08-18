#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN = 2000;
int N,W,ans,c2,r2;
int presum[MAXN][MAXN];
char G[MAXN][MAXN];

int main() {
  freopen("input.txt","r",stdin);
  scanf("%d",&N);
  for(int r = 0;r < N;r++){
    for(int c = 0;c < N;c++){
            scanf(" %c",&G[r][c]);
            if(G[r][c] == '#')
               presum[r][c]+= ((c-1 >=0) ? presum[r][c-1]:0)+1;
    }
  }
  for(int r = 0;r < N;r++){
    for(int c = 0;c < N;c++){
            if(G[r][c] == '#'){
                W = 1;
                c2 = c,r2 = r;
                while(c2 < N && r2 < N && presum[r2][c2] >= W){
                    ans++;
                    c2++;
                    r2++;
                    W+=2;
                }
            }
    }
  }
  printf("%d\n",ans);
  return 0;
}
