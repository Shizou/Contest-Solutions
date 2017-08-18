#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int N,k,c,c_tot,min_d = 1<<23;
vector< int > arr;// < candy count, calorie count>

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d",&N);
    for(int i = 0; i < N;i++){
        scanf("%d%d",&k,&c);
        for(int j = 0; j < k;j++)
            arr.push_back(c);
        c_tot+=k*c;
    }
    sort(arr.begin(),arr.end());

    printf("%d\n",min_d);
    return 0;
}
