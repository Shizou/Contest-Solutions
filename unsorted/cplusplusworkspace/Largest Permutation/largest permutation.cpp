#include<bits/stdc++.h>
using namespace std;

const int MAXN = (int)1e5+1;
int N,K,qlo,qhi,val;
int tree[4*MAXN];
map<int,int>idx;

void update(int n,int lo,int hi){
     if(lo > hi || lo > qhi || hi < qlo)
        return;
     if(lo >= qlo && hi <= qhi)
        tree[n] = val;
     else{
        update(2*n+1,lo,(lo+hi)/2);
        update(2*n+2,(lo+hi)/2+1,hi);
        tree[n] = max(tree[2*n+1],tree[2*n+2]);
     }
}
int query(int n,int lo,int hi){
   if(lo > hi || lo > qhi || hi < qlo)
      return 0;
   if(lo >= qlo && hi <= qhi)
      return tree[n];
   else
      return max(query(2*n+1,lo,(lo+hi)/2),query(2*n+2,(lo+hi)/2+1,hi));
}
int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d",&N,&K);N--;
    memset(tree,0,sizeof(tree));
    for(int i = 0;i <= N;++i){
        scanf("%d",&val);
        idx[val] = i;
        qlo = qhi = i;
        update(0,0,N);
    }
    for(int i = 0;i <= N && K > 0;++i){
        qlo = qhi = i;
        int t = query(0,0,N);
        qlo = i+1,qhi = N;
        int t2 = query(0,0,N);
        if(t < t2){
           idx[t] = idx[t2];
           idx[t2] = i;
           qlo = qhi = i,val = t2;
           update(0,0,N);
           qlo = idx[t],qhi = idx[t],val = t;
           update(0,0,N);
           K--;
        }
    }
    for(int i = 0;i <= N;++i){
        qlo = qhi = i;
        printf("%d ",query(0,0,N));
    }printf("\n");
    return 0;
}