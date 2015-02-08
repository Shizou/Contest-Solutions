#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

int R,L,cnt;
vector<int> g[30];

int to_10(string &s){
    int p = 0, sum = 0;
    for(int k = 0; k < s.size();k++)
        sum += (s[k]-'0')*pow(2,p++);
    return sum;
}

int main(){
    //freopen("input.txt","r",stdin);
    cin >> R >> L;
    R--,L--;
    for(int i = 0;i <= R;i++){
        string a = "",b = "";
        for(int j = 0;j <= L;j++){
            cin >> b;
            a+=b;
        }
        g[i].push_back(to_10(a));
    }
    for(int i = 1; i<=R;i++){
        int s1 = g[i].size(),s2 = g[i-1].size();
        for(int j = 0;j < s1;j++)
            for(int k = 0; k < s2;k++)
                g[i].push_back(g[i][j]^g[i-1][k]);
        sort(g[i].begin(),g[i].end());
        for(int j = 0;j < g[i].size()-1;j++){
            if(g[i][j] == g[i][j+1]){
                g[i].erase(g[i].begin()+j);
                j--;
            }
        }
    }
    printf("%d\n",g[R].size());
    return 0;
}

