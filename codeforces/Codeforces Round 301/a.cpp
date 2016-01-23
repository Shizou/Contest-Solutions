#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define db 0
#define all(x) x.begin(),x.end()
using namespace std;

const int MAXN = (int)1e5,inf = 0x3f3f3f3f;
int N,ans;
string s1,s2;

int dist(int a,int b){
  return min(abs(a-b), min(a,b)+10-max(a,b));
}

int main(){
    //freopen("input.txt","r",stdin);
    cin >> N;
    cin >> s1 >> s2;
    for(int i = 0,a,b;i < N;i++){
      a = s1[i]-'0', b = s2[i]-'0';
      ans += dist(a,b);
      //cout << dist(a,b) << endl;
    }
    cout << ans << endl;
    return 0;
}