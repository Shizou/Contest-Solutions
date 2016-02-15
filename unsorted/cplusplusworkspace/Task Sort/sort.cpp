#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int N,C,in,it;
map<int, int>mem;
vector< pair<int,pair<int,int> > >freq;//freq, it, val

bool compare(pair<int, pair<int,int> > left,pair<int, pair<int,int> > right ){
    if(left.first > right.first)return true;
    else if(left.first == right.first){
        if(left.second.first < right.second.first)return true;
    }
    return false;
}
int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d",&N,&C);
    for(int i = 0; i < N;i++){
        scanf("%d",&in);
        if(mem.find(in) == mem.end()){
            mem[in] = it++;
            freq.push_back( make_pair(1, make_pair(i,in)) );
        }
        else
            freq[mem[in]].first++;
    }
    sort(freq.begin(),freq.end(), compare);
    for(int i = 0;i < freq.size();i++){
        while(freq[i].first--)printf("%d ",freq[i].second.second);
    }
    printf("\n");
}
