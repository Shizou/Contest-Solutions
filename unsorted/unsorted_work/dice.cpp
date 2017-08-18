#include<stdio.h>
using namespace std;
int a,b,c;
int main(){
    scanf("%d%d",&a,&b);
    for(int i = 1;i <= a;i++){
        for(int j = 1;j <= b;j++){
            if(j+i == 10) c++;//awwwww yeaaaahhh
        }
    }
    if(c == 1)
        printf("There is 1 way to get the sum 10.");
    else
        printf("There are %d ways to get the sum 10.",c);
    return 0;
}
