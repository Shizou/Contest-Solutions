#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int T,N,C,d,e,f;
int adj[100][100];
int dist[100];
bool v[100];


struct edge{
    int w,sn,en;
    bool operator < (const edge& rhs) const{
        return w > rhs.w;
    }
};
int prim(){
    priority_queue< edge > pq;
    pq.push( (edge){0,0,0} );
    int MSTNodes = 1, totalWeight = 0;

    v[0] = 1;
    for(int i = 1; i < 100;i++)
        if(adj[0][i] != 300)pq.push( (edge){adj[0][i], 0, i});

   while(MSTNodes < N && !pq.empty()){
        int w = pq.top().w;
        int sn = pq.top().sn;
        int en = pq.top().en;
        pq.pop();
        if(!v[en]){
            v[en] = true;
            MSTNodes++;
            totalWeight+=w;
            for(int i = 0; i < 100;i++){
                if(adj[en][i] != 300 && dist[i] > adj[en][i]){
                    dist[i] = adj[en][i];
                    pq.push((edge){adj[en][i],en,i} );
                }
            }
        }
    }
   return (MSTNodes == N) ? totalWeight:-1;
}
int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&N,&C);
        fill( &adj[0][0], &adj[0][0] + 100*100, 300);
        fill( &dist[0], &dist[0] + 100, 3000);
        fill( &v[0], &v[0] + 100, 0);
        for(int i = 0; i < C;i++){
            scanf("%d%d%d",&d,&e,&f);
            adj[d-1][e-1] = min(adj[d-1][e-1],f);
            adj[e-1][d-1] = min(adj[e-1][d-1],f);
        }
        int ans = prim();
        if(ans == -1)
            printf("Requires more conduits\n");
        else
            printf("%d\n",ans);
    }
}
