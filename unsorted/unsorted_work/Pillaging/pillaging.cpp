#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#define mp make_pair
#define pb push_back
#define MAXN 100000
using namespace std;

int N,T;
int p,x,s;

vector< pair<int, pair<int,int> > > v;
int main(){
    freopen("input.txt","r",stdin);
    scanf("%d%d",&N,&T);
    for(int i = 0; i < N;++i){
        scanf("%d%d%d",&p,&x,&s);
        v.pb(mp(p,mp(x,s)));
    }
    sort(v.begin(),v.end());
    int dp[MAXN] = {0};
    for(int i = 1; i < N;++i){

    }
    return 0;
}
