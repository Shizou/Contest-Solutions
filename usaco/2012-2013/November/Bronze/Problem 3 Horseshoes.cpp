#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int N = 0,M = 0;
string g[5];
bool v[5][5];
string in;

bool check(string s){
    for(int i = 0;i < s.size()/2;i++)
        if(s[i] == ')')return false;

    for(int i = s.size()/2;i < s.size();i++)
        if(s[i] == '(')return false;

    return true;
}

void dfs(int x, int y, string s){
    if(x < 0 || y < 0 || x > N-1 || y > N-1)return;
    if(v[x][y])return;
    v[x][y] = true;
    s += (g[x][y] == '(') ? '(' : ')';
    if(s.size()%2 == 0 && s.size() > M && check(s) ){
        M = s.size();
    }
    dfs(x+1,y,s);
    dfs(x,y+1,s);
    dfs(x-1,y,s);
    dfs(x,y-1,s);
    v[x][y] = false;
}

int main(){
    cin >> N;
    getline(cin,in);
    for(int i = 0;i < N;i++){
        getline(cin,in);
        g[i] = in;
    }
    dfs(0,0,"");
    cout << M << endl;
}

