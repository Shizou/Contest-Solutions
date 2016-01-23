#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define lowbit(x) x&(-x)
#define MAXN (int)1e5+1
using namespace std;

int N,tree[MAXN];
vector< pair<int,int> >arr;

void update_tree(int x){
    for(int i = x; i < MAXN;i+=lowbit(i))
        tree[i]++;
}
int query_tree(int x){
    int sum = 0;
    for(int i = x; i > 0;i-=lowbit(i))
        sum+=tree[i];
    return sum;
}
int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&N);
    for(int i = 0,a = 0; i < N;i++){
        scanf("%d",&a);
        arr.push_back(make_pair(a,i+1));
    }
    sort(arr.begin(),arr.end(),greater< pair<int,int> >());
    double ans = 0;
    for(int i = 0; i < N;i++){
        update_tree(arr[i].second);
        ans += query_tree(arr[i].second);
    }
    ans/=N;
    printf("%.2f\n",ans);
    return 0;
}
