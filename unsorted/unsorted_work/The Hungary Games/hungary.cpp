#include<stdio.h>
#include<vector>
#include<queue>

using namespace std;

int N,M,s,t,l;

vector< pair<int,int> > adj[20000];
vector< pair<int,int> > dist(20000, make_pair(25000000,25000000));

int spfa(){
    queue< pair<int,int> >q;
    q.push( make_pair(0,0) );
    while(!q.empty()){
		int d = q.front().first;
		int n = q.front().second;
		q.pop();
        //printf("N:%d D:%d\n", n,d );

		for(int i = 0;i < adj[n].size();i++){
		   if(dist[adj[n][i].first].first > d + adj[n][i].second){
		        dist[adj[n][i].first].first = d + adj[n][i].second;
                q.push( make_pair( dist[adj[n][i].first].first,adj[n][i].first ));
		    }
		    else if(dist[adj[n][i].first].first == d + adj[n][i].second && adj[n][i].first != N-1){
                  dist[adj[n][i].first].second = d + adj[n][i].second;
                  q.push( make_pair( dist[adj[n][i].first].second,adj[n][i].first ));
		    }
		    else if(dist[adj[n][i].first].second > d + adj[n][i].second){
		        dist[adj[n][i].first].second = d + adj[n][i].second;
                q.push( make_pair( dist[adj[n][i].first].second,adj[n][i].first ));
		    }
		}
	}
    return 0;
}

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d",&N,&M);
    for(int i = 0; i < M;i++){
        scanf("%d%d%d",&s,&t,&l);
        adj[s-1].push_back( make_pair(t-1, l) );
    }
    spfa();
    //printf("%d\n",dist[N-1].first);
    printf("%d\n", (dist[N-1].second) == 25000000 ? -1:dist[N-1].second);

  // fclose(stdin);
}
