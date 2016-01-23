#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#include<cmath>
#include<cstring>
#include<map>
#include<set>

using namespace std;

int A,B,N,cost = 1<<25;
int main(){
    //freopen("input.txt","r",stdin);
    freopen("cowroute.in","r",stdin);
    freopen("cowroute.out","w",stdout);
    scanf("%d%d%d",&A,&B,&N);
    for(int i = 0, c = 0, n = 0; i < N;i++){
        scanf("%d%d",&c,&n);
        bool after = false, good = false;
        for(int i = 0,j = 0; i < n;i++){
            scanf("%d",&j);
            if(j == A && !after)
                after = true;
            if(j == B && after)
                good = true;
        }
        if(good)
            cost = min(cost,c);
    }
    printf("%d\n",cost == 1<<25 ? -1:cost);
    return 0;
}
