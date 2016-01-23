#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
int row,col,n;
string s;
char g[20][20];
bool v[20][20];
bool p;
struct path{
    int r,c,d;
};
int main(){
    //freopen("input.txt","r",stdin);
    cin >> n;
    queue< path > q;
    for(int o = 0;o < n;o++){
            cin >> row >> col;
            for(int i = 0;i < row;i++){
                for(int j = 0;j < col;j++){
                    cin >> g[i][j];
                }
            }
            q.push( (path){0,0,1});
            p = 0;
            while(!q.empty()){
                int r = q.front().r;
                int c = q.front().c;
                int d = q.front().d;
                q.pop();
                if(r < 0 || c < 0 || r > row-1 || c > col-1) continue;
                if(v[r][c]) continue;
                if(r == row-1 && c == col-1 && g[r][c] != '*'){
                    cout << d << endl;
                    p = 1;
                    break;
                }
                v[r][c] = 1;
                if(g[r][c] == '+'){
                    q.push( (path){r+1,c,d+1});
                    q.push( (path){r-1,c,d+1});
                    q.push( (path){r,c+1,d+1});
                    q.push( (path){r,c-1,d+1});
                }
                else if(g[r][c] == '-'){
                     q.push( (path){r,c+1,d+1});
                     q.push( (path){r,c-1,d+1});
                }
                else if(g[r][c] == '|'){
                     q.push( (path){r+1,c,d+1});
                     q.push( (path){r-1,c,d+1});
                }
                else if(g[r][c] == '*'){
                     continue;
                }

            }
            if(!p){
                cout << -1 << endl;
            }
            q = queue< path >();
            memset(v,0,sizeof v);
        getline(cin,s);
    }
    //fclose(stdin);
    return 0;
}
