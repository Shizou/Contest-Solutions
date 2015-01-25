#include<iostream>
#include<cstdio>
#include<vector>
#include<cctype>
#include<queue>
#include<cmath>
#include<algorithm>
#define mp make_pair
#define pb push_back
using namespace std;

int N,min_d,tot_d;
vector< pair<int,int> >loc;

int dist(int x1,int y1, int x2,int y2){
    return abs(x1-x2)+abs(y1-y2);
}
int main(){
    scanf("%d",&N);
    for(int i = 0,x,y; i < N;i++){
        scanf("%d%d",&x,&y);
        loc.pb(mp(x,y));
    }
    for(int i = 0; i < N-1;i++){
        tot_d += dist(loc[i].first, loc[i].second,loc[i+1].first,loc[i+1].second);
        min_d = tot_d;
    }
    for(int i = 1; i < N-1;i++){
        int diff = dist(loc[i-1].first,loc[i-1].second,loc[i+1].first,loc[i+1].second);
        int diff2 = dist(loc[i-1].first,loc[i-1].second,loc[i].first,loc[i].second) + dist(loc[i].first,loc[i].second,loc[i+1].first,loc[i+1].second);
        int path = tot_d - (diff2-diff);
        min_d = min(min_d,path);
    }
    printf("%d\n",min_d);
    return 0;
}

