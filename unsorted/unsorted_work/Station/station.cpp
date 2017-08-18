#include<iostream>
#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;

int N,K;
set<int>stn;
set<int>::iterator it;

int main(){
    scanf("%d%d",&N,&K);
    for(int i = 1,j = 0;i <= N;++i){
        scanf("%d",&j);
        if(j != 0)stn.insert(i);
    }
    int pos = 1,cnt = 0;
    while(pos != N){
        it = --stn.upper_bound(pos+K);
        if(*it == pos || *it-pos > K){
            cnt = -1;
            break;
        }
        else{
          pos = *it;
          cnt++;
        }
    }
    printf("%d\n",cnt);
    return 0;
}