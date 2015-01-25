#include<iostream>
#include<cstdio>
#define min(a,b) a<b?a:b

using namespace std;

int p,g,r,o,t,cnt,min_n;
bool test = true;
int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d%d%d%d",&p,&g,&r,&o,&t);
    min_n = 100000000;
    for(int i = 0;i < 100;i++){
        for(int j = 0;j < 100;j++){
            for(int k = 0; k < 100;k++){
                for(int m = 0; m < 100;m++){
                    int sum = i*p + j*g + k*r + m*o;
                    if(sum == t){
                        printf("# of PINK is %d # of GREEN is %d # of RED is %d # of ORANGE is %d\n",i,j,k,m);
                        cnt++;
                        int tot = i+j+k+m;
                        min_n = min(min_n,tot);
                    }
                }
            }
        }
    }
    printf("Total combinations is %d.\n",cnt);
    printf("Minimum number of tickets to print is %d.\n",min_n);
}
