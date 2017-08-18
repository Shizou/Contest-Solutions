#include<bits/stdc++.h>
#define lowbit(x) x&-x
using namespace std;

int R,C,S,ans,N;
map<int,map<int,int> >tree;

void update(int r,int c,int val){
    for(int i = r;i <= R;i+=lowbit(i))
        for(int j = c;j <= C;j+=lowbit(j))
            tree[i][j]+=val;
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
    freopen("input.txt","r",stdin);
    scanf("%d%d%d",&R,&C,&S);
    for(int r = 1;r <= R;r++){
        for(int c = 1;c <= C;c++){
            char g;
            scanf(" %c",&g);
            if(g == 'X')
                update(r,c,1);
        }
    }
    for(int r = 1;r <= R;r++)
        for(int c = 1;c <= C;c++)
            if(r+S-1 <= R && c+S-1 <= C && sum(r,c,r+S-1,c+S-1) > 0)
               ans += sum(r,c,r+S-1,c+S-1),N++;

    printf("%.8f\n",(double)(ans)/N);
    return 0;
}