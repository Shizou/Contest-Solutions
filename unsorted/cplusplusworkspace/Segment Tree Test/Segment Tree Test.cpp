// my attempt at lazy propagation
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXN = (int)1e5,inf = 0x3f3f3f3f;
int N,M,qlo,qhi,val,a,b,c;
int A[MAXN],tree[4*MAXN],lazy[4*MAXN];
char cmd;

void update(int n,int lo,int hi){
    if(lo > hi || lo > qhi || hi < qlo)
      return;
    else{
      if(lazy[n] != 0) {
         tree[n] = lazy[n];
         if(lo != hi) {
            lazy[2*n+1] = lazy[n];
            lazy[2*n+2] = lazy[n];
         }
         lazy[n] = 0;
      }
      if(lo >= qlo && hi <= qhi){
         tree[n] = val;
         if(lo != hi) {
            lazy[2*n+1] = val;
            lazy[2*n+2] = val;
         }
      }
      else{
            update(2*n+1,lo,(lo+hi)/2);
            update(2*n+2,(lo+hi)/2+1,hi);
            tree[n] = min(tree[2*n+1],tree[2*n+2]);
      }
  }
}
int query(int n,int lo,int hi){
   if(lo > hi || lo > qhi || hi < qlo)
      return inf;
   if(lazy[n] != 0) {
       tree[n] = lazy[n];
       if(lo != hi) {
          lazy[n*2+1] = lazy[n];
          lazy[n*2+2] = lazy[n];
       }
       lazy[n] = 0;
   }
   if(lo >= qlo && hi <= qhi)
      return tree[n];
   return min(query(2*n+1,lo,(lo+hi)/2),query(2*n+2,(lo+hi)/2+1,hi));
}
int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d",&N,&M);N--,M--;
    memset(tree,inf,sizeof(tree));
    memset(lazy,0,sizeof(lazy));
    for(int i = 0;i <= N;++i){
        scanf("%d",&A[i]);
        qlo = i,qhi = i;
        val = A[i];
        update(0,0,N);
    }
    for(int i = 0;i <= M;++i){
        scanf(" %c",&cmd);
        if(cmd == 'Q'){
          scanf("%d%d",&a,&b);
          qlo = a,qhi = b;
          printf("%d\n",query(0,0,N));
        }
        else if(cmd == 'M'){
          scanf("%d%d",&a,&b);
          qlo = qhi = a;
          val = A[a] = b;
          update(0,0,N);
        }
        else if(cmd == 'R'){
          scanf("%d%d%d",&a,&b,&c);
          qlo = a,qhi = b, val = c;
          update(0,0,N);
        }
    }
    return 0;
}