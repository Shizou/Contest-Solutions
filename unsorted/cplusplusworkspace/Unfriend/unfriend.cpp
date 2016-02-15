#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
using namespace std;

int N,in,cnt;
vector<int>adj[6];
set<string>v;

void dfs(int n,string s){
    if(adj[n].size() == 0){
        if(v.find(s) == v.end()){
            cout << s << endl;
            cnt++;
            v.insert(s);
        }
    }
    else{
        for(int i = 0; i < adj[i].size();i++){
            s+= (adj[n][i]+'0');
           //cout << s << endl;
            dfs(adj[n][i], s);
            s.erase(s.size()-1,1);
        }
    }
}
int main(){
    freopen("input.txt","r",stdin);
    scanf("%d",&N);
    for(int i = 0; i  < N-1;i++){
        scanf("%d",&in);
        adj[in-1].push_back(i);
    }
    for(int i = N-1; i >= 0;i--){
        string s;
        s+= (i+'0');
        dfs(i,s);
    }
    //cout << cnt << endl;
    return 0;
}
