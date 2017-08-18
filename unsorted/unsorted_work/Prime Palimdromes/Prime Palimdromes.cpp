#include <stdio.h>
#include <string>
#include <math.h>
#include <vector>
#include <iostream>

using namespace std;
int t,m,n,cnt;
vector<bool>p(1000005,true);

void sieve(){
    for(int i = 2;i <= 1000;i++){
        if(p[i]){
            for(int j = 2; i*j <= 1000000;j++) p[i*j] = 0;
        }
    }
}
bool palidin(int i){
    int num = i, rev = 0, dig = 0;
    while (num > 0){
        dig = num % 10;
        rev = rev * 10 + dig;
        num = num / 10;
    }
    return rev == i ? true:false;
}
int main(){
    sieve();
    t = 5;
    while(t--){
        scanf("%d%d",&n,&m);
        for(;n <= m;n++)if(p[n] && palidin(n))cnt++;
        cout << cnt << endl;
        cnt = 0;
    }
}
