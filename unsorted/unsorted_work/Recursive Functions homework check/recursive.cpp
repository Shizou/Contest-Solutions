/** Author : William G.
    Date   : 12/10/14
    Purpose: Verification of recursive functions
    Instructions: Update the recursive functions type options (and the functions themselves)
                  to your liking then simply input the respective variables that are to be queried.
*/

#include<iostream>
#include<cstdio>
#include<algorithm>
#define Fill2D(a,b) fill(&(a)[0][0], &(a)[0][0]+sizeof(a)/sizeof((a)[0][0]), (b))
#define Fill3D(a,b) fill(&(a)[0][0][0], &(a)[0][0][0]+sizeof(a)/sizeof((a)[0][0][0]), (b))
using namespace std;

// Recursive function type options
bool two_var = true, three_var = false;
const long long INF = 1 << 24;
const int SIZE = 1000, SIZE3D = 100;

long long xin,yin,zin;
long long memo[SIZE];
long long memo2D[SIZE][SIZE];
long long memo3D[SIZE3D][SIZE3D][SIZE3D];

long long f(long long x){
    if(x > 0){
        if(memo[x] != INF)
            return memo[x];
        else{
            memo[x] = f( f(x-3)) + 3;
            printf("f(%lld) = %lld\n",x,memo[x]);
            return memo[x];
        }
    }
    else{
        memo[x] = x*x - 2;
        printf("f(%lld) = %lld\n",x,memo[x]);
        return memo[x];
    }
}
long long f(long long x,long long y){
    if(x > 3){
        if(memo2D[x][y] != INF)
            return memo2D[x][y];
        else{
            memo2D[x][y] = f(x-3,y+2)-1;
            printf("f(%lld, %lld) = %lld\n",x,y,memo2D[x][y]);
            return memo2D[x][y];
        }
    }
    else if(x == 3){
        memo2D[x][y] = x+y;
        printf("f(%lld, %lld) = %lld\n",x,y,memo2D[x][y]);
        return memo2D[x][y];
    }
    else if(x < 3){
        memo2D[x][y] = f(2*x+1, y-4) +1;
        printf("f(%lld, %lld) = %lld\n",x,y,memo2D[x][y]);
        return memo2D[x][y];
    }
}
long long f(long long x, long long y, long long z){
    return 0;
}
int main(){
    if(three_var){
        scanf("%lld%lld",&xin,&yin,&zin);
        Fill3D(memo3D,INF);
    }
    else if(two_var){
        scanf("%lld%lld",&xin,&yin);
        Fill2D(memo2D,INF);
    }
    else{
        scanf("%lld",&xin);
        fill(memo, memo+SIZE, INF);
    }
    if(three_var)printf("f(%lld,%lld,%lld) = %lld\n",xin,yin,zin,f(xin,yin,zin));
    else if(two_var)printf("f(%lld,%lld) = %lld\n",xin,yin,f(xin,yin));
    else       printf("f(%lld) = %lld\n",xin,f(xin));
    return 0;
}
