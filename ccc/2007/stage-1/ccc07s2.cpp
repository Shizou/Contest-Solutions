#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define A first
#define L second.first
#define W second.second.first
#define H second.second.second
using namespace std;

int N,M;
vector< pair<int,pair<int,pair<int,int> > > >box;

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&N);
    for(int i = 0,l,w,h; i < N;i++){
        scanf("%d%d%d",&l,&w,&h);
        box.pb(mp(l*w*h,mp(l,mp(w,h))));
    }
    sort(box.begin(),box.end());
    scanf("%d",&M);
    for(int i = 0; i < M;i++){
        int D[3],P = 1;
        scanf("%d%d%d",&D[0],&D[1],&D[2]);
        for(int j = 0;j < N;j++){
            sort(D,D+3);
            do{
                if( P == 1 && D[0] <= box[j].L && D[1] <= box[j].W && D[2] <= box[j].H){
                    printf("%d\n",box[j].A);
                    P = 0;
                }
            }while(next_permutation(D,D+3));
        }
        if(P == 1)printf("Item does not fit.\n");
    }
    return 0;
}

