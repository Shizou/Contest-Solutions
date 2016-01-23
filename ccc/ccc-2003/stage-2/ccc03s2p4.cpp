#include <iostream>
#include <cstdio>
#include <algorithm>
#include<vector>

using namespace std;

int arr[] = {1,2,3,4,5,6,7,8,9};
int N,K,a,b,cnt;
vector< pair<int,int> > cst;

int find_nth(int n){
    for(int i = 0; i < N;++i)
        if(arr[i] == n)return i;
    return -1;
}
int main(){
    scanf("%d",&N);
    scanf("%d",&K);
    for(int i = 0; i < K;i++){
        scanf("%d%d",&a,&b);
        cst.push_back( make_pair(a,b));
    }
    do{
        bool pos = true;
        for(int i = 0; i < K;++i){
            if( !(find_nth(cst[i].first) < find_nth(cst[i].second)) ){
                pos = false;
                break;
            }
        }
        if(pos)++cnt;
    }while(next_permutation(arr, arr+N));
    printf("%d\n",cnt);
    return 0;
}

