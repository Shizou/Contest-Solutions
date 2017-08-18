#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int N,x,y;
int mx[150];
vector< pair<int,int> >arr;

int r(int it, int cnt){
    for(int i = it+1; i < N;i++){
        if(arr[it].second <= arr[i].first){
            int pos_cnt = r(i,cnt+1);
            if( cnt < pos_cnt)return pos_cnt;
        }
    }
    return cnt;
}
int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&N);
    for(int i = 0; i < N;i++){
        scanf("%d%d",&x,&y);
        arr.push_back( make_pair(x,y) );
    }
    sort(arr.begin(),arr.end());
    for(int i = 0; i < N;i++){
        mx[i] = r(i,1);
    }
    sort(mx, mx+N, greater<int>());
    printf("%d\n",mx[0]+mx[1]);
    return 0;
}
