#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

struct cmd{
    int dir,h,s;// direction, hours(time), speed(m/s)
};

int N,a,b,c;
vector< cmd > cmds;

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&N);
    for(int i = 0; i < N;i++){
        scanf("%d%d%d",&a,&b,&c);
        a = (a == 12) ? 0: ( (a == 9) ? 3: ((a == 6) ? 2:1));
        cmds.push_back( (cmd){a,b,c});
    }
    int x = 0, y = 0,t = 0,br = 0;
    for(int i = 0; i < cmds.size();i++){
       while(cmds[i].h--){
            if(t != 0 && t%5 == 0)br++;
            t++;
            for(int j = 1; j <= cmds[i].s;j++){
                x+= (cmds[i].dir == 0) ? 1: ((cmds[i].dir  == 2) ? -1:0);
                y+= (cmds[i].dir == 1) ? 1: ((cmds[i].dir  == 3) ? -1:0);
                if(x == 0 && y == 0){
                    printf("%d\n",br);
                    return 0;
                }
            }
        }
    }
    printf("-1\n");
    return 0;
}
