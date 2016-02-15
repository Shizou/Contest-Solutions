#include<iostream>
#include<fstream>
#include<queue>
#include<vector>
#include<string.h>
using namespace std;

int m,n,a,b;
vector<int>p[1000001];

bool bfs(int x,int y){
    queue<int>q;
    bool v[1000001];
    memset(v,0,sizeof v);
    q.push(x);
    while(!q.empty()){
        int pe = q.front();
        q.pop();
        if(v[pe]) continue;
        if(pe == y){
            return true;
        }
        v[pe] = 1;
        for(int i = 0;i < p[pe].size();i++) q.push(p[pe][i]);
    }
    return false;
}
int main(){
    //freopen("input.txt","r",stdin);
    cin >> m >> n;
    for(int i = 0;i < n;i++){
        cin >> a >> b;
        p[a].push_back(b);
    }
    cin >> a >> b;
    if( bfs(a,b))
        cout << "yes" << endl;
    else if(bfs(b,a))
        cout << "no" << endl;
    else
        cout << "unknown" << endl;
    //fclose(stdin);
    return 0;
}
