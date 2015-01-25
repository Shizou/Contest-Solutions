#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};
int K,cnt,br = 0,bc = 0,mr = 4,mc = 4;
const int R = 5,C = 5;
bool v[R][C];


void print_grid(){
    for(int r = 0; r < R;r++){
        for(int c = 0; c < C;c++){
            cout << v[r][c];
        }
        cout << endl;
    }cout << endl;
}
bool valid(){
    for(int r = 0; r < R;r++)
        for(int c = 0; c < C;c++)
            if(!v[r][c])return false;
    return true;
}
void rec(){
    if(br == mr && bc == mc){
        if(valid())cnt++;
        return;
    }
    for(int d1 = 0; d1 < 4;d1++){
        for(int d2 = 0; d2 < 4;d2++){
            int tbr = br+dr[d1],tbc = bc+dc[d1];
            int tmr = mr+dr[d2],tmc = mc+dc[d2];
            if(tbr >= 0 && tbc >= 0 && tbr < R && tbc < C && !v[tbr][tbc]){
                if(tmr >= 0 && tmc >= 0 && tmr < R && tmc < C && !v[tmr][tmc]){
                    v[br][bc] = v[mr][mc] = true;
                    br = tbr, bc = tbc;
                    mr = tmr, mc = tmc;
                    v[br][bc] = v[mr][mc] = true;
                    rec();
                    v[br][bc] = v[mr][mc] = false;
                    br-=dr[d1],bc-=dc[d1];
                    mr-=dr[d2],mc-=dc[d2];
                    v[br][bc] = v[mr][mc] = false;
                }
            }
        }
    }
}
int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&K);
    for(int i = 0,r,c; i < K;i++){
        scanf("%d%d",&r,&c);r--;c--;
        v[r][c]=true;
    }
    rec();
    printf("%d\n",cnt);
    return 0;
}
