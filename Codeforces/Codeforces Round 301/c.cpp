#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define db 0
#define all(x) x.begin(),x.end()
#define r first
#define c second
using namespace std;

const int N = 505,inf = 0x3f3f3f3f;
int R,C;
int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};
pair<int,int>pt[2];
char g[N][N];
bool v[N][N][2];

int main(){
    //freopen("input.txt","r",stdin);
    cin >> R >> C;
    memset(v,false,sizeof(v));
    for(int r = 1;r <= R;r++){
        for(int c = 1;c <= C;c++){
            cin >> g[r][c];
            if(g[r][c] == 'X')
               v[r][c][0] = true;
      }
    }
    cin >> pt[0].r >> pt[0].c;
    cin >> pt[1].r >> pt[1].c;
    queue< pair<int,int> >q;
    q.push(pt[0]);
    while(!q.empty()){
        pair<int,int> st = q.front();
        q.pop();
        if(db)
          cout << st.r << " " << st.c << endl;
        for(int i = 0;i < 4;i++){
            st.r+=dr[i],st.c+=dc[i];
            if(st.r >= 1 && st.r <= R && st.c >= 1 && st.c <= C){
               if(!v[st.r][st.c][0]){
                  v[st.r][st.c][0] = true;
                  q.push(st);

               }
               else if(!v[st.r][st.c][1])
                  v[st.r][st.c][1] = true;
            }
            st.r-=dr[i],st.c-=dc[i];
        }
    }
    if(db){
      for(int r = 1;r <= R;r++){
        for(int c= 1;c <= C;c++){
          cout << v[r][c][0];
        }cout << endl;
      }
    }
    if(v[pt[1].r][pt[1].c][1])
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}