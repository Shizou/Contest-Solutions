#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#define Fill2D(a,b) fill(&(a)[0][0], &(a)[0][0]+sizeof(a)/sizeof((a)[0][0]), (b))

using namespace std;

struct state{
    int r,c,d;
};

int R,C,min_spot = 1<<23;
vector< pair<int,int> >pos_loc;
char g[50][50];
bool v[50][50];

void flood(int r, int c){
    if(r<0||c<0||r>R-1||c>C-1||v[r][c])return;
    v[r][c]=true;
    if(g[r][c]!='.')
        g[r][c]='S';
    else{
        pos_loc.push_back(make_pair(r,c));
        return;
    }
    flood(r+1,c);
    flood(r-1,c);
    flood(r,c+1);
    flood(r,c-1);
}
int bfs(int sr,int sc,int sd = 0){
    queue<state>q;
    q.push((state){sr,sc,sd});
    Fill2D(v,false);
    while(!q.empty()){
        int r = q.front().r;
        int c = q.front().c;
        int d = q.front().d;
        q.pop();
        if(r<0||c<0||r>R-1||c>C-1||v[r][c])continue;
        v[r][c]=true;
        if(d>min_spot)continue;
        if(g[r][c]=='X')return d;
        q.push((state){r+1,c,d+1});
        q.push((state){r-1,c,d+1});
        q.push((state){r,c+1,d+1});
        q.push((state){r,c-1,d+1});
    }
    return 1<<23;
}
int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d",&R,&C);
    for(int r = 0; r < R;r++)
        for(int c = 0; c < C;c++)
            scanf(" %c",&g[r][c]);

    for(int r = 0; r < R;r++){
        for(int c = 0; c < C;c++){
            if(g[r][c] == 'X'){
                flood(r,c);
                goto end;
            }
        }
    }
    end:;
    for(int i = 0; i < pos_loc.size();i++)
        min_spot = min(min_spot,bfs(pos_loc[i].first,pos_loc[i].second));
    printf("%d\n",min_spot);
    return 0;
}
