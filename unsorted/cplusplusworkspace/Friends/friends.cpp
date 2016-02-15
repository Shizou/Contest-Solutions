#include<stdio.h>
#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;

int n,x,y;
vector<int> p[10000];
bool v[10000];
struct path{
    int pp,d;
};
int main(){
    freopen("input.txt","r",stdin);
    scanf("%d",&n);
    while(n--){
        scanf("%d%d",&x,&y);
        p[x].push_back(y);
    }
    while(1){
        scanf("%d%d",&x,&y);
        if(x == 0 && y == 0)break;
        bool pos = 0;
        queue< path >q;
        q.push( (path){x,-1});
        while(!q.empty()){
            int pp = q.front().pp;
            int d = q.front().d;
            q.pop();
            if(pp == y){
                printf("Yes %d\n",d);
                pos = 1;
                break;
            }
            if(v[pp])continue;
            v[pp] = 1;
            for(int i = 0;i < p[pp].size();i++){
                q.push( (path){p[pp][i],d+1});
            }
        }
        if(!pos) printf("No\n");
        memset(v,0,sizeof v);
    }
    fclose(stdin);
    return 0;
}


