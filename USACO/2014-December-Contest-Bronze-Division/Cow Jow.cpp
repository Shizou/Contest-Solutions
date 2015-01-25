#include<iostream>
#include<cstdio>
#include<vector>
#include<cctype>
#include<queue>
#include<cmath>
#include<algorithm>
#define MAXN (int)1e5
#define mp make_pair
#define pb push_back
using namespace std;

int N;
int root[MAXN];
int size[MAXN];
vector< pair<int,int> >cow;

int find_root(int x){
    if(root[x]!=x)root[x]=find_root(root[x]);
    return root[x];
}
bool merge(int x, int y){
    x = find_root(x);
    y = find_root(y);
    if(x==y)return false;
    if(cow[x].second < cow[y].second){
        root[y] = root[x];
        size[x]++;
        size[y]--;
    }
    else if(cow[y].second < cow[x].second){
        root[x] = root[y];
        size[y]++;
        size[x]--;
    }
    return true;
}
int main(){
    scanf("%d",&N);
    for(int i = 0,d,s; i < N;i++){
        scanf("%d%d",&d,&s);
        cow.pb(mp(d,s));
        root[i] = i;
        size[i] = 1;
    }
    bool change = true;
    while(change){
        change = false;
        for(int i = N-1; i >= 1;i--){
            if(cow[root[i]].second < cow[root[i-1]].second){
                if(merge(i,i-1)){
                    change = true;
                }
            }
        }
    }
    int g = 0;
    for(int i = 0; i < N;i++)
        if(size[i] > 0)g++;
    printf("%d\n",g);
    return 0;
}
