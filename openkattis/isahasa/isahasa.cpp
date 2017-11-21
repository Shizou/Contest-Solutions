#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#define MAXN 1005
using namespace std;

int N, M, cid = 0;
bool adj[MAXN][MAXN];
map<int, set<string> >attr;
map<string, int>id;

void apply_id(string s){
    if(!id.count(s)){
        id[s] = cid++;
    }
}

int main(){
    cin >> N >> M;
    for(int i = 0;i < N;i++){
        string cur_class, rel, opt;
        cin >> cur_class >> rel >> opt;
        if(rel == "is-a"){ // opt is a class
            apply_id(cur_class);
            apply_id(opt); 
            adj[id[cur_class]][id[opt]] = true;
        } else if(rel == "has-a"){ // opt is an attribute 
            apply_id(cur_class);
            attr[id[cur_class]].insert(opt);
        }
    }
    // computing the transitive closure of the graph
    int nodes = cid;
    for(int i = 0;i < MAXN;i++)adj[i][i]=true;
    for(int k = 0;k < nodes;k++){
        for(int i = 0;i < nodes;i++){
            for(int j = 0;j < nodes;j++){
                adj[i][j] = adj[i][j] || (adj[i][k] && adj[k][j]);
                if(adj[i][j]){
                    attr[i].insert(attr[j].begin(), attr[j].end());
                }
            }
        }
    }
    for(int q = 1;q <= M;q++){
        string cur_class, rel, opt;
        cin >> cur_class >> rel >> opt;
        if(rel == "is-a"){ // determine if there's a relation 
            apply_id(cur_class);
            apply_id(opt);
            string qout = adj[id[cur_class]][id[opt]]  ? "true" : "false";
            cout << "Query " << q << ": "  << qout << endl;
        } else if(rel == "has-a"){ // determine if you have the lements 
            apply_id(cur_class);
            string qout;
            if(id.count(opt)){ // check if we contain instance of a class
                bool result = false;
                for(auto inst: attr[id[cur_class]]){
                   if(id.count(inst)){ // this instance is a class
                       result  |= adj[id[inst]][id[opt]];
                   }
                }
                qout = result ? "true":"false";
            }else{ // check for attributes
                qout = attr[id[cur_class]].count(opt) ? "true" : "false";
            }
            cout << "Query " << q << ": "  << qout << endl;
        }

    }
    return 0;
}
