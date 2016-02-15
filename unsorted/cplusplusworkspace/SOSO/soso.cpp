#include<iostream>
#include<cstdio>
#include<set>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;


struct state{
    vector<string>g;
    state(vector<string>_g){
        g = _g;
    }

    string to_s(){
      string ret;
      for(int i = 0;i < (int)s.size();i++)
        ret+=s[i];
      return ret;
    }
    bool operator < (state&rhs){
        this->to_s() < rhs.to_s();
    }
};

int T = 10,R,C;
string in;

bool valid(int r1,int c1,int r2,int c2,state s){
  if(r2<0 ||c2 < 0 || r2 == R ||c2 == C)return false;
  if(s.g[r1][c1] == s.g[r2][c2])        return false;

  return true;
}

int main(){
    freopen("input.txt","r",stdin);
    while(T--){
        cin >> R >> C;
        set<string>used;
        vector<string>grid;
        for(int t = 0;t < 4;t++){
          for(int i = 0; i < R;i++){
            cin >> in;
            grid.push_back(in);
          }
          queue<state>q;
          q.push((state){grid});
          while(!q.empty()){
              state current = q.front();
              q.pop();
              for(int r = 0;r < R;r++){
                  for(int c = 0;c < C;c++){
                      if(valid(r,c,r-1,c,current));
                      if(valid(r,c,r+1,c,current));
                      if(valid(r,c,r,c-1,current));
                      if(valid(r,c,r,c+1,current));
                  }
              }
          }
        }
    }
    return 0;
}