#include<stdio.h>
#include<iostream>
#include<string.h>
#include<queue>
#include<vector>
#include<map>


using namespace std;

int N,NS;
string s,s2;
vector< pair<int, string> > adj[1000];
vector<string> in;
bool v[1000];
map< string, int> m;


bool bfs(){
    queue<int>q;
    int bg = m[s], ed = m[s2];
    q.push(bg);
    for(int i = 0;i < 1000;i++)v[i] = 0;

    while(!q.empty()){
        int n = q.front();
        q.pop();
        if(v[n])continue;
        v[n] = true;

        if(n == ed)return true;
        for(int i = 0;i < adj[n].size();i++){
            q.push( adj[n][i].first );
        }
    }

    return false;
}

int nextApos(int i,string ss){
    int cnt = 0;
    for(;i < ss.size();i++){
        cnt++;
        if(ss[i] == '\"')return cnt;
        if(ss[i] == '>')break;
    }
    return 0;
}
int nextClose(int i,string ss){
    int cnt = 0;
    for(;i < ss.size();i++){
        cnt++;
        if(ss[i] == '<'){
                if(i+3 < ss.size()){
                    if(ss.substr(i,4) == "</A>" ){
                         return cnt;
                    }
                 }
        }
    }
    return 0;
}
int main(){
    //freopen("input.txt","r",stdin);
    cin >> N;
    getline(cin,s);
    for(int i = 0;i < N;i++){
        getline(cin,s);
        in.push_back(s);
        m[s] = i;
        while(getline(cin,s)){
            if(s == "</HTML>")break;
            for(int j = 0;j < s.size();j++){
                if(s[j] == '<'){
                    if(j + 9 < s.size()){
                        if( s.substr(j, 9) == "<A HREF=\""){
                                adj[i].push_back(make_pair(-1, s.substr(j+9,nextApos(j+10,s))));
                                cout << "Link from " << in[i] << " to " << adj[i][adj[i].size()-1].second << endl;
                        }

                    }
                }

            }
        }

    }
    NS = N;
    for(int i = 0;i < N;i++){
        for(int j = 0;j < adj[i].size();j++){
            if( m.find(adj[i][j].second) != m.end())
                adj[i][j].first = m[adj[i][j].second];
            else{
                m[adj[i][j].second] = NS;
                adj[i][j].first = m[adj[i][j].second];
                NS++;
            }
        }
    }
    cout << endl;
    while(getline(cin,s)){
        if(s == "The End")break;
        getline(cin,s2);
        if(bfs())
            cout << "Can surf from " << s << " to " << s2 << endl;
        else
            cout << "Can't surf from " << s << " to " << s2 << endl;
    }
    return 0;
}
