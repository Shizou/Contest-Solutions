#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#define MAXN 5*(int)1e6+5
using namespace std;

int W,D,V;
vector<int>dig;
vector<int> dist(MAXN,-1);

int main(){
    scanf("%d%d",&W,&D);
    for(int i = 0, j = 0; i < D;++i){
        scanf("%d",&j);
        dig.push_back(j);
    }
    queue< pair<int,int> >q;
    for(int i = 0; i < dig.size();++i)
        q.push(make_pair(dig[i],0));
    while(!q.empty()){
        int n = q.front().first;
        int d = q.front().second;
        q.pop();
        for(int i = 0; i < dig.size();++i){
            if(n+dig[i] < MAXN && (dist[n+dig[i]] == -1 || d+1 <= dist[n+dig[i]] || d+1 == W)){
                if(dist[n+dig[i]] != W )dist[n+dig[i]] = d+1;
                if(d+1 == W)
                    dist[n+dig[i]] = W;
                else
                    q.push(make_pair(n+dig[i],d+1));
            }
            if(n*dig[i] < MAXN && (dist[n*dig[i]] == -1 ||  d+1 <= dist[n*dig[i]] || d+1 == W)){
                if(dist[n*dig[i]] != W )dist[n*dig[i]] = d+1;
                if(d+1 == W)
                    dist[n*dig[i]] = W;
                else
                    q.push(make_pair(n*dig[i],d+1));
            }
        }
    }
    scanf("%d",&V);
    for(int i = 0, j = 0; i < V;i++){
        scanf("%d",&j);
        if(dist[j] == W)
            printf("Y\n");
        else
            printf("N\n");
    }
    return 0;
}
