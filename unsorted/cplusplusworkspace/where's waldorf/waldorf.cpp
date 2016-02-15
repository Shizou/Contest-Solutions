#include<iostream>
#include<cstdio>
#include<cctype>
using namespace std;

int T,M,N,K;
int dr[] = {-1, -1, 0, 1, 1,  1,  0, -1};
int dc[] = { 0,  1, 1, 1, 0, -1, -1, -1};
string g[50];
string w[50];

bool v(int i, int j, int d, string q){
    string str;
    while(i > -1 && i < M && j > -1 && j < N){
        str+= g[i][j];
        if(str == q)return true;
        i+=dr[d];
        j+=dc[d];
    }
    return false;
}
int main(){
    freopen("input.txt","r",stdin);
    cin >> T;
    while(T--){
        cin >> M >> N;
        for(int i = 0; i < M;i++){
            cin >> g[i];
            for(int j = 0; j < N;j++)
                g[i][j] = tolower(g[i][j]);
        }
        cin >> K;
        for(int i = 0; i < K;i++){
            cin >> w[i];
            for(int j = 0; j < w[i].size();j++)
                w[i][j] = tolower(w[i][j]);
        }
        for(int l = 0; l < K;l++){
        for(int i = 0; i < M;i++)
        for(int j = 0; j < N;j++)
        for(int d = 0; d < 8;d++)
            if(v(i,j,d,w[l])){
                cout  <<(i+1) << " " << (j+1) << endl;
                goto found;
            }
            found:;
        }
        cout << endl;
    }
    return 0;
}
