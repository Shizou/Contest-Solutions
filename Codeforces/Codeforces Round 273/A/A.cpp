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
#define sz(x) (int)(x).size()
using namespace std;

const int MAXN = 10000,inf = 0x3f3f3f3f;
int N,M,ans,cnt;
vector<int>arr;


void print(){
    for(int i = 0;i < (int)arr.size();i++){
        cout << arr[i] << " ";
    }cout << endl;
}
int main(){
    //freopen("A-input.txt","r",stdin);
    needforspeed;
    cin >> N >> M;
    for(int i = 0;i < N;i++)
        arr.pb(1);
    ans = inf;
    cnt = (int)arr.size();
    if( cnt%M == 0)
           ans = min(ans,cnt);
    while(!arr.empty()){
       if(arr.size() > 1){
          arr.pop_back();
          arr.pop_back();
          cnt--;
          if( cnt%M == 0)
           ans = min(ans,cnt);
       }else{
          break;
       }
    }
    cout << (ans == inf ? -1:ans) << endl;
    return 0;
}