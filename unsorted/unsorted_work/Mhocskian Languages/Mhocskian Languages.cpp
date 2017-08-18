#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define LL long long
#define db 0
using namespace std;

int V,T,R,W,MAXL;
vector<string>var,ter,out;
vector< pair<string,pair<string,string> > >rules;
set<string>words;
string a,b,c;


int search(string s){
   for(int i = 0;i < (int)rules.size();++i)
       if(rules[i].first == s)return i;
  return -1;
}
void rec(string s){
    //cout << s << endl;
    for(int i = 0;i < (int)s.size();++i){
        if(isupper(s[i])){
           string ss;ss+=s[i];
           int pos = search(ss);
           if(pos != -1){
              string t;
              for(int j = pos;j < (int)rules.size() && ss == rules[j].first;++j){
                  if(i!=0)
                    t = s.substr(0,i) + rules[j].second.first + rules[j].second.second + s.substr(i+1,s.size()-i);
                  else
                    t = rules[j].second.first + rules[j].second.second + s.substr(1,s.size()-1);
                  if(!words.count(t) && (int)t.size() <= MAXL){
                      words.insert(t);
                      rec(t);
                  }
              }
           }
        }
    }
}

int main(){
  freopen("input.txt","r",stdin);
  cin >> V >> T;
  for(int i = 0;i < V;++i){
    cin >> a;
    var.pb(a);
  }
  for(int i = 0;i < T;++i){
    cin >> a;
    ter.pb(a);
  }
  cin >> R;
  for(int i = 0;i < R;++i){
    cin >> a >> b;
    rules.pb(mp(a,mp(b,"")));
  }
  cin >> R;
  for(int i = 0;i < R;++i){
    cin >> a >> b >> c;
    rules.pb(mp(a,mp(b,c)));
  }
  cin >> W;
  for(int i = 0;i < W;++i){
      cin >> a;
      out.pb(a);
      MAXL = max(MAXL,(int)a.size());
  }
  sort(rules.begin(),rules.end());
  words.insert(var[0]);
  rec(var[0]);
  for(int i = 0;i < (int)out.size();++i){
     if(words.count(out[i]))cout << 1 << endl;
     else                   cout << 0 << endl;
  }
  return 0;
}