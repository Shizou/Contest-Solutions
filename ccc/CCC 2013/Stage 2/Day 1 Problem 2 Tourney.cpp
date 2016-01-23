#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define db 0
#define all(x)(x).begin(),(x).end()
#define x first
#define y second
using namespace std;

const int MAXN = (1<<20)+5,inf = 0x3f3f3f3f;
int N,M,I,S,qlo,qhi,idx;
int arr[MAXN],best[4*MAXN],tree[4*MAXN];
char cmd;
map<int,int>score_to_index;

int query(int n,int lo,int hi){
    if(lo > hi || lo > qhi || hi < qlo)
       return -inf;
    else if(lo >= qlo && hi <= qhi)
       return tree[n];
    else
       return max(query(2*n,lo,(lo+hi)/2),query(2*n+1,(lo+hi)/2+1,hi));
}
int query2(int n,int lo,int hi){
    if(lo > hi || lo > qhi || hi < qlo)
       return 0;
    else if(tree[n] == arr[idx])
       return best[n];
    else
       return max(query2(2*n,lo,(lo+hi)/2) , query2(2*n+1,(lo+hi)/2+1,hi));
}
void update(int n,int lo,int hi){
    if(idx >= lo && idx <= hi){
       if(lo == hi)
          tree[n] = arr[lo];
       else{
          update(2*n,lo,(lo+hi)/2);
          update(2*n+1,(lo+hi)/2+1,hi);
          tree[n] = max(tree[2*n],tree[2*n+1]);
          best[n] = max(best[2*n],best[2*n+1]) + 1;
       }
    }
}

int main(){
    freopen("Input/tourney.0.in","r",stdin);
    memset(tree,-inf,sizeof(tree));
    scanf("%d%d",&N,&M);N = (1<<N);
    for(int i = 1;i <= N;++i){
        scanf("%d",&arr[i]);
        idx = i;
        score_to_index[arr[i]] = i;
        update(1,1,N);
    }
    for(int i = 1;i <= M;++i){
        scanf(" %c",&cmd);
        if(cmd == 'R'){
          scanf("%d%d",&I,&S);
          score_to_index[S] = I;
          arr[I] = S;
          qlo = qhi = idx = I;
          update(1,1,N);
        }
        if(cmd == 'W'){
          qlo = 1,qhi = N;
          printf("%d\n",score_to_index[query(1,1,N)]);
        }
        if(cmd == 'S'){
          scanf("%d",&I);
          idx = qlo = qhi = I;
          printf("%d\n",query2(1,1,N));
        }
    }
    return 0;
}