#include<stdio.h>
#include<vector>
#include<queue>
#include<cmath>

using namespace std;

int N,K,M;

int g[25][25];
int dist[25][25];
bool v[25][25];


int dijkstra(){
    priority_queue< pair<int, pair<int,int> > > pq;
    pq.push( make_pair(0, make_pair(0,0)));

    while(!pq.empty()){
        int o = (-pq.top().first);
        int x = pq.top().second.first;
        int y = pq.top().second.second;

        pq.pop();

        if(v[x][y])continue;
        v[x][y] = true;

        if(dist[x][y] > o)     dist[x][y] = o;
        else if(dist[x][y] < 0)continue;

        if(x == N-1 && y == N-1)
            return o;

      //  printf("X: %d Y: %d\n",x,y);
        if(x+1 <= N-1){
            if( abs(g[x+1][y]-g[x][y]) <= 2 ){
                pq.push( make_pair( -( o +  ((g[x+1][y] > M || g[x][y] > M) ? 1:0) ) , make_pair(x+1,y)));

            }
        }
        if(x-1 >= 0){
            if( abs(g[x-1][y]-g[x][y]) <= 2 ){
                pq.push( make_pair(-(o + ((g[x-1][y] > M || g[x][y] > M) ? 1:0) ), make_pair(x-1,y)));
            }
        }
        if(y+1 <= N-1){
            if( abs(g[x][y+1]-g[x][y]) <= 2 ){
                pq.push( make_pair(-(o + ((g[x][y+1] > M || g[x][y] > M) ? 1:0)), make_pair(x,y+1)));
            }
        }
        if(y-1 >= 0){
            if( abs(g[x][y-1]-g[x][y]) <= 2 ){
                pq.push( make_pair(-(o + ((g[x][y-1] > M || g[x][y] > M) ? 1:0) ), make_pair(x,y-1)));
            }
        }

    }
    return -1;
}
int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&K);
    while(K--){
        scanf("%d",&N);
        for(int i = 0;i < N;i++){
            for(int j = 0;j < N;j++){
                scanf("%d",&g[i][j]);
                v[i][j] = 0;
                dist[i][j] = 250000;
            }
        }
        M = g[0][0];
        int ans = dijkstra();
        if(ans == -1) printf("CANNOT MAKE THE TRIP\n");
        else          printf("%d\n",ans);
    }
   // fclose(stdin);
}
