#include<iostream>
#include<cstdio>

using namespace std;

int r[4],t[6];
int max_w;
int main(){
   // freopen("input.txt","r",stdin);
    for(int i = 0; i < 4;i++)scanf("%d",&r[i]);
    for(int i = 0; i < 6;i++)scanf("%d",&t[i]);

    for(int k = 0; k < 4;k++)
    for(int m = 0; m < 4;m++)
    for(int b = 0; b < 4;b++)
    for(int a = 0; a < 4;a++)
    for(int l = 0; l < 4;l++)
    for(int o = 0; o < 4;o++){
        int w = 0;
        int temp_t[4] = {0,0,0,0};
        temp_t[k]+= t[0];
        temp_t[m]+= t[1];
        temp_t[b]+= t[2];
        temp_t[a]+= t[3];
        temp_t[l]+= t[4];
        temp_t[o]+= t[5];
        for(int i = 0; i < 4;i++)
            if(temp_t[i] > r[i])w++;

        max_w = max(max_w,w);
    }
    printf("%d\n",max_w);
    return 0;
}
