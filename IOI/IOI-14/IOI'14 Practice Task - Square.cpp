#include<iostream>
#include<cstdio>
#include<algorithm>
#define lowbit(x)x&(-x)
using namespace std;

const int MAXN = 1010;
int N,B,BO;
int tree[MAXN][MAXN];

void update(int r,int c,int v){
    for(int i = r;i <= MAXN;i+=lowbit(i))
      for(int j = c;j <= MAXN;j+=lowbit(j))
          tree[i][j]+=v;
}
int sum(int r,int c){
    int ret = 0;
    for(int i = r;i > 0;i-=lowbit(i))
        for(int j = c;j > 0;j-=lowbit(j))
            ret+=tree[i][j];
    return ret;
}
int sum(int r1,int c1,int r2,int c2){
    return sum(r2,c2)-sum(r1-1,c2)-sum(r2,c1-1)+sum(r1-1,c1-1);
}
int main(){
    scanf("%d",&N);
    for(int r = 1;r <= N;++r){
        for(int c = 1, k = 0;c <= N;++c){
            scanf("%d",&k);
            update(r,c,k);
        }
    }
    B = 0,BO = 0;
    for(int r = 1;r <= N;++r){
      for(int c = 1;c <= N;++c){
        for(int k = B,m = min(N-r,N-c);k <= m;k++){
            if(sum(r,c,r+k,c+k) == (k+1)*(k+1)){
                if(k == B)    BO++;
                else if(k > B)B = k,BO = 1;
            }else
              break;
        }
      }
    }
    printf("%d\n",(B+1)*BO);
    return 0;
}
