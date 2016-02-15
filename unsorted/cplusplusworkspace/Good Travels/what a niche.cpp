#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define db 0
using namespace std;

const int N = 2000;
int R,C;
string g[N];
bool v[N][N];

bool end(int r,int c){
    int cnt = 0;
    if(r+1 < R  && g[r+1][c] == 'X')cnt++;
    if(c+1 < C  && g[r][c+1] == 'X')cnt++;
    if(r-1 >= 0 && g[r-1][c] == 'X')cnt++;
    if(c-1 >= 0 && g[r][c-1] == 'X')cnt++;
    return cnt == 3;
}
bool
int main(){
    freopen("input.txt","r",stdin);
    cin >> R >> C;
    for(int r = 0;r < R;r++){
        cin >> g[r];
        for(int c = 0;c < C;c++)
            if(g[r][c] == 'X')v[r][c] = true;
    }
    for(int r = 0;r < R;r++){
        for(int c = 0;c < C;c++){
            if(g[r][c] == '.' && end(r,c)){
               if(check(r,c)){

               }
            }
        }
    }
    return 0;
}