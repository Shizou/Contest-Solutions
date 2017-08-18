#include<iostream>
#include<stdio.h>
#include<fstream>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;

int t,l,n;// lols
int c,r,h,d,cnt;
int field[1000];
int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&l,&n);
        while(n--){
            scanf("%d%d%d",&c,&r,&d);
            for(int i = c-1;i >= c-1-r && i >= 0;i--) field[i] -= d;
            for(int i = c;i < c+r && i < l;i++) field[i] -= d;
        }
        scanf("%d",&n);
        while(n--){
            scanf("%d",&h);
            int pos = 0;
            bool safe = 1;
            while(pos < l){
                h += field[pos];
                if(h <= 0){
                    printf("%d\n",pos+1);
                    safe = 0;
                    break;
                }
                pos++;
            }
            if(safe) printf("Bloon leakage\n");
        }
        memset(field,0,sizeof field);
    }
    //fclose(stdin);
    return 0;
}
