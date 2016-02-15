#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define db 1
using namespace std;

int T,N;
int overlap;
int best[2];
map<int,int>pts;

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d",&T);
    for(int t = 1;t <= T;++t){
        scanf("%d",&N);
        for(int i = 0,a,b;i < N;++i){
            scanf("%d%d",&a,&b);
            pts[a]++;
            pts[b+1]--;
        }
        overlap = best[0] = best[1] = 0;
        for (map<int, int>::iterator it = pts.begin(); it != pts.end(); it++){
             if(db){
                printf("[%d,%d]\n",it->first,it->second);
             }
             overlap+=it->second;
             if(best[0] < overlap)
                best[0] = overlap;
             else if(best[1] < overlap)
                best[1] = overlap;
        }
        printf("Case %d: %d\n",t,best[0]+best[1]);
        pts.clear();
    }
    return 0;
}