#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int N,M,a,b;
vector< pair<int,int> > bs;
vector< pair<int,int> > el;

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d",&N,&M);
    for(int i = 0; i < N;i++){
        scanf("%d%d",&a,&b);
        bs.push_back( make_pair(a,b));
    }
    for(int i = 0; i < M;i++){
        scanf("%d%d",&a,&b);
        el.push_back( make_pair(a,b));
    }
    int d_bs = 0, d_el = 0,ldr_chng = 0,t = 0;
    int ld_bs = 0, ld_el = 0;
    bool start = true;
    bool flag = false;
    while( (bs[0].second > 0 || el[0].second > 0) && (bs.size() > 0 && el.size() > 0) ){
        d_bs+= (bs[0].second > 0) ? bs[0].first:0 ;
        d_el+= (el[0].second > 0) ? el[0].first:0 ;
        //printf("time: %d\nDBS : %d\nDEL : %d\n",++t,d_bs,d_el);
        if(start){
            start = false;
            if(d_bs == d_el)flag = true;
        }
        if(d_bs > d_el && (ld_bs <= ld_el))
            ldr_chng++;
        else if(d_el > d_bs && (ld_el <= ld_bs))
            ldr_chng++;
       // printf("%d\n\n",ldr_chng);
        ld_bs = d_bs;
        ld_el = d_el;
        bs[0].second--;
        el[0].second--;
        if(bs[0].second == 0)
            bs.erase(bs.begin());
        if(el[0].second == 0)
            el.erase(el.begin());
    }
    if(!flag)ldr_chng--;
    printf("%d\n",ldr_chng);
}
