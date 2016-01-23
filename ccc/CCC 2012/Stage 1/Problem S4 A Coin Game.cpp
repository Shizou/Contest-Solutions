#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <sstream>
#include <set>
#include <algorithm>
#define MAXN 8
#define reset_game(G,M) for(int i = 0; i < N;i++)G[i].clear();
#define to_s(N) static_cast<ostringstream*>( &(ostringstream() << N) )->str()
using namespace std;

struct state{
    vector<int>g[MAXN];
    int d;
    string id;
};

int N,ai;
vector<int>game[MAXN];
set< string >past_game;

string to_id(vector<int>g[MAXN]){
    string id;
    for(int i = 0; i < MAXN;i++){
        string t;
        for(int j = 0; j < g[i].size();j++){
            t+= to_s(g[i][j]);
        }
        t+="-";
        id+=t;
    }
    return id;
}
bool game_done(vector<int>g[MAXN]){
    for(int i = 0; i < N;i++)
        if(g[i].empty())return false;
    for(int i = 0; i < N;i++)
        if(g[i].size()!= 1 || g[i][0] != i+1)return false;
    return true;
}
void print_game(vector<int>g[MAXN],int d,string id){
    printf("D:%d ;",d);cout << id << endl;
    for(int i = 0; i < MAXN;i++){
        printf("%d:",i+1);
        for(int j = 0; j < g[i].size();j++)printf("%d",g[i][j]);
        printf("\n");
    }
    printf("\n");
}
int bfs(){
    queue<state> q;
    q.push( (state){game[0],game[1],game[2],game[3],game[4],game[5],game[6],game[7],0,to_id(game)});
    while(!q.empty()){
        vector<int>g[MAXN] = q.front().g;
        int d = q.front().d;
        string id = q.front().id;
        q.pop();
        if(past_game.find(id) != past_game.end())
            continue;
        else
            past_game.insert(id);
        //print_game(g,d,id);
        if(game_done(g)){
            return d;
        }
        for(int i = 0; i < N;i++){
            if(g[i].empty())continue;
            if(i-1>=0){
                int left_end = g[i-1].size()-1;
                int curr_end = g[i].size()-1;
                if(g[i-1].empty()){
                    g[i-1].push_back(g[i][curr_end]);
                    g[i].erase(g[i].begin() + curr_end);
                    q.push( (state){g[0],g[1],g[2],g[3],g[4],g[5],g[6],g[7],d+1,to_id(g)});
                    left_end++;curr_end--;
                    g[i].push_back(g[i-1][left_end]);
                    g[i-1].erase(g[i-1].begin()+left_end);
                }
                else if(g[i-1][left_end] > g[i][curr_end]){
                    g[i-1].push_back(g[i][curr_end]);
                    g[i].erase(g[i].begin() + curr_end);
                    q.push( (state){g[0],g[1],g[2],g[3],g[4],g[5],g[6],g[7],d+1,to_id(g)});
                    left_end++;curr_end--;
                    g[i].push_back(g[i-1][left_end]);
                    g[i-1].erase(g[i-1].begin()+left_end);
                }
            }
            if(i+1<N){
                int rght_end = g[i+1].size()-1;
                int curr_end = g[i].size()-1;
                if(g[i+1].empty()){
                    g[i+1].push_back(g[i][curr_end]);
                    g[i].erase(g[i].begin() + curr_end);
                    q.push( (state){g[0],g[1],g[2],g[3],g[4],g[5],g[6],g[7],d+1,to_id(g)});
                    rght_end++;curr_end--;
                    g[i].push_back(g[i+1][rght_end]);
                    g[i+1].erase(g[i+1].begin()+rght_end);
                }
                else if(g[i+1][rght_end] > g[i][curr_end]){
                    g[i+1].push_back(g[i][curr_end]);
                    g[i].erase(g[i].begin() + curr_end);
                    q.push( (state){g[0],g[1],g[2],g[3],g[4],g[5],g[6],g[7],d+1,to_id(g)});
                    rght_end++;curr_end--;
                    g[i].push_back(g[i+1][rght_end]);
                    g[i+1].erase(g[i+1].begin()+rght_end);
                }
            }
        }
    }
    return -1;
}
int main(){
    //freopen("input.txt","r",stdin);
    while(scanf("%d",&N)&& N!= 0){
        for(int i = 0; i < N;i++){
            scanf("%d",&ai);
            game[i].push_back(ai);
        }
        //print_game(game,0,to_id(game));
        int ans = bfs();
        if(ans == -1)printf("IMPOSSIBLE\n");
        else         printf("%d\n",ans);
        past_game.clear();
        reset_game(game,MAXN);
    }
    return 0;
}
