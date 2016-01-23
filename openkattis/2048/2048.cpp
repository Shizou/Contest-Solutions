#include<bits/stdc++.h>
#define DB 0
#define endl '\n'
#define pb push_back
#define mp make_pair
#define LL long long
#define MAXN (int)1e5
#define inf 0x3f3f3f3f
using namespace std;

enum directions{LT,UP,RT,DN};
const int N = 4;
int D;
int a[N][N];

void _translate(int r,int c,int dir){
     if(dir == UP)
     while(r-1 >= 0 && r < N && c >= 0 && c < N){
           if(a[r-1][c] == 0 && a[r][c] != 0)
              swap(a[r-1][c],a[r][c]);
           else
              break;
           r--;
     }
     if(dir == DN)
     while(r >= 0 && r+1 < N && c >= 0 && c < N){
           if(a[r+1][c] == 0 && a[r][c] != 0)
              swap(a[r+1][c],a[r][c]);
           else
              break;
           r++;
     }
     if(dir == LT)
     while(r >= 0 && r < N && c-1 >= 0 && c < N){
           if(a[r][c-1] == 0 && a[r][c] != 0)
              swap(a[r][c-1],a[r][c]);
           else
              break;
           c--;
     }
     if(dir == RT)
     while(r >= 0 && r < N && c >= 0 && c+1 < N){
           if(a[r][c+1] == 0 && a[r][c] != 0)
              swap(a[r][c+1],a[r][c]);
           else
              break;
          c++;
     }
}
void translate(int dir){
    if(dir == UP)
    for(int r = 1;r < N;r++)
        for(int c = 0;c < N;c++)
             _translate(r,c,dir);
    if(dir == DN)
    for(int r = N-2;r >= 0;r--)
        for(int c = 0;c < N;c++)
             _translate(r,c,dir);
    if(dir == RT)
    for(int c = N-2;c >= 0;c--)
        for(int r = 0;r < N;r++)
            _translate(r,c,dir);
    if(dir == LT)
    for(int c = 1;c < N;c++)
        for(int r = 0;r < N;r++)
            _translate(r,c,dir);

}
void go(int dir){
    if(dir == UP){
       translate(UP);
       for(int r = 1;r < N;r++){
           for(int c = 0;c < N;c++){
               if(a[r-1][c] == a[r][c]){
                  a[r-1][c] *= 2;
                  a[r][c] = 0;
               }
           }
       }
       translate(UP);
    }
    if(dir == DN){
       translate(DN);
       for(int r = N-2;r >= 0;r--){
           for(int c = 0;c < N;c++){
               if(a[r+1][c] == a[r][c]){
                  a[r+1][c] *= 2;
                  a[r][c] = 0;
               }
           }
       }
       translate(DN);
    }
    if(dir == RT){
       translate(RT);
       for(int c = N-2;c >= 0;c--){
           for(int r = 0;r < N;r++){
               if(a[r][c+1] == a[r][c]){
                  a[r][c+1] *= 2;
                  a[r][c] = 0;
               }
           }
       }
       translate(RT);
    }
    if(dir == LT){
       translate(LT);
       for(int c = 1;c < N;c++){
           for(int r = 0;r < N;r++){
               if(a[r][c-1] == a[r][c]){
                  a[r][c-1] *= 2;
                  a[r][c] = 0;
               }
           }
       }
       translate(LT);
    }
}

int main(){
    #ifdef DBa
    freopen("input.txt","r",stdin);
    #endif
    for(int r = 0;r < N;r++){
        for(int c = 0;c < N;c++){
            cin >> a[r][c];
            if(DB)cout << a[r][c] << " ";
        }cout << endl;
    }
    cin >> D;
    go(D);
    if(DB) cout << D << endl << endl;
    for(int r = 0;r < N;r++){
        for(int c = 0;c < N;c++){
            cout << a[r][c] << " ";
        }cout << endl;
    }
    return 0;
}