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
#define MAXN (int)25
#define inf 0x3f3f3f3f
using namespace std;

enum dir{UP,RT,DN,LT};
string out[] = {"UP","RT","DN","LT"};

int T,W,L;
int dr[] = {-1,0,1,0};
int dc[] = { 0,1,0,-1};
char g[MAXN][MAXN];
bool v[MAXN][MAXN];

int direction(int d,char c){
   if(c == '\\'){
      if(d == UP)
         d = LT;
      else if(d == RT)
         d = DN;
      else if(d == DN)
         d = RT;
      else if(d == LT)
         d = UP;
   }
   else if(c == '/'){
      if(d == UP)
         d = RT;
      else if(d == RT)
         d = UP;
      else if(d == DN)
         d = LT;
      else if(d == LT)
         d = DN;
   }

   return d;
}
void find(int sr,int sc,int sd){
    int r = sr,c = sc,d = sd;
    r+= dr[d],c += dc[d];
    ms(v,false);
    if(DB)cout << "START: " << r << " " << c << " " << out[sd] << endl;
    while(r >= 0 && r < L && c >= 0 && c < W && g[r][c] != 'x'){
       if(DB)cout << r << " " << c << " " << out[d] << endl;
       if(g[r][c] == '\\' || g[r][c] == '/'){
          d = direction(d,g[r][c]);
       }
       r+=dr[d];
       c+=dc[d];
    }
    g[r][c] = '&';
}
int main(){
    #ifdef DBa
    freopen("input.txt","r",stdin);
    #endif
    needforspeed;
    for(int t = 1;cin >> W >> L && !(W == 0 && L == 0);t++){
          int sr = 0,sc = 0,sd = 0;
          for(int r = 0;r < L;r++){
              for(int c = 0;c < W;c++){
                  cin >> g[r][c];
                  if(g[r][c] == '*'){
                     sr = r;
                     sc = c;
                  }
              }
          }
          // choosing direction
          if(sr-1 >= 0 && g[sr-1][sc] != 'x')
             sd = UP;
          else if(sr+1 < L && g[sr+1][sc] != 'x')
             sd = DN;
          else if(sc-1 >= 0 && g[sr][sc-1] != 'x')
             sd = LT;
          else if(sc+1 < W && g[sr][sc+1] != 'x')
             sd = RT;
          find(sr,sc,sd);
          cout << "HOUSE " << t << endl;
          for(int r = 0;r < L;r++){
              for(int c = 0;c < W;c++){
                  cout << g[r][c];
              }cout << endl;
          }
    }
    return 0;
}