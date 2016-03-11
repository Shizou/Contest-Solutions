#include<bits/stdc++.h>
#define MAXN 155
#define inf 0x3f3f3f3f
using namespace std;

struct edge{int u, v, w;};

int n, m, q;
vector<edge>E;

// we will detect for a negative cycle
bool bellman_ford(int nodes, int start)
{
    long long dist[MAXN];
    for(int i = 0;i < nodes;i++)
    {
        dist[i] = inf;
    }
    dist[start] = 0;
    for(int i = 0;i < nodes;i++)
    {
        for(int j = 0;j < (int)E.size();j++)
        {
            if(dist[E[j].v]  > dist[E[j].u]+E[j].w)
            {
                dist[E[j].v] = dist[E[j].u]+E[j].w;
            }
        }
    }
    // find negative cycles
    for(int i = 0;i < (int)E.size();i++)
    {
        if(dist[E[i].v] > dist[E[i].u] + E[i].w)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    freopen("input.txt","r",stdin);
    while(true)
    {
        cin >> n >> m >> q;
        if(n == 0 && m == 0 && q == 0)
            break;

        long long dist[MAXN][MAXN];
        memset(dist, inf,sizeof(dist));
        E.clear();
        for(int i = 0;i < m;i++)
        {
            int u,v,w;
            cin >> u >> v >> w;
            E.push_back( (edge){u,v,w});
            dist[u][v] = w;
        }
        // just set edges to themselves to 0
        for(int i = 0;i < n;i++)
        {
            dist[i][i] = 0;
        }
        // perform floyd warshall
        for(int k = 0;k < n;k++)
        {
          for(int u = 0;u < n;u++)
          {
              for(int v = 0;v < n;v++)
              {
                  dist[u][v] = min(dist[u][v],dist[u][k]+dist[k][v]);
              }
          }
        }
        bool negative_cycle[MAXN];
        for(int i = 0;i < n;i++)
        {
            negative_cycle[i] = bellman_ford(n, i);
        }
        for(int i = 0;i < q;i++)
        {
            int u,v;
            cin >> u >> v;
            if(negative_cycle[u] || negative_cycle[v])
                cout << "-Infinity" << endl;
            else if(dist[u][v] != 4557430888798830399LL)
                cout << dist[u][v] << endl;
            else
                cout << "Impossible" << endl;
        }
        // reset everything
        cout << endl;
    }
    return 0;
}