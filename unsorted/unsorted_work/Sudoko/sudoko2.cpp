#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cctype>
#define MAXN 9
using namespace std;

int arr[MAXN][MAXN];
bool v[MAXN][MAXN];

void rec(){
    for(int r = 0; r < MAXN;r++){
        for(c = 0; c < MAXN;c++){
            if(v[r][c])continue;
            g[r][c] =
        }
    }
}
int main(){
    freopen("input.txt","r",stdin);
    for(int r = 0; r < MAXN;r++){
        for(int c = 0;c < MAXN;c++){
            char ch;
            cin >> ch;
            if(isdigit(c)){
                arr[r][c] = ch - '0';
                v[r][c] = true;
            }
            else
                arr[r][c] = 0;
        }
    }
    return 0;
}
