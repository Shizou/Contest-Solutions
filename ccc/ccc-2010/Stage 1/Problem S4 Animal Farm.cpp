#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define db 0
#define all(x)(x).begin(),(x).end()
#define x first
#define y second
using namespace std;

struct corners{
    int w,pen1,pen2;
};

const int MAXN = 500,INF = 0x3F3F3F3F;
int N,E;

corners c[MAXN][MAXN];
vector< pair<int,int> >adj[MAXN];
bool v[MAXN];

int prim(int n){
    priority_queue< pair<int,pair<int,int> > >pq;
    int MSTNodes = 1, totWeight = 0;
    for(int i = 0; i < adj[1].size();i++)
            if(adj[1][i].x <= n)
                pq.push(mp(-adj[1][i].y,mp(1,adj[1][i].x)));
    memset(v,false,sizeof v);
    v[1] = true;
    while(MSTNodes < n && !pq.empty()){
        int w = -pq.top().x;
        int sn = pq.top().y.x;
        int en = pq.top().y.y;
        pq.pop();
        if(v[sn] && !v[en]){
            MSTNodes++;
            totWeight+=w;
            v[en] = true;
            for(int i = 0; i < adj[en].size();i++)
                if(adj[en][i].x <= n)
                    pq.push(mp(-adj[en][i].y,mp(en,adj[en][i].x)));
        }
    }
    return MSTNodes == n ? totWeight:INF;
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&N);
    for(int i = 0; i < MAXN;i++)
        for(int j = 0; j < MAXN;j++)
                c[i][j].w = c[i][j].pen1 = c[i][j].pen2 = INF;
    for(int i = 0; i < N;i++){
        scanf("%d",&E);
        int tc[E],w[E];
        for(int j = 0; j < E;j++)
            scanf("%d",&tc[j]);
        for(int j = 0; j < E;j++)
            scanf("%d",&w[j]);
        for(int j = 0; j < E;j++){
            int corner[] = {tc[j],tc[(j+1)%E]};
            sort(corner,corner+2);
            if(c[corner[0]][corner[1]].pen1 == INF)
                c[corner[0]][corner[1]].pen1 = i+1;
            else
                c[corner[0]][corner[1]].pen2 = i+1;
            c[corner[0]][corner[1]].w = w[j];
        }
    }
    for(int i = 0; i < MAXN;i++){
        for(int j = 0; j < MAXN;j++){
            if(c[i][j].pen1 != INF && c[i][j].pen2 != INF){// not connected to outside because declared twice
                adj[c[i][j].pen1].pb(mp(c[i][j].pen2,c[i][j].w));
                adj[c[i][j].pen2].pb(mp(c[i][j].pen1,c[i][j].w));
            }
            else if(c[i][j].pen1 != INF && c[i][j].pen2 == INF){// connected to outside because declared once
                adj[c[i][j].pen1].pb(mp(N+1,c[i][j].w));
                adj[N+1].pb(mp(c[i][j].pen1,c[i][j].w));
            }
        }
    }
    int ans1 = prim(N),ans2 = prim(N+1);
    printf("%d\n",min(ans1,ans2));
    return 0;
}

