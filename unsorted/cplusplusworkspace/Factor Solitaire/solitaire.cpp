#include<iostream>
#include<cmath>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#define mp make_pair
using namespace std;

int N;
vector<int>factors;
vector<int>cost(5000000,1<<23);

void sieve(){
    vector<bool>v(N+5,true);
    v[0]=v[1]=false;
    factors.push_back(1);
    for(int i = 2; i < sqrt(N+5);++i){
        if(v[i]){
            for(int j = i*i;j < N+5;j+=i)v[j]=false;
            factors.push_back(i);
        }
    }
    for(int i = sqrt(N)-1;i < N+5;++i)
        if(v[i])factors.push_back(i);
}
int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&N);
    sieve();
    // minimize cost using a min heap so we know for sure
    // when we get to N that this will be the minimum cost.
    priority_queue< pair<int,int> >q;
    q.push(mp(0,1));
    while(!q.empty()){
        int cst = -(q.top().first);
        int c   = q.top().second;
        q.pop();
        if(c > N || cost[c] <= cst)
            continue;
        else
            cost[c] = cst;
        if(c == N){
            printf("%d\n",cst);
            break;
        }
        for(int i = 0; i < factors.size() && factors[i] <= c;++i){
            if(c%factors[i] == 0){
                int a = factors[i],b = c/factors[i];
                q.push(mp(-(cst+b),c+a));
                q.push(mp(-(cst+a),c+b));
            }
        }
    }
    return 0;
}
