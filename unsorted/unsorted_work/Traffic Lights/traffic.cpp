#include<stdio.h>
#include<queue>
#include<vector>

using namespace std;

int N,K,a,b,c;

vector< pair<int,int> > adj[1001];
vector< pair<int,int> > lht;
vector<int> dist(1001,250000);

vector<bool> swch(1001,true);
vector<bool>v(1001,false);

int r(int d, int node){

    if(swch[node]){
        if(d-lht[node].first >= 0){
            d-=lht[node].first;
            swch[node] = 0;
        }
        else
            return d;
    }
    else{
        if(d-lht[node].second >= 0){
            d-=lht[node].second;
            swch[node] = 1;
        }
        else
            return d;
    }
    return r(d,node);

}
int dijkstra(){
    priority_queue< pair<int,int> > pq;

    for(int i = 0;i < adj[0].size();i++){
        pq.push( make_pair( -(adj[0][i].second), adj[0][i].first ) );
    }
    v[0] = 1;
    //pq.push(make_pair(0,0));

    while(!pq.empty()){
        int d = -(pq.top().first);
        int n = pq.top().second;


        pq.pop();

        if(v[n])continue;
        v[n] = true;

        if(dist[n] > d)      dist[n] = d;
        else if(dist[n] < d) continue;
       // printf("N: %d ; D: %d ;\n", n+1,d);
        if(n == K-1){
            return d;
        }
        int rt = r(d,n);

        for(int i = 0;i < adj[n].size();i++){
            if(swch[n]) {
                if(!v[adj[n][i].first]){
                    pq.push( make_pair( -(d+adj[n][i].second), adj[n][i].first ) );
                   // printf("Going to node %d with distance of %d\n",adj[n][i].first+1,d+adj[n][i].second);
                }
            }

            else {

                    if(!v[adj[n][i].first]){
                        if(rt == 0){
                            pq.push( make_pair( -(d+adj[n][i].second + lht[n].second), adj[n][i].first ) );
                          //  printf("Going to node %d with distance of %d\n",adj[n][i].first +1, d+adj[n][i].second + lht[n].second);
                        }
                        else{
                           // printf("Hello? %d\n",rt);
                            pq.push( make_pair( -(d+adj[n][i].second + (lht[n].second%rt)), adj[n][i].first ) );
                           // printf("Going to node %d with distance of %d\n",adj[n][i].first +1, d+adj[n][i].second + (lht[n].second%rt));
                        }
                    }
            }
        }

    }

    return 0;
}
int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d",&N,&K);
    for(int i = 0; i < N; i++){
        scanf("%d%d%d",&a,&b,&c);
        adj[a-1].push_back(make_pair(b-1,c));
        adj[b-1].push_back(make_pair(a-1,c));
    }
    for(int i = 0; i < K; i++){
        scanf("%d%d",&a,&b);
        lht.push_back( make_pair(a,b));
    }

    printf("%d\n",dijkstra());


   // fclose(stdin);
    return 0;
}
