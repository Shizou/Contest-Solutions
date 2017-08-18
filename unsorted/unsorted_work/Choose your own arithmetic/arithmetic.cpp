#include<iostream>
#include<fstream>
#include<set>
#include<queue>
#include<vector>
using namespace std;

int maxDep,wD,t,v;
vector<int>wDig;
vector<bool> visited(5000000);
int main(){
    freopen("CYOA.4.in","r",stdin);
    cin >> maxDep >> wD;
    for(int i = 0;i < wD;i++){
        cin >> t;
        wDig.push_back(t);
    }
    cin >> v;
    while(v--){
        cin >> t;
        bool pos = 0;
        queue< pair<int,int> > q;
        for(int i = 0;i < wD;i++)   q.push( make_pair(wDig[i],0) );

        while(!q.empty()){
            int val = q.front().first;
            int dep = q.front().second;
            q.pop();
            if( (dep == maxDep && val != t) || val > t){
                continue;
            }
            if(dep == maxDep && val == t){
                cout << "Y" << endl;
                pos = true;
                break;
            }
            if(visited[val])continue;
            for(int i = 0;i < wD;i++){
                if(!visited[val * wDig[i]])q.push( make_pair(val * wDig[i],dep+1) );
                //visited[val * wDig[i]] = 1;
                if(!visited[val + wDig[i]])q.push( make_pair(val + wDig[i],dep+1) );
                //visited[val + wDig[i]] = 1;
            }
        }
        if(!pos) cout << "N" << endl;
    }

    return 0;
    fclose(stdin);
}
