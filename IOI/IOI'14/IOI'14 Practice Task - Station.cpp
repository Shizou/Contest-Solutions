#include<iostream>
#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;

int N,K;
set<int>stn;

int main(){
    scanf("%d%d",&N,&K);
    for(int i = 1,j = 0;i <= N;++i){
        scanf("%d",&j);
        if(j == 1)stn.insert(i);
    }
    int pos = 1,cnt = 0;
    while(pos != N){
        int next = *stn.upper_bound(pos);
        while(abs(pos-*stn.upper_bound(next)) <= K){
            next = *stn.upper_bound(next);
            if(next == N)break;
        }
        if(abs(pos-next) <= K){
          pos = next;
          cnt++;
        }
        else{
          cnt = -1;
          break;
        }
    }
    printf("%d\n",cnt);
    return 0;
}