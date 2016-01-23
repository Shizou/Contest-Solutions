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

int N,a,b;
string S;

int main(){
    //freopen("A-input.txt","r",stdin);
    needforspeed;
    cin >> N;
    for(int i = 0;i < N;i++){
        char c;cin >> c;
        S+=c;
        if(S.size() >= 2)
           if ( (S[S.size()-1] == '0' && S[S.size()-2] == '1') || (S[S.size()-1] == '1' && S[S.size()-2] == '0') )
               S.erase(S.size()-2,2);
    }
    int idx  = 0;
    while(true){
          idx = S.find("01");
          if(idx > 0)
             S.erase(idx,2);
          else{
             idx = S.find("10");
             if(idx > 0)
                S.erase(idx,2);
             else
              break;
          }
    }
    cout << S.size() << endl;
    return 0;
}