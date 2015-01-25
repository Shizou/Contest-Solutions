#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#define MAXN 12
using namespace std;

int arr[MAXN];
int best = 0x3F3F3F3F;
vector<int>team[4];

int sum(vector<int>&arr){int s = 0;for(int i = 0; i < 3;i++)s+=arr[i];return s;}
void rec(int n){
    if(n == MAXN){
        int t1 = sum(team[0]),t2 = sum(team[1]),t3 = sum(team[2]),t4 = sum(team[3]);
        int mn = min(t1,min(t2,min(t3,t4))), mx = max(t1,max(t2,max(t3,t4)));
        best = min(best,mx-mn);
    }
    for(int i = 0; i < 4;i++){
        if(team[i].size()<3){
            team[i].push_back(arr[n]);
            rec(n+1);
            team[i].pop_back();
        }
    }
}
int main(){
    //freopen("input.txt","r",stdin);
    for(int i = 0;i < MAXN;++i)
        scanf("%d",&arr[i]);
    rec(0);
    printf("%d\n",best);
    return 0;
}

