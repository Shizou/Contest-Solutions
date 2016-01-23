#include<iostream>
#include<cstdio>
using namespace std;

int T,N,u,l,e;
int main(){
    //freopen("input.txt","r",stdin);
    for(cin >> T;T!=0;T--){
        cin >> N;
        u = l = e = 0;
        u = N;
        for(int r = 0; r < 50000;r++){
            printf("Round %d: %d undefeated, %d one-loss, %d eliminated\n",r,u,l,e);
            if(u == 1 && l == 1){
                u = 0, l = 2;
                continue;
            }
            e = e + l/2;
            l = (l%2 == 0 ? l/2:l/2+1) + u/2;
            u = u%2 == 0 ? u/2:u/2+1;
            if(u==0 && l == 1){
                printf("Round %d: %d undefeated, %d one-loss, %d eliminated\n",++r,u,l,e);
                printf("There are %d rounds.\n\n",r);
                break;
            }
        }
       // break;
    }
}
