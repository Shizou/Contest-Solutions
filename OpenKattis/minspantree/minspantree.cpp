#include<bits/stdc++.h>
#define endl '\n'
#define needforspeed ios_base::sync_with_stdio (false);
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define len(x) (int)(x).size()
#define ms(a,b) memset( (a), (b), sizeof( (a) ) )
#define xx first
#define yy second
#define LL long long
#define DB 0
#define MAXN (int)20005
#define inf 0x3f3f3f3f
using namespace std;

int N,M;
int parent[MAXN];
vector< pair<int,pair<int,int> > >E;

int find(int x){
    if(parent[x]!=x)parent[x] = find(parent[x]);
    return parent[x];
}
void merge(int x,int y){
    x = find(x);
    y = find(y);
    if(x < y)
       parent[y] = parent[x];
    else
       parent[x] = parent[y];
}


int main(){
    #ifdef DBa
    freopen("input.txt","r",stdin);
    #endif
    needforspeed;
    while(cin >> N >> M && !(N == 0 && M == 0)){
        E.clear();
        for(int i = 0,u,v,w;i < M;i++){
                cin >> u >> v >> w;
                if(u > v)swap(u,v);
                E.pb(mp(w,mp(u,v)));
         }
         int cost = 0,forest = 0;
         vector< pair<int,int> >out;
         sort(all(E));
         for(int i = 0;i < N;i++)
             parent[i] = i;
        for(int i = 0;i < len(E);i++){
            int x = find(E[i].yy.xx);
            int y = find(E[i].yy.yy);
            if(x!=y){
               merge(x,y);
               cost += E[i].xx;
               out.pb( mp(E[i].yy.xx,E[i].yy.yy) );
            }
        }
        for(int i = 0;i < N;i++){
            if(parent[i] == i){
                forest++;
            }
        }
        if(forest == 1){
           cout << cost << endl;
           sort(all(out));
           for(int i = 0;i < len(out);i++){
           cout << out[i].xx << " " << out[i].yy << endl;
           }
        }
        else
        cout << "Impossible" << endl;
   }
    return 0;
}