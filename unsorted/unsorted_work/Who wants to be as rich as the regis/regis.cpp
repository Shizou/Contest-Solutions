#include<stdio.h>
#include<string.h>
#include<iostream>

using namespace std;

char g[30][30][30];
bool v[30][30][30];
int N,C,R;
string in;

int f(int x, int y, int z){
    if(x < 0 || y < 0 || z < 0 || x > N-1 || y > N-1 || z > N-1)
        return 0;
    if(v[x][y][z])
        return 0;
    v[x][y][z] = true;
    if(g[x][y][z] == '1') return 0;
    return f(x+1,y,z) + f(x-1,y,z) + f(x,y+1,z) + f(x,y-1,z) + f(x,y,z+1) + f(x,y,z-1) + 1;
}
void r(){
    for(int i = 0;i < 30;i++){
        for(int j = 0; j < 30;j++){
            for(int k = 0;k < 30;k++){
                g[i][j][k] = '0';
            }
        }
    }
    for(int i = 0;i < 30;i++){
        for(int j = 0; j < 30;j++){
            for(int k = 0;k < 30;k++){
                v[i][j][k] = 0;
            }
        }
    }

}
int main(){
   // freopen("input.txt","r",stdin);
    while(true){
        cin >> N;
        if(N == -1)break;
        getline(cin,in);
        for(int i = 0;i < N;i++){
            for(int j = 0;j < N;j++){
                getline(cin,in);
                for(int k = 0;k < N;k++){
                     g[i][j][k] = in[k];
                }
            }
            if(i != N-1)getline(cin,in);
        }
        cin >> C >> R;
        cout << f(0,C-1,R-1) << endl;
        r();
    }
   // fclose(stdin);
}
