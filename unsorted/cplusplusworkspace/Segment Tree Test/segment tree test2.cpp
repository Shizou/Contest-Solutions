#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = (int)1e5+1,inf = 0x3f3f3f3f;
int N,M;
int A[MAXN],T[4*MAXN];

int query(int n,int lo,int hi,const int&qlo,const int&qhi){
    if(lo > qhi || hi < qlo)
        return inf;
    else if(lo >= qlo && hi <= qhi)
        return T[n];
    else
        return min(query(2*n+1,lo,(lo+hi)/2,qlo,qhi),query(2*n+2,(lo+hi)/2+1,hi,qlo,qhi));
}

void update(int n,int lo,int hi,const int &idx){
    if(idx >= lo && idx <= hi){
        if(lo == hi)
            T[n] = A[lo];
        else{
            update(2*n+1,lo,(lo+hi)/2,idx);
            update(2*n+2,(lo+hi)/2+1,hi,idx);
            T[n] = min(T[2*n+1],T[2*n+2]);
        }
        printf("%d [%d,%d] : %d\n",n,lo,hi,T[n]);
    }
}

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d%d",&N,&M);N--,M--;
    memset(A,inf,sizeof(A));
    memset(T,inf,sizeof(T));
    for(int i = 0;i <= N;i++){
        scanf("%d",&A[i]);
        update(0,0,N,i);
    }
    char cmd;
    for(int i = 0,a = 0,b = 0;i <= M;i++){
        scanf(" %c%d%d",&cmd,&a,&b);
        if(cmd == 'Q')
            printf("%d\n",query(0,0,N,a,b));
        else{
            A[a]=b;
            update(0,0,N,a);
        }
    }
    return 0;
}
