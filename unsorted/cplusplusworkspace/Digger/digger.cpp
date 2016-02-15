#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#define pb push_back
#define mp make_pair
using namespace std;

const int MAXN = 1000, INF = 0xF3F3F3F3;
int A,B,N,E,D = INF;
int dist[MAXN], adj[MAXN][MAXN];
vector< pair< pair<int,int>, pair<int,int> > >arr;
vector< pair<int,int> >coor[MAXN];



int main() {
	freopen("input.txt","r",stdin);
    memset(dist,INF,sizeof dist);
    memset(adj,INF,sizeof adj);
    scanf("%d%d%d",&A,&B,&N);
    for(int i = 0,a,b,c,d; i < N;i++){
        scanf("%d%d%d%d",&a,&b,&c,&d);
        arr.pb(mp(mp(a,b),mp(c,d)));
        D = min(D,a);
        for(int j = b; j <= d;j++){
            coor[i].pb(mp(a,j));
            if(a!=b)coor[i].pb(mp(b,j));
        }
        for(int j = a; j <= c;j++){
            coor[i].pb(mp(j,b));
            if(b!=d)coor[i].pb(mp(j,d));
        }
    }
    scanf("%d%d",&A,&B);
    for(int i = 0; i < N;i++){
        if(A >= arr[i].first.first && A <= arr[i].second.first){
            if(B >= arr[i].first.second && B <= arr[i].second.second){
                E = i;
                break;
            }
        }
    }
    for(int i = 0; i < N;i++){
        for(int j = 0; j < N;j++){
            for(int k = 0;k < coor[i].size();k++)
                for(int h = 0; h < coor[i].size();h++)
                    adj[i][j] = min(adj[i][j],abs(coor[i][k].first - coor[j][h].first)+abs(coor[i][k].second - coor[j][h].second));
        }
    }


	return 0;
}
