#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int N,x,y,cnt;
vector< pair<int,int> > pnts;
int main(){
    freopen("7.in","r",stdin);
    scanf("%d",&N);
    for(int i = 0 ; i < N;i++){
        scanf("%d%d",&x,&y);
        pnts.push_back( make_pair(x,y));
    }
    sort(pnts.begin(),pnts.end());
    do{
        int d1 = 0;
        /*printf("(0,0)\n");
        for(int i = 0; i < N;i++){
                printf("(%d,%d)\n",pnts[i].first,pnts[i].second);
        }*/
        if( (pnts[0].first == 0 || pnts[0].second == 0) && (pnts[N-1].first == 0 || pnts[N-1].second == 0) ){
            //                             UP{0, +N} DN{0,-N}            RT{+N,0} LT{-N,0}
            d1 = (pnts[0].first == 0) ? ( (pnts[0].second > 0) ? 0:2):( (pnts[0].first > 0) ? 1:3 );
            for(int i = 1; i < N;i++){
                int d2 = (pnts[i-1].first == pnts[i].first) ? ( (pnts[i].second > pnts[i-1].second) ? 0:2):( (pnts[i].first > pnts[i-1].first) ? 1:3 );
                if(d2 != d1 && (pnts[i-1].first == pnts[i].first || pnts[i-1].second == pnts[i].second))
                    d1 = d2;
                else
                    goto not_possible;
            }
            cnt++;
        }
        not_possible:;
    }while(next_permutation(pnts.begin(), pnts.end()));
    printf("%d\n",cnt);
    return 0;
}
