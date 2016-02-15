#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

struct fox{
    int a,s,o,cnt;
    bool awake;
};

int T,N,in_a,in_s,in_o;
vector<fox>foxen;

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        for(int i = 0; i < N;i++){
            scanf("%d%d%d",&in_a,&in_s,&in_o);
            //printf("A: %d S:%d O: %d\n",in_a,in_s,in_o);
            int test = in_o;
            bool swch = true;
            while(true){
                if(swch && test - in_a >= 0){
                    test-=in_a;
                    swch = false;
                }
                else if(!swch && test - in_s >= 0){
                    test-=in_s;
                    swch = true;
                }
                else
                    break;
            }
           //printf("%d %d\n",in_o,test);
            //printf("%s\n", (swch) ? "awake":"asleep");
            foxen.push_back((fox){in_a,in_s,0,test,swch});
        }
        bool pos = true;
        int s_cnt = 0,d_cnt = 0;
        while(pos){
            pos = false;
            s_cnt = 0;
            d_cnt++;
            for(int i = 0; i < N;i++){
                if(foxen[i].o != 20000){
                    pos = true;
                    foxen[i].cnt++;
                    foxen[i].o++;
                    if(foxen[i].awake && foxen[i].cnt == foxen[i].a){
                        foxen[i].awake = false;
                        foxen[i].cnt = 0;
                    }
                    else if(!foxen[i].awake && foxen[i].cnt == foxen[i].s){
                        foxen[i].awake = true;
                        foxen[i].cnt = 0;
                    }
                    if(!foxen[i].awake)
                        s_cnt++;
                }
                else
                    foxen[i].awake = true;
            }
           /* printf("Hour:%d\n",d_cnt);
            for(int i = 0;i < N;i++)
                printf("Fox %d is %s, cnt is %d\n", (i+1), (foxen[i].awake) ? "awake":"asleep",foxen[i].cnt);
            printf("\n");*/
            if(s_cnt == N){
                printf("%d\n",d_cnt);
                break;
            }
        }
        if(s_cnt != N)
            printf("Foxen are too powerful\n");
        foxen.clear();
    }
}
