#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int N,a,b, min_d = 1000000001;
vector< pair<int,int> > in;
int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&N);
    for(int i = 0; i < N;i++){
        scanf("%d%d",&a,&b);
        in.push_back( make_pair(a,b));
    }
    sort(in.begin(), in.end());
    do{
        int s_t = 1, b_t = 0;
        for(int i = 0; i < N;i++){
            s_t*=in[i].first;
            b_t+=in[i].second;
            min_d = min(min_d, abs(s_t-b_t));
        }
    }while( next_permutation(in.begin(), in.end()));
    printf("%d\n",min_d);
    return 0;
}
