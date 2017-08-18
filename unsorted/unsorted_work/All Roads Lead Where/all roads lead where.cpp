#include<iostream>
#include<stdio.h>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

struct state{
    string n,p;
};
int M,N,T;
string a,b;
vector< int > adj[1000];
vector< bool > v(1000,0);
map< string, int > index;
map< int, string> index2;

string bfs(string sn, string en){
    queue< state > q;
    q.push( (state){sn,""});
    while(!q.empty()){
        string n = q.front().n;
        string p = q.front().p;
        q.pop();
        if(v[index[n]])continue;
        v[index[n]] = true;
        p+=n[0];
        if(n == en)return p;
        for(int i = 0; i < adj[index[n]].size();i++){
            q.push( (state){index2[ adj[index[n]][i]], p} );
        }
    }
    return "swag";
}
int main(){
    //freopen("input.txt","r",stdin);
    cin >> M >> N;
    for(int i = 0;i < M;i++){
        cin >> a >> b;
        if(index.find(a) == index.end()){
            index[a] = T;
            index2[T++]=a;
        }
        if(index.find(b) == index.end()){
            index[b] = T;
            index2[T++]=b;
        }
        adj[index[a]].push_back(index[b]);
        adj[index[b]].push_back(index[a]);
    }
    for(int i = 0; i < N;i++){
        cin >> a >> b;
        cout << bfs(a,b) << endl;
        fill(v.begin(),v.end(),0);
    }
}
