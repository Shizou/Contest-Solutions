#include<bits/stdc++.h>
#define endl '\n'
#define needforspeed ios_base::sync_with_stdio (false);
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define len(x) (int)(x).size()
#define ms(a,b) memset( (a), (b), sizeof( (a) ) )
#define xx first
#define yy second
#define LL long long
#define DB 1
#define MAXN (int)1e6
#define inf 0x3f3f3f3f
using namespace std;

int N;
string s;

int main(){
    #ifdef DBa
    freopen("input.txt","r",stdin);
    #endif
    needforspeed;
    while(cin >> N && N != 0){
          cin >> s;
          reverse(all(s));
          while(N--)
          for(int i = 0;i < len(s);i++){
              if(isupper(s[i]) || s[i] == '_' || s[i] == '.'){
                 if(isupper(s[i]) && s[i] < 'Z')
                    s[i]++;
                  else if(s[i] == 'Z')
                     s[i] = '_';
                  else if(s[i] == '_')
                     s[i] = '.';
                  else if(s[i] == '.')
                     s[i] = 'A';

              }
          }
          cout << s << endl;
    }
    return 0;
}