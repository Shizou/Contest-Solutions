#include<bit/stdc++.h>
using namespace std;

int R = 7, C = 7,cnt;
string g[7];

int main() {
    //freopen("input.txt"."r",stdin);
    for(int r = 0; r < 7 && getline(cin,g[r]);r++){
        if(r == 0||r==1||r==5||r==6)g[r]+="  ";
    }
    for(int r = 0; r < 7;r++){
        for(int c = 0; c < C;c++){
            if(g[r][c] == 'o'){
                if(r-2>=0 && g[r-1][c]=='o'&& g[r-2][c]=='.')cnt++;
                if(c-2>=0 && g[r][c-1]=='o'&& g[r][c-2]=='.')cnt++;
                if(r+2< R && g[r+1][c]=='o'&& g[r+2][c]=='.')cnt++;
                if(c+2< C && g[r][c+1]=='o'&& g[r][c+2]=='.')cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}