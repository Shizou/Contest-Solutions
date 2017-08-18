#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cctype>
#define MAXN 9
using namespace std;

int arr[MAXN][MAXN], d1;
bool v[MAXN][MAXN];

bool possible(int r,int c){
    bool v2[10] = {0}, v3[10]{0};
    for(int i = 0; i < MAXN;i++){
        if(v2[arr[r][i]] && arr[r][i] != 0)return false;
        v2[arr[r][i]] = true;
    }
    for(int i = 0; i < MAXN;i++){
        if(v3[arr[i][c]] && arr[i][c] != 0)return false;
        v3[arr[r][i]] = true;
    }
    return true;
}

void rec(int d){
    if(d == 81){
        for(int r = 0; r < MAXN;r++){
            for(int c = 0; c < MAXN;c++){
                cout << arr[r][c];
            }
            cout << endl;
        }
        exit(0);
    }
    for(int r = 0; r < MAXN;r++){
            for(int c = 0; c < MAXN;c++){
                cout << arr[r][c];
            }
            cout << endl;
        }
    cout << endl;
    for(int r = 0; r < MAXN;r++){
        for(int c = 0; c < MAXN;c++){
            if(v[r][c])continue;
            for(int i = 1; i <= MAXN;i++){
                arr[r][c] = i;
                if(possible(r,c)){
                    v[r][c] = true;
                    rec(d+1);
                    v[r][c] = false;
                }
                arr[r][c] = 0;
            }
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
                d1++;
            }
            else
                arr[r][c] = 0;
        }
    }
    rec(d1);
    return 0;
}
