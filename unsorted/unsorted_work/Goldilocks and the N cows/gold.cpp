#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int N,X,Y,Z,ai,bi;
int mx_milk,t_milk;
vector< pair<int,int> > pnts;

bool compare( pair<int,int> lft, pair<int,int> rht){
    return (lft.first < rht.first) ? true: ((lft.first == rht.first) ? (lft.second > rht.second):false);
}

int main() {
    //freopen("input.txt","r",stdin);
	scanf("%d%d%d%d",&N,&X,&Y,&Z);
	for(int i = 0; i < N;++i){
		scanf("%d%d",&ai,&bi);
        pnts.push_back( make_pair(ai,Y-X));
        pnts.push_back( make_pair(bi,Z-Y));
	}
	sort(pnts.begin(),pnts.end(),compare);
    t_milk = mx_milk =  N*X;
    for(int i = 0; i < pnts.size();i++){
        if(pnts[i].second < 0){
            mx_milk = max(mx_milk,t_milk);
            t_milk+=pnts[i].second;
        }
        else{
            t_milk+=pnts[i].second;
        }
    }
	printf("%d\n",mx_milk);
	return 0;
}
