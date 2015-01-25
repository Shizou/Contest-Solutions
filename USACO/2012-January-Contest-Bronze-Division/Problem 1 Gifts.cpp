#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int N,B,cnt;
vector< pair<int,int> > cows;// P(i) S(i)
int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d",&N,&B);
    for(int i = 0,pi,si; i < N;i++){
        scanf("%d%d",&pi,&si);
        cows.push_back(make_pair(pi+si,pi));
    }
    sort(cows.begin(),cows.end());
    for(int i = 0; i < cows.size();i++){
        if(B-cows[i].first >= 0){
            B-=cows[i].first;
            cnt++;
        }
        else{
            cows[i].first-=cows[i].second/2;
            if(B-cows[i].first >= 0){
                B-=cows[i].first;
                cnt++;
            }
            break;
        }
    }
    printf("%d\n",cnt);
    return 0;
}
