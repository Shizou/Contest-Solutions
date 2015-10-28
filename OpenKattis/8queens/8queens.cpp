#include<bits/stdc++.h>
#define DB
using namespace std;

const int R = 8,C = 8;
int dr[] = {-1,-1,0,1,1, 1, 0,-1};
int dc[] = { 0, 1,1,1,0,-1,-1,-1};
char g[8][8];
bool v[8][8];


void update(int r,int c,int dir){
  r += dr[dir], c += dc[dir];
  while(r < R && r >= 0 && c < C && c >= 0){
       v[r][c] = true;
       r +=dr[dir], c += dc[dir];
  }
}

int main(){
    #ifdef DBa
    freopen("input.txt","r",stdin);
    #endif
    for(int r = 0;r < R;r++){
        for(int c = 0;c < C;c++){
            cin >> g[r][c];
        }
    }
    for(int r = 0;r < R;r++){
        for(int c = 0;c < C;c++){
            if(g[r][c] == '*'){
               for(int k = 0;k < 8;k++)
                   update(r,c,k);
            }
        }
    }
    bool valid = true;
    for(int r = 0,cnt = 0;r < R;r++){
        for(int c = 0;c < C;c++){
            if(g[r][c] == '*' && v[r][c])
                valid = false;
            if(g[r][c] == '*')
               cnt++;
        }
        if(r == R-1 && cnt != 8)
           valid = false;
    }
    if(valid)
       cout << "valid" << endl;
    else
       cout << "invalid" << endl;
    return 0;
}