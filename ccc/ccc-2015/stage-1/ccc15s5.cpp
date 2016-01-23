/*Only gets 40% of testcases since too slow*/
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
#define to_s(N) static_cast<ostringstream*>(&(ostringstream() << N))->str()
using namespace std;

const int MAXN = 5000, INF = 0x3F3F3F3F;
int N,M,ans;
int DPP[MAXN];
bool v[MAXN],done = false;
vector<int>A,B;


void print_arr(vector<int>&arr){
      for(int i = 0; i < N+M;i++){
        printf("%d ",arr[i]);
    }printf("\n");
}
int find_max(vector<int>&arr){
    int dp[N+M],sum = 0;
    //print_arr(arr);
    memset(dp,0,sizeof(dp));
    for(int i = 0; i < N+M;i++){
        if(i-2 >= 0 && i-3 >= 0)
            dp[i] = max(dp[i-2],dp[i-3])+arr[i];
        else if(i-3 >= 0)
            dp[i] = dp[i-3]+arr[i];
        else if(i-2 >= 0)
            dp[i] = dp[i-2]+arr[i];
        else
            dp[i] = arr[i];
        sum = max(sum,dp[i]);
    }
    return sum;
}

void rec(int depth){
    for(int i = 0; i < M;i++){
        for(int j = 0;j < A.size();j++){
            if(!v[i]){
                v[i] = true;
                A.insert(A.begin()+j,B[i]);
                int tot = find_max(A);
                if(DPP[depth+1] <= tot){
                    DPP[depth+1] = tot;
                    if(depth+1 < M)
                        rec(depth+1);
                }
                A.erase(A.begin()+j);
                v[i] = false;
            }
        }
    }
}
int main(){
    scanf("%d",&N);
    for(int i = 0,j = 0; i < N;i++){
        scanf("%d",&j);
        A.pb(j);
    }
    scanf("%d",&M);
    for(int i = 0, j = 0;i < M;i++){
        scanf("%d",&j);
        B.pb(j);
    }
    rec(0);
    for(int i = 0; i < N+M;i++)
        ans = max(DPP[i],ans);
    printf("%d\n",ans);
    return 0;
}

