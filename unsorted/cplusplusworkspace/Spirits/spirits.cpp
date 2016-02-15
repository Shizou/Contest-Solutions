#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int X,A,B,N,M,p,lht_cnt,drk_cnt;
vector< pair<int,int> > lht; // <pos,power>
vector< pair<int,int> > drk; // <pos,power>
int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d%d%d%d",&X,&A,&B,&N,&M);
    for(int i = 0; i < N;i++){
        scanf("%d",&p);
        lht.push_back( make_pair(i*-A,p) );
    }
    for(int i = 0; i < M;i++){
        scanf("%d",&p);
        drk.push_back( make_pair(X+i*B,p) );
    }
    while( !(lht.size() == 0 && drk.size() == 0) ){
        // move light souls
        for(int i = 0; i < lht.size();i++)lht[i].first++;

        if(lht.size() != 0 && drk.size() != 0 && lht[0].first == drk[0].first){
            if(lht[0].second > drk[0].second)drk.erase(drk.begin());
            else                             lht.erase(lht.begin());
        }
        if(lht.size() != 0 && lht[0].first == X){
            lht_cnt++;
            lht.erase(lht.begin());
        }
        if(drk.size() != 0 && drk[0].first == 0){
            drk_cnt++;
            drk.erase(drk.begin());
        }

        // move dark souls
        for(int i = 0; i < drk.size();i++)drk[i].first--;

        if(lht.size() != 0 && drk.size() != 0 && lht[0].first == drk[0].first){
            if(lht[0].second > drk[0].second)drk.erase(drk.begin());
            else                             lht.erase(lht.begin());
        }
        if(lht.size() != 0 && lht[0].first == X){
            lht_cnt++;
            lht.erase(lht.begin());
        }
        if(drk.size() != 0 && drk[0].first == 0){
            drk_cnt++;
            drk.erase(drk.begin());
        }

    }
    printf("%d %d\n",lht_cnt, drk_cnt);
    return 0;
}
