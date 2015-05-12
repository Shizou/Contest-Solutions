#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define db 0
#define lb(x)((x)&(-x))
using namespace std;

int L,T;

map<int, map<int,int> >tree;

void update(int r,int c,int v){
    for(c = c; c <= L;c+=lb(c))
        tree[r][c]+=v;
}
int sum(int r,int c){
    int s = 0;
    for(c = c;c > 0;c-=lb(c))
        s+=tree[r][c];
    return s;
}
int sum(int r,int c1,int c2){
    return sum(r,c2)-sum(r,c1-1);
}

int inconvenience(int r,int c){
    int w = 1,s = 0;
    map<int,map<int,int> >::iterator it = tree.begin();
    for(it = it; it!=tree.end();it++)
        if(it->first == r)break;
    for(it++;it!=tree.end();it++){
        w = it->first-r;
        if(c-w < 0 && c+w > L)
           s+=sum(it->first,1,L);
        else if(c-w > 0 && c+w <= L)
           s+=sum(it->first,c-w,c+w);
        else if(c-w > 0)
           s+=sum(it->first,c-w,L);
        else if(c+w <= L)
           s+=sum(it->first,1,c+w);
    }
    return s;
}
int main(){
    freopen("input.txt","r",stdin);
    scanf("%d%d",&L,&T);
    for(int i = 0;i < T;++i){
        char a;int r,c;
        scanf(" %c%d%d",&a,&r,&c);
        if(a == 'E')
           update(r,c,1);
        else if(a == 'L')
           update(r,c,-1);
        else if(a == 'S'){
            if(tree.count(r) && sum(r,c,c+1) > 0)
               printf("No\n");
            else
               printf("%d %d\n",inconvenience(r,c),inconvenience(r,c+1));
        }
    }
    return 0;
}
