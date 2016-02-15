#include<iostream>
#include<stdio.h>

using namespace std;

int T,H,W,N,treasure;
int fx,fy;
string g[105];
bool v[105][105];
string dir;

bool valid(string &dir){
    if(dir == "L" && fy-1 >= 0 && g[fx][fy-1] != 'S')
        return true;
    else if(dir == "R" && fy+1 <= W-1 && g[fx][fy+1] != 'S')
        return true;
    else if(dir == "D" && fx+1 <= H-1 && g[fx+1][fy] != 'S')
        return true;
    return false;
}
void fall(){
    while(fx+1 <= H-1 && g[fx+1][fy] == 'E'){
        fx++;
    }
}
int traverse(string &dir){
    //printf("Original(%d% , %d)\n",fx,fy);
    if(dir == "L"){
        fy--;
        if(g[fx][fy] == 'T' && !v[fx][fy]){
            v[fx][fy] = true;
            treasure++;
        }
        fall();
    }
    else if(dir == "R"){
        fy++;
        if(g[fx][fy] == 'T' && !v[fx][fy]){
            v[fx][fy] = true;
            treasure++;
        }
        fall();
    }
    else if(dir == "D"){
        fx++;
        if(g[fx][fy] == 'T' && !v[fx][fy]){
            v[fx][fy] = true;
            treasure++;
        }
        fall();
    }
   // printf("END(%d% , %d)\n",fx,fy);
}
void r(){
    /*resets visited to 0*/
    for(int i= 0;i < 105;i++)
        for(int j = 0;j < 105;j++)
            v[i][j] = false;
    /*initializes suface row*/
    g[0] = "";
    for(int i = 0;i < W;i++)g[0]+="D";
}
int main(){
    //freopen("input.txt","r",stdin);
    cin >> T;
    while(T--){
        cin >> H >> W >> N;
        H++;//increment H to account for surface row
        getline(cin,g[0]);
        fx = fy = treasure = 0;
        r();
        for(int i = 1; i < H;i++){
            getline(cin,g[i]);
        }
        for(int i = 0; i < N;i++){
            getline(cin,dir);
            if(valid(dir)){
              traverse(dir);
            }
        }
        cout << treasure << endl;
    }
}
