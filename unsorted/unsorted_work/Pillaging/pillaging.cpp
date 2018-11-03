#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#define mp make_pair
#define pb push_back
#define MAXN 100000
#define side(x) x.second.second
#define val(x) x.second.first
using namespace std;

int N,T;
int p,x,s;

enum dir {LEFT, RIGHT};
vector< pair<int, pair<int,int> > > v;


int main(){
    freopen("input.txt","r",stdin);
    scanf("%d%d",&N,&T);
    for(int i = 0; i < N;++i){
        scanf("%d%d%d",&p,&x,&s);
        v.pb(mp(p,mp(x,s)));
    }
    v.pb(mp(0, mp(0, 0)));
    sort(v.begin(),v.end());
    int DP[MAXN] = {0};
    int last_left = 0;
    int last_right = -1;
    int ans = 0;
    for(int i = 1; i < N+1;++i){
        if(side(v[i]) == LEFT){
            DP[i] = max(DP[i], DP[last_left] + val(v[i]));
            if(last_right != -1)
                DP[i] = max(DP[i], DP[last_right] + val(v[i]) - T);
            last_left = i;
        } else if (side(v[i]) == RIGHT){
            DP[i] = max(DP[i], DP[last_left] + val(v[i]) - T);
            if(last_right != -1)
                DP[i] = max(DP[i], DP[last_right] + val(v[i]));
            last_right = i;
        }
        ans = max(ans, DP[i]);
    }
    printf("%d\n", ans);
    return 0;
}
