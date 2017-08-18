#include<iostream>
#include<stdio.h>

using namespace std;

int N,t,h_i,ans;
int h[10000];

int main(){
    scanf("%d",&N);
    for(int i = 0; i < N;i++){
        scanf("%d",&h_i);
        h[i] = h_i;
        t+=h_i;
    }
    t/=N;
    for(int i = 0;i < N;i++){
        if(h[i] < t)
            ans+=t-h[i];
    }
    printf("%d\n",ans);
}
