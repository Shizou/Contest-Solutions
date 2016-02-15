#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

const int MAXH = 1000;
int H,K,lo,hi,mid;
vector<int>house;
bool v[MAXH];

int dist(int h1,int h2){
  return min(h2-h1,(int)1e6-h2+h1);
}

bool predicate(int hose_len,int k_left = K,int h_left = H){
  memset(v,false,sizeof(v));
  for(int i = 0;i < (int)house.size() && h_left > 0 && k_left > 0;++i){
      if(v[i])
        continue;
      else{
        k_left--,h_left--,v[i] = true;
        for(int k = (i+1)%H;k < (int)house.size();++k){
            if(!v[k] && dist(house[i],house[k]) <= 2*hose_len)
                h_left--,v[k] = true;
            else
                break;
        }
      }
  }
  return (h_left == 0) ? true:false;
}

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&H);
    for (int i = 0,j = 0; i < H; ++i){
      scanf("%d",&j);
      house.push_back(j);
    }
    sort(house.begin(),house.end());
    scanf("%d",&K);
    lo = 0,hi = (int)1e6,mid = (lo+hi)/2;
    while(lo < hi){
        if(predicate(mid))// this hose length works so it's now the upperbound
            hi = mid;
        else              // this hose length is too short
            lo = mid+1;
        mid = (lo+hi)/2;
    }
    printf("%d\n",mid);
    return 0;
}