#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

vector<bool>v(1000001,true);

int N;

void sieve(){
    for(int i = 2; i < 1000;i++){
        if(v[i]){
            for(int j = i*i; j <= 1000000;j+=i){
                v[j] = false;
            }
        }
    }

}
int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&N);
    sieve();
    for(int i = 2; i <= N/2;i++){
        if( !v[i] && !v[N-i]){
            printf("%d %d\n",i,N-i);
            break;
        }
    }
    return 0;
 }
