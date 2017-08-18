#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define lb(x) ((x)&(-x))
#define db 0
using namespace std;


const int MAXN = (int)1e5+1,MAXR = 7;
int N,M;
int tree[MAXN][MAXR];


void update(int r,int c,int v){
    for(r=r;r <= N;r+=lb(r))
        for(c=c;c <= M;c+=lb(c))
            tree[r][c]+=v;
}
int sum(int r,int  c){
    int s = 0;
    for(r=r;r > 0;r-=lb(r))
        for(c=c;c > 0;c-=lb(c))
            s+=tree[r][c];
    return s;
}
int sum(int r1,int c1,int r2,int c2){
    return sum(r2,c2)-sum(r1-1,c2)-sum(r2,c1-1)+sum(r1-1,c1-1);
}
int main(){
    freopen("input.txt","r",stdin);
    update(1,1,2);
    printf("%d\n",sum(1,1,1,1));
    return 0;
}