// http://wcipeg.com/problems/desc/2048
#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>
using namespace std;

const int MAXN = 4;
enum DIRECTIONS{UP,RT,DN,LT};
int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};

struct grid{
  int G[MAXN][MAXN];
  grid(int (&_G)[MAXN][MAXN]){
    for(int r = 0;r < MAXN;r++)
        for(int c = 0;c < MAXN;c++)
            G[r][c] = _G[r][c];
  }
  // modifiers
  void translate_col(int d,int c);
  void translate_row(int d,int r);
  void translate(int d);
  void shift(int d);
  // queries
  int get_max();
  void print();
  // operators
  bool operator <  (const grid &grid2)const;
  bool operator == (const grid &grid2)const;
  void operator =  (grid &grid2);
};

// modifiers
void grid::translate_col(int d,int c){
    bool change = true;
    if(d == UP){
      while(change){
        change = false;
        for(int r = 0;r < MAXN-1;r++)
          if(G[r][c] == 0 && G[r+1][c] != 0)
            G[r][c] = G[r+1][c],G[r+1][c] = 0,change = true;
      }
    }else if(d == DN){
      while(change){
        change = false;
        for(int r = MAXN-1;r >= 1;r--)
          if(G[r][c] == 0 && G[r-1][c] != 0)
            G[r][c] = G[r-1][c],G[r-1][c] = 0,change = true;
      }
    }
}
void grid::translate_row(int d,int r){
    bool change = true;
    if(d == RT){
      while(change){
        change = false;
        for(int c = MAXN-1;c >= 1;c--)
          if(G[r][c] == 0 && G[r][c-1] != 0)
            G[r][c] = G[r][c-1],G[r][c-1] = 0,change = true;
      }
    }else if(d == LT){
      while(change){
        change = false;
        for(int c = 0;c < MAXN-1;c++)
          if(G[r][c] == 0 && G[r][c+1] != 0)
            G[r][c] = G[r][c+1],G[r][c+1] = 0,change = true;
      }
    }
}
void grid::translate(int d){
      if(d == UP|| d == DN)
        for(int c = 0;c < MAXN;c++)
           translate_col(d,c);
      else
        for(int r = 0;r < MAXN;r++)
            translate_row(d,r);
}
void grid::shift(int d){
    if(d == UP){
       translate(UP);
       for(int r = 1;r < MAXN;r++)// addition
          for(int c = 0;c < MAXN;c++)
            if(G[r-1][c] == G[r][c])
              G[r-1][c]+=G[r][c], G[r][c]=0;
       translate(UP);
    }
    else if(d == DN){
      translate(DN);
      for(int r = MAXN-1;r >= 1;r--)// addition
          for(int c = 0;c < MAXN;c++)
            if(G[r][c] == G[r-1][c])
              G[r][c]+=G[r-1][c], G[r-1][c]=0;
      translate(DN);
    }
    else if(d == RT){
      translate(RT);
      for(int c = 0;c < MAXN-1;c++)// addition
          for(int r = 0;r < MAXN;r++)
            if(G[r][c+1] == G[r][c])
              G[r][c+1]+=G[r][c], G[r][c]=0;
      translate(RT);
    }
    else if(d == LT){
      translate(LT);
      for(int c = MAXN-1;c >= 1;c--)// addition
          for(int r = 0;r < MAXN;r++)
            if(G[r][c-1] == G[r][c])
              G[r][c-1]+=G[r][c], G[r][c]=0;
      translate(LT);
    }
}
// queries
int grid::get_max(){
    int m = 0;
    for(int r = 0;r < MAXN;r++)
        for(int c = 0;c < MAXN;c++)
          m = max(m,G[r][c]);
    return m;
}
void grid::print(){
    for(int r = 0;r < MAXN;r++){
      for(int c = 0;c < MAXN;c++){
        printf("%d ",G[r][c]);
      }printf("\n");
    }printf("\n");
}
// comparison operators
bool grid::operator < (const grid &grid2)const{
      for(int r = 0;r < MAXN;r++)
        for(int c = 0;c < MAXN;c++)
          if(G[r][c] < grid2.G[r][c])return true;
        return false;
}
bool grid::operator == (const grid &grid2)const{
    for(int r = 0;r < MAXN;r++)
      for(int c = 0;c < MAXN;c++)
        if(G[r][c] != grid2.G[r][c])
            return false;
    return true;
}
void grid::operator = (grid &grid2){
  for(int r = 0;r < MAXN;r++)
      for(int c = 0;c < MAXN;c++)
          G[r][c] = grid2.G[r][c];
}
/*-------------------------------------------------------------------------------------------------------------------------------------------------------*/
int G[MAXN][MAXN];
int best = 0;
queue<grid>q;
set<grid>used;

int main(){
    freopen("input.txt","r",stdin);
    for(int r = 0;r < MAXN;r++)
        for(int c = 0;c < MAXN;c++)
            scanf("%d",&G[r][c]);
    grid init = (grid){G};
    best = max(best,init.get_max());
    q.push(init);
    while(!q.empty()){
        grid current = q.front();
        current.print();
        q.pop();
        if(used.find(current) != used.end())
          continue;
        else{
          used.insert(current);
          for(int d = 0;d < 4;d++){
            grid temp = current;
            temp.shift(d);
            if(used.find(temp) == used.end()){
              q.push(temp);
              used.insert(temp);
              best = max(best,temp.get_max());
            }else{
              printf("already in\n");
            }
          }
      }
    }
    printf("%d\n",best);
    return 0;
}
