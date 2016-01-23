#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int N,K,x,y,cnt;
int rlt[15][15];
int same[15];
vector<int>group[3];
char d;

bool check(vector<int>&arr,int &n){
    int rlt_cnt = same[n], cnt2 = 0;
    for(int i = 0; i < arr.size();i++){
        if(rlt[n][arr[i]] == 1)cnt2++;
    }
    return rlt_cnt == cnt2;
}
void recurse(int n){
    if(n == N){
        for(int i = 0; i < 3;i++){
            if(group[i].size() == 1 && same[group[i][0]])
                return;
            for(int j = 0; j < group[i].size();j++)
                if(same[group[i][j]] && !check(group[i],group[i][j]))
                    return;
        }
        cnt++;
        return;
    }
    for(int i = 0; i < 3;i++){
        bool pos = true;
        for(int j = 0; j < group[i].size();j++){
            if(rlt[n][group[i][j]] == -1){
                pos = false;
                break;
            }
        }
        if(pos){
            group[i].push_back(n);
            recurse(n+1);
            group[i].pop_back();
        }
    }
}
int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d",&N,&K);
    for(int i = 0; i < K;i++){
        scanf(" %c%d%d",&d,&x,&y);x--;y--;
        if(d == 'S'){
            rlt[x][y] = rlt[y][x] = 1;
            same[x]++;
            same[y]++;
        }
        else
            rlt[x][y] = rlt[y][x] = -1;
    }
    recurse(0);
    printf("%d\n",cnt);
    return 0;
}

