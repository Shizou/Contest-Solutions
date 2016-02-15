#include<iostream>
#include<fstream>
#include<stdio.h>
#include<math.h>

using namespace std;
int bt,np,yp,goal,cnt,temp;
int main(){
    //freopen("input.txt","r",stdin);
    cin >> bt >> np >> yp >> goal;
    for(int i = 0;i <= ceil(goal/bt);i++){
        for(int j = 0;j <= ceil(goal/np);j++){
            for(int k = 0;k <= ceil(goal/yp);k++){
                temp = bt*i + np*j + yp*k;
                if(temp <= goal && temp != 0){
                    printf("%d Brown Trout, %d Northern Pike, %d Yellow Pickerel\n",i,j,k);
                    cnt++;
                }
            }
        }
    }
    printf("Number of ways to catch fish: %d\n",cnt);
    //fclose(stdin);
    return 0;
}

