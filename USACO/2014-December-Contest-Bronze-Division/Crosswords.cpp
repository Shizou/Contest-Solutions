#include<iostream>
#include<cstdio>
#include<vector>
#include<cctype>
#include<queue>
#include<cmath>
#include<algorithm>
#define mp make_pair
#define pb push_back
using namespace std;

int R,C,cnt;
const int UP = 0, RT = 1, DN = 2, LT = 3;
int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};
char g[50][50];
bool h[50][50],v[50][50];
vector< pair<int,int> > clues;

bool clue(int r, int c,int dir){
    int d = 0;
    r+=dr[dir],c+=dc[dir];
    while(r >= 0 && c >= 0 && r < R && c < C && g[r][c] != '#'){
        //printf("%d %d\n",r,c);
        if(dir == DN && v[r][c])return false;
        if(dir == RT && h[r][c])return false;
        r+=dr[dir];
        c+=dc[dir];
        d++;
    }
    return d >= 2;
}
void assign(int r,int c, int dir){
    while(r >= 0 && c >= 0 && r < R && c < C && g[r][c] != '#'){
        if(dir == DN)v[r][c]=true;
        if(dir == RT)h[r][c]=true;
        r+=dr[dir];
        c+=dc[dir];
    }
}
int main(){
    scanf("%d%d",&R,&C);
    for(int r = 0; r < R;r++)
        for(int c = 0; c < C;c++)
            scanf(" %c",&g[r][c]);

    for(int r = 0; r < R;r++){
        for(int c = 0; c < C;c++){
            if(g[r][c] != '#' && ((c-1 >= 0 && g[r][c-1] == '#') || (c-1 < 0))&& clue(r,c,RT)){
                clues.pb(mp(r+1,c+1));
                assign(r,c,RT);
            }
            else if(g[r][c] != '#' && ((r-1 >= 0 && g[r-1][c] == '#') || (r-1 < 0))&& clue(r,c,DN)){
                clues.pb(mp(r+1,c+1));
                assign(r,c,DN);
            }
        }
    }
    printf("%d\n",clues.size());
    for(int i = 0; i < clues.size();i++)
        printf("%d %d\n",clues[i].first, clues[i].second);

    return 0;
}

