#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int N,L,S,a,b,c;
vector< pair<int,pair<int,bool> > > pnts;
vector< pair<int,pair<int,int> > > pnts2;

void print_pnts(){
    for(int i = 0; i < pnts.size();i++){
        printf("%s : %d\n", pnts[i].second .second? "START":"END",pnts[i].first);
    }
}
bool compare(pair<int, pair<int,bool> >lft, pair<int, pair<int,bool> >rht){
    return lft.first == rht.first ? (lft.second.second && !rht.second.second):lft.first < rht.first;
}
int main(){
    freopen("input.txt","r",stdin);
    scanf("%d%d%d",&N,&L,&S);
    for(int i = 0; i < N;i++){
        scanf("%d%d%d",&a,&b,&c);
        pnts.push_back(make_pair(a,make_pair(c,true)));
        pnts.push_back(make_pair(b,make_pair(c,false)));
    }

    pnts.push_back( make_pair(0,make_pair(0,true)) );
    sort(pnts.begin(),pnts.end(),compare);
    if(pnts[2].first == 1)pnts.erase(pnts.begin());
    pnts.push_back( make_pair(L,make_pair(0,false)));
    //print_pnts();
    int spky = 0;
    for(int i = 0; i < pnts.size()-1;i++){
        if(pnts[i].second.second && pnts[i+1].second.second){// [ai,bi)
            //printf("[%d,%d)\n",pnts[i].first, pnts[i+1].first);
            spky+= pnts[i].second.first;
            pnts2.push_back(make_pair(pnts[i].first,make_pair(pnts[i+1].first-1,spky)));
        }
        else if(pnts[i].second.second && !pnts[i+1].second.second){//[ai,bi]
            //printf("[%d,%d]\n",pnts[i].first, pnts[i+1].first);
            spky+= pnts[i].second.first;
            pnts2.push_back(make_pair(pnts[i].first,make_pair(pnts[i+1].first,spky)));
        }
        else if(!pnts[i].second.second && !pnts[i+1].second.second){//(ai,bi]
            //printf("(%d,%d]\n",pnts[i].first, pnts[i+1].first);
            spky -= pnts[i].second.first;
            pnts2.push_back(make_pair(pnts[i].first+1,make_pair(pnts[i+1].first,spky)));
        }
        else if(!pnts[i].second.second && pnts[i+1].second.second){//(ai,bi)
            //printf("(%d,%d)\n",pnts[i].first, pnts[i+1].first);
            spky -= pnts[i].second.first;
            pnts2.push_back(make_pair(pnts[i].first+1,make_pair(pnts[i+1].first-1,spky)));
        }
    }
    int cnt = 0;
    for(int i = 0; i < pnts2.size();i++){
        if(pnts2[i].second.second < S){
            //printf("%d %d\n",pnts2[i].first,pnts2[i].second.first);
            cnt += pnts2[i].second.first - pnts2[i].first;
            if(pnts[i].first != 0)cnt++;
        }
    }
    printf("%d\n",cnt);

    return 0;
}
