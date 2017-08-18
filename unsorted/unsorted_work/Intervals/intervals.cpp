#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

int N,Q,a,b,q;
const int POS_INF = (int)10e9, NEG_INF = -(int)10e9;
vector< pair<int,bool> >pnts;
vector< pair<int, pair<int,int> > >overlap_pnts; // begin interval, end interval, overlap counter


void print_pnts(){
    for(int i = 0; i < overlap_pnts.size();i++){
        printf("(S:%d ,E:%d) O:%d\n", overlap_pnts[i].first,overlap_pnts[i].second.first,overlap_pnts[i].second.second);
    }
}
bool compare(pair<int,bool>lft, pair<int,bool>rht){
    return lft.first == rht.first ? (lft.second && !rht.second):lft.first < rht.first;
}

bool predicate(int q, int mid){
    return overlap_pnts[mid].first >= q || overlap_pnts[mid].second.first >= q;
}
bool predicate2(int q,int mid){
    return overlap_pnts[mid].first <= q && overlap_pnts[mid].second.first >= q;
}
int binary_search(int lo, int hi, int &q){
        int mid;
        while(lo < hi){
            mid = lo + (hi-lo)/2;
            //printf("LO: %d HI:%d MID:%d\n",lo,hi,mid);
            if(predicate(q,mid))
                hi = mid;
            else
                lo = mid+1;
        }
        //printf("QRY: %d LO: %d HI:%d MID:%d\n",q,lo,hi,mid);
        if(!predicate2(q,lo)){
            return -1;// not found
        }
        return lo;
}
int linear_search(int query){
    int index = 0;
    int val = 0;
    for(int i = 0; i < overlap_pnts.size();i++){
        if(overlap_pnts[i].first <= query && overlap_pnts[i].second.first >= query){
            if(overlap_pnts[i].second.second > val){
                index = i;
                val = overlap_pnts[i].second.second;
            }
        }
        else if(overlap_pnts[i].first >= query && overlap_pnts[i].second.first >= query)
            break;
    }
    return index;
}
int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d",&N,&Q);
    bool hard_code = true;
    for(int i = 0; i < N;++i){
        scanf("%d%d",&a,&b);
        pnts.push_back(make_pair(a,true));
        pnts.push_back(make_pair(b,false));
        if(a < -1000 || b < -1000 || a > 1000 || b > 1000)hard_code = false;
    }
    sort(pnts.begin(),pnts.end(),compare);
    if(!hard_code){
        int overlap = 0;
        for(int i = 0; i < pnts.size()-1;i++){
            if(pnts[i].second){
                overlap++;
                if(pnts[i+1].second)
                    overlap_pnts.push_back(make_pair(pnts[i].first,make_pair(pnts[i+1].first-1,overlap)));
                else
                    overlap_pnts.push_back(make_pair(pnts[i].first,make_pair(pnts[i+1].first,overlap)));
            }
            else{
                overlap--;
                if(pnts[i+1].second)
                     overlap_pnts.push_back(make_pair(pnts[i].first+1,make_pair(pnts[i+1].first-1,overlap)));
                else
                    overlap_pnts.push_back(make_pair(pnts[i].first+1,make_pair(pnts[i+1].first,overlap)));
            }
        }
    }
    else{
        int overlap = 1;
        overlap_pnts.push_back(make_pair(NEG_INF,make_pair(pnts[0].first-1,0)));//[-infinity,starting point of first interval)
        for(int i = 1; i < pnts.size();i++){
            if(pnts[i].second){
                overlap_pnts.push_back(make_pair(pnts[i-1].first,make_pair(pnts[i].first,overlap)));
                overlap++;
            }
            else{
                overlap_pnts.push_back(make_pair(pnts[i-1].first,make_pair(pnts[i].first,overlap)));
                overlap--;
            }
        }
        overlap_pnts.push_back(make_pair(pnts[pnts.size()-1].first+1,make_pair(POS_INF,0)));//(ending point of ending interval,+infinity]
    }
    //print_pnts();
    for(int i = 0; i < Q;i++){
        scanf("%d",&q);
        if(!hard_code){
            int index = binary_search(0,overlap_pnts.size()-1,q);
            if(index == -1)
                printf("%d\n",0);
            else{
                int ans = overlap_pnts[index].second.second;
                for(int i = index; i >= 0;i++){
                    if(predicate2(q,i) && overlap_pnts[i].second.second > ans){
                        ans = overlap_pnts[i].second.second;
                    }
                    else
                        break;
                }
                printf("%d\n",ans);
            }
        }
        else{
            int index = linear_search(q);
            printf("%d\n",overlap_pnts[index].second.second);
        }
    }
    return 0;
}
