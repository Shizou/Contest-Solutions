#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<sstream>
#include<algorithm>
#define pb push_back
#define mp make_pair
using namespace std;

const int MAXN = (int)1e1, INF = 0x3F3F3F3F;
int K,sum;
vector<int>arr;
int main(){
    scanf("%d",&K);
    for(int i = 0,j = 0; i < K;i++){
        scanf("%d",&j);
        if(j == 0)
            arr.pop_back();
        else
            arr.push_back(j);
    }
    for(int i = 0; i < arr.size();i++)
        sum+=arr[i];
    printf("%d\n",sum);
    return 0;
}

