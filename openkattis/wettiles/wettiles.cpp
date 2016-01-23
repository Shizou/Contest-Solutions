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
#define MAXN (int)2000
#define inf 0x3f3f3f3f
using namespace std;

int X,Y,T,L,W;
char g[MAXN][MAXN];
int dist[MAXN][MAXN];
int dr[] = {-1,0,1,0};
int dc[] = { 0,1,0,-1};
vector< pair<int,int> >leak;

void print_grid(){
  for(int r = 1;r <= X;r++){
      for(int c = 1;c <= Y;c++){
          cout << g[r][c];
      }cout << endl;
  }
}
void bfs(int sr,int sc){
   queue< pair< int, pair<int,int> > >q;
   q.push( mp(1,mp(sr,sc)) );
   dist[sr][sc] = 1;
   while(!q.empty()){
       pair<int,pair<int,int> > p = q.front();
       int d = p.xx, r = p.yy.xx, c = p.yy.yy;
       q.pop();
       for(int i = 0;i < 4;i++){
           int r2 = r+dr[i],c2 = c+dc[i];
           if(r2 >= 1 && r2 <= X && c2 >= 1 && c2 <= Y && dist[r2][c2] > d+1 && g[r2][c2] != '*' && d+1 <= T){
              dist[r2][c2] = d+1;
              q.push(mp(d+1,mp(r2,c2)));
           }
       }
   }
}

int main(){
    #ifdef DBa
    freopen("input.txt","r",stdin);
    #endif
    needforspeed;
    while(cin >> X && X != -1){
          cin >> Y >> T >> L >> W;
          if(DB)cout << X << " " << Y << " " << T << " " << L << " " << W << endl;
          ms(g,'.');
          ms(dist,inf);
          leak.clear();
          for(int i = 0,x,y;i < L;i++){
              cin >> x >> y;
              if(DB)cout << x << " " << y << endl;
              leak.pb(mp(x,y));
              g[x][y] = 'L';
          }
          if(W > 0){
             for(int i = 0,x1,y1,x2,y2;i < W;i++){
                 cin >> x1 >> y1 >> x2 >> y2;
                 if(DB)cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
                 // horizontal or vertical tiles
                 if(x1 == x2 && y1 == y2)// one til
                    g[x1][y1] = '*';
                 else if(x1 == x2){// horizontal tile
                    if(y1 < y2){
                       while(y1 != y2){
                            g[x1][y1] = '*';
                            y1++;
                       }
                       g[x1][y1] = '*';
                    }
                    else if(y1 > y2){
                         while(y1 != y2){
                            g[x1][y1] = '*';
                            y1--;
                         }
                         g[x1][y1] = '*';
                    }
                 }
                 else if(y1 == y2){// vertical tile
                     if(x1 < x2){
                       while(x1 != x2){
                            g[x1][y1] = '*';
                            x1++;
                       }
                       g[x1][y1] = '*';
                     }
                     else if(x1 > x2){
                       while(x1 != x2){
                            g[x1][y1] = '*';
                            x1--;
                       }
                       g[x1][y1] = '*';
                     }
                 }
                 // diagnol lines
                 else if(x1 < x2 && y1 < y2){
                    while(x1 != x2 && y1 != y2){
                         g[x1][y1] = '*';
                         x1++,y1++;
                    }
                    g[x1][y1] = '*';
                 }
                 else if(x1 < x2 && y1 > y2){
                    while(x1 != x2 && y1 != y2){
                         g[x1][y1] = '*';
                         x1++,y1--;
                    }
                    g[x1][y1] = '*';
                 }
                 else if(x1 > x2 && y1 < y2){
                    while(x1 != x2 && y1 != y2){
                         g[x1][y1] = '*';
                         x1--,y1++;
                    }
                    g[x1][y1] = '*';
                 }
                 else if(x1 > x2 && y1 > y2){
                    while(x1 != x2 && y1 != y2){
                         g[x1][y1] = '*';
                         x1--,y1--;
                    }
                    g[x1][y1] = '*';
                 }

              //   if(DB)print_grid();
             }
          }
          // execute simulation
          for(int i = 0;i < len(leak);i++){
              bfs(leak[i].xx,leak[i].yy);
          }
          // check for broken tiles
          int ans = 0;
          for(int r = 1;r <= X;r++){
              for(int c = 1;c <= Y;c++){
                  if(dist[r][c] <= T)
                     ans++;
              }
          }
          if(DB)
          for(int r = 1;r <= X;r++){
              for(int c = 1;c <= Y;c++){
                  if(dist[r][c] <= T && dist[r][c] != 1 && g[r][c] != '*')cout << dist[r][c];
                  else               cout << g[r][c];
              }cout << endl;
          }
          cout << ans << endl;
          //if(DB)print_grid();

    }
    return 0;
}