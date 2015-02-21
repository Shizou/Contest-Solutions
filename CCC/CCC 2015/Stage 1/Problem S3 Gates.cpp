#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<sstream>
#include<algorithm>
using namespace std;

const int MAXN = (int)1e5, INF = 0x3F3F3F3F;
int G,P,cnt;
bool v[MAXN];

int main(){
    memset(v,false,sizeof v);
    scanf("%d%d",&G,&P);
    for(int i = 0,j = 0;i < P;++i){
        scanf("%d",&j);--j;
        for(;j>=0;--j){
            if(!v[j]){
                v[j]=true;
                ++cnt;
                break;
            }
        }
        if(j == -1)
            break;
    }
    printf("%d\n",cnt);
    return 0;
}

