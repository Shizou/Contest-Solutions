#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

struct state{
	int r,c,d;
};

int M,R,C,sr,sc,cnt;
int dist[100][100];
char g[100][100];
vector<int>path;

void bfs(){
    queue< state >q;
	q.push((state){sr,sc,0});
	while(!q.empty()){
		int r = q.front().r;
		int c = q.front().c;
		int d = q.front().d;
		q.pop();
		if(r < 0 || c < 0 || r > R-1 || c > C-1 ||d >= dist[r][c])continue;
		dist[r][c]=d;
		if(g[r][c] == '#')continue;
		if(g[r][c] == 'S')
			path.push_back(d);
		q.push((state){r+1,c,d+1});
		q.push((state){r-1,c,d+1});
		q.push((state){r,c+1,d+1});
		q.push((state){r,c-1,d+1});
	}
}
int main() {
    //freopen("input.txt","r",stdin);
	scanf("%d",&M);
	while(M--){
        scanf("%d%d",&R,&C);
        fill(&dist[0][0], &dist[0][0]+100*100,1<<23);
        cnt = 0;
        path.clear();
        for(int r = 0; r < R;++r){
            for(int c = 0;c < C;++c){
                scanf(" %c",&g[r][c]);
                if(g[r][c] == 'C'){
                    sr = r;
                    sc = c;
                }
            }
        }
        bfs();
        sort(path.begin(),path.end(),greater<int>());
        cnt+=path[0]+60;
        for(int i = 1; i < path.size();i++){
            cnt+=2*path[i]+60;
        }
        printf("%d\n",cnt);
	}
	return 0;
}


