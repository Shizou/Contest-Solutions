#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define db 0
using namespace std;

int V,T,R,W;
vector<string>var;
map<string,vector<string> >rules;
map<string,map<string,bool> >path;
string a,b,c;


bool possible(string word,string var){
     if(path[var].count(word))
        return path[var][word];
     else{
        for(int i = 1;i < (int)word.length();i++){
            string w1 = word.substr(0,i);
            string w2 = word.substr(i,-1);
            for(int j = 0;j < (int)rules[var].size();j++){
                string v1; v1 += rules[var][j][0];
                string v2; v2 += rules[var][j][1];
                if(possible(w1,v1) && possible(w2,v2)){
                   path[var][word] = true;
                   return true;
                }
            }
        }
         path[var][word] = false;
         return false;
     }
}

int main(){
  //freopen("Input/Mhocskian.1.in","r",stdin);
  cin >> V >> T;
  for(int i = 0;i < V;++i){
    cin >> a;
    if(i == 0)// we only care about the first element
       var.pb(a);
  }
  for(int i = 0;i < T;++i){
    cin >> a;
    // we don't care about these
  }
  cin >> R;
  for(int i = 0;i < R;++i){
    cin >> a >> b;
    path[a][b] = true;
  }
  cin >> R;
  for(int i = 0;i < R;++i){
    cin >> a >> b >> c;
    rules[a].pb(b+c);
  }
  cin >> W;
  for(int i = 0;i < W;++i){
      cin >> a;
      if(possible(a,var[0]))
         cout << 1 << endl;
      else
         cout << 0 << endl;
  }
  return 0;
}