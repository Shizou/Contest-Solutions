#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int R,C,N,in;
vector< vector<int> > spread(100);

bool compare( vector<int> left, vector<int> right){
    if(left[in-1] < right[in-1])return true;
    return false;
}
int main(){
  //  freopen("input.txt","r",stdin);
    scanf("%d%d",&R,&C);
    for(int i = 0; i < R;i++){
        for(int j = 0; j < C;j++){
            scanf("%d",&in);
            spread[i].push_back(in);
        }
    }
    scanf("%d",&N);
    for(int k = 0;k < N;k++){
        scanf("%d",&in);
        stable_sort(spread.begin(),spread.begin()+R,compare);
    }
    for(int i = 0; i < R;i++){
        for(int j = 0; j < C;j++){
            printf("%d ",spread[i][j]);
        }
        printf("\n");
    }
}
