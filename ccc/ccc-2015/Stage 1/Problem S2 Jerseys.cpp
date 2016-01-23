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
using namespace std;

int J,A,cnt;
char c;
const int MAXN = (int)1e6+1, INF = 0x3F3F3F3F;
int S,L,M;
int arr[MAXN];
bool v[MAXN];
map<char,int>m;
int main(){
    memset(arr,-1,sizeof arr);
    m['S'] = 0,m['M'] = 1,m['L'] = 2;
    scanf("%d%d",&J,&A);
    for(int i = 0; i < J;i++){
        scanf(" %c",&c);
        arr[i] = m[c];
    }
    for(int i = 0,a = 0; i < A;i++){
        scanf(" %c%d ",&c,&a);a--;
        if(arr[a] >= m[c] && !v[a]){
            cnt++;
            v[a] = true;
        }
    }
    printf("%d\n",cnt);
    return 0;
}
