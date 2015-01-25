#include<cstdio>
#include<iostream>
#include<vector>
#include<fstream>
#include<cmath>
using namespace std;
int n,in,m;
vector<int> t[100];
struct path{
    int r,c,s;
};
int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        for(int j = 0;j < i+1;j++){
            scanf("%d",&in);
            t[i].push_back(in);
        }
    }
    t[1][0]+= t[0][0];
    t[1][1]+=t[0][0];
    for(int x = 2;x < n;x++){
        for(int y = 0;y < x+1;y++){
            if(y-1 < 0)                t[x][y] += t[x-1][y];
            else if(y+1 > t[x-1].size()) t[x][y] += t[x-1][y-1];
            else                       t[x][y] += max(t[x-1][y-1],t[x-1][y]);
        }
    }
    for(int y = 0;y < n;y++){
        if(t[n-1][y] > m) m = t[n-1][y];
    }
    printf("%d\n",m);
    //fclose(stdin);
    return 0;
}
