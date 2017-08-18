#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

const int MAXK = 1300000, MAXS = 100000;
long long N,K;
vector<int>lft,rht;// left prime, right composite

void sieve(){
    vector<bool>v(MAXK,true);
    v[0]=v[1]=false;
    for(int i = 2; i <= sqrt(MAXK);i++){
        if(v[i]){
            for(int j = i*i; j < MAXK;j+=i)v[j]=false;
            lft.push_back(i);
        }
        else
            rht.push_back(i);
    }
    for(int i = sqrt(MAXK)+1; i < MAXK && lft.size() < MAXS;i++){
        if(v[i])
            lft.push_back(i);
        else if(rht.size() < MAXS)
            rht.push_back(i);
    }
}
int main(){
    //freopen("input.txt","r",stdin);
    scanf("%lld%lld",&N,&K);
    sieve();
    long long alex = 0, benz = N;
    long long it = 0, diff = 1 << 23;
    int t_it = -K+2;
    for(int i = 0; i < MAXS;++i,t_it++){
        alex+=lft[i];
        benz+=rht[i];
        if(i == K-1){
            it = t_it;
            diff = abs(benz-alex);
        }
        else if(i >= K){
            alex-=lft[i-K];
            benz-=rht[i-K];
            if(abs(benz-alex) < diff){
              it = t_it;
              diff = abs(benz-alex);
            }
        }
    }
    printf("%d\n",it);
    return 0;
}
