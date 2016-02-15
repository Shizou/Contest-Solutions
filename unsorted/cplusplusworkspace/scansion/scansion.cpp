#include <iostream>
#include <cstdio>
#include <vector>
#define pb push_back
using namespace std;

const int N = 10000,K = 17,M = 10007;
int dp[N];
string s;
string A[K] = {"00","01","10","11","000","001","010","011","100","101","110","111","0001","0010","0110","1000","1001"};



int main() {
    freopen("input.txt","r",stdin);
	cin >> s;
	dp[0]=1;
    for(int i = 0;i <= s.size();i++){
        for(int k = 0,pos = 0;k < K;k++){
            pos = i-A[k].size();
            if(pos < 0)break;
            else{
                if(s.substr(pos,A[k].size()) == A[k]){
                    dp[i]+=dp[pos];
                    dp[i]%=M;
                }
            }
        }
    }
    for(int i = 0;i <= s.size();i++)
        printf("%d\n",dp[i]);
    printf("%d\n",dp[s.size()]%M);
	return 0;
}
