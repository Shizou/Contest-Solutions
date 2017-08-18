#include<iostream>
#include<fstream>
#include<stdio.h>
#include<math.h>
using namespace std;

int main(){
    //freopen("input.txt","r",stdin);
    int p,g,r,o,goal;
    cin >> p >> g >> r >> o >> goal;

    int temp = 0;
    int cnt = 0;
    int min = 999999;
    for(int i = 0;i <= ceil(goal/p);i++){
        for(int j = 0;j <= ceil(goal/g);j++){
            for(int k = 0;k <= ceil(goal/r);k++){
                for(int l = 0;l <= ceil(goal/o);l++){
                    temp = l*o + k*r + j*g + i*p;
                    if(temp == goal){
                        printf("# of PINK is %d # of GREEN is %d # of RED is %d # of ORANGE is %d\n",i,j,k,l);
                        cnt++;
                        temp = l+k+j+i;
                        if(temp < min)
                            min = temp;
                    }

                }
            }
        }
    }
    printf("Total combinations is %d.\n",cnt);
    printf("Minimum number of tickets to print is %d.\n",min);
    //fclose(stdin);
    return 0;
}
