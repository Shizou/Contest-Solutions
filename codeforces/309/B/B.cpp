#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define db 1
#define lb(x) ((x)&(-x))
#define all(x) (x).begin(),(x).end()
#define needforspeed ios::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define x first
#define y second
#define LL long long
using namespace std;

int N,ans = 0;
string g[200][2];
string gg[200];

string flip(string ss){
    string ret = ss;
    for(int i = 0;i < N;i++){
        ret[i] =  (ret[i] == '1') ? '0':'1';
    }
    return ret;
}


vector<string>cur;
bool OK(){
  int fine = N;
  for(int i = 0;i < N;i++){
      for(int j = 0;j < (int)cur.size();j++){
          if(cur[j][i] == '1'){
            fine--;
            break;
          }
      }
  }
  return fine > 0;
}

int check(){
   int ret = 0;
   for(int i = 0;i < N;i++){
       for(int j = 0;j < (int)cur.size();j++){
           if(cur[j][i] == '1')break;
           if(j == (int)cur.size()-1)ret++;
       }
   }
   return ret;
}

void print(){
  for(int i = 0;i < (int)cur.size();i++)cout << cur[i] << endl;
    cout << endl;
}
void rec(int i){
    // reached end
    if(i == N){
      ans = max(ans,check());
      return;
    }
    // try one
    cur.pb(g[i][0]);
    if(!OK())
      cur.pop_back();
    else
      rec(i+1);
    // try two
    cur.pb(g[i][1]);
    if(!OK())
      cur.pop_back();
    else
      rec(i+1);
}
int main(){
    freopen("B-input.txt","r",stdin);
    cin >> N;
    for(int i = 0;i < N;i++){
        cin >> gg[i];
    }
    for(int i = 0;i < N;i++){
      string ss = "";
      for(int j = 0;j < N;j++){
          ss += gg[j][i];
      }
      g[i][0] = ss;
      g[i][1] = flip(ss);
    }
    rec(0);
    cout << ans << endl;
    return 0;
}