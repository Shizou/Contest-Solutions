#include<iostream>
#include<stdio.h>
#include<map>
using namespace std;

int N,K,in,max_bp;
map<int,int> loc;
int main(){
    scanf("%d%d",&N,&K);
    for(int i = 0; i < N;i++){
        scanf("%d",&in);
        if(loc.find(in) == loc.end())
            loc[in] = i+1;
        else{
            if( (i+1)-loc[in] <= K){
                if(in > max_bp)max_bp = in;
            }
            loc[in] = i+1;
        }
    }
    printf("%d\n",max_bp);
}
