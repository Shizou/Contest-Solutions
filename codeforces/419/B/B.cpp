#include<bits/stdc++.h>
#define needforspeed ios::sync_with_stdio(0);cin.tie(0);
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define endl '\n'
#define pb push_back
#define mp make_pair
#define mp3(a,b,c) make_pair(a,make_pair(b,c))
#define mp4(a,b,c,d) make_pair(make_pair(a,b),make_pair(c,d))
#define trace1(a) cout << (a) << endl;
#define trace2(a,b) cout << (a)  << " " << (b) << endl;
#define trace3(a,b,c) cout << (a)  << " " << (b) << " " << (c) << endl;
#define trace4(a,b,c,d) cout << (a)  << " " << (b) << " " << (c) <<  " " << (d) << endl;
#define trace5(a,b,c,d,e) cout << (a)  << " " << (b) << " " << (c) <<  " " << (d) <<  " " << (e) << endl;
#define ms(a,b) memset( (a), (b), sizeof(a))
#define fi(x) freopen(x,"r",stdin)
#define fo(x) freopen(x,"w",stdout)
#define wi(x) for(int  (i) = (0); (i) < (x);(i)++)
#define wj(x) for(int  (j) = (0); (j) < (x);(j)++)
#define wk(x) for(int  (k) = (0); (k) < (x);(k)++)
#define all(x) (x).begin(),(x).end()
#define len(x) (int)(x).size()
#define xx first
#define yy second
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define MAXN (int)1e9
#define inf 0x3f3f3f3f
#define nullptr 0
#define db 0
using namespace std;

int N,K,Q;
vector< pair<int,int> >ranges;

int main() {
  needforspeed;
  cin >> N >> K >> Q;
  for(int i = 0;i < N;i++){
      int a,b;
      cin >> a >> b;
      ranges.pb(mp(a, 1));
      ranges.pb(mp(b+1, -1));
  }
  sort(all(ranges));
  vector< pair<int,int> >P;
  int cnt = 0;
  for(int i = 0;i < len(ranges);i++){
      if(ranges[i].second == 1)
          cnt++;
      else
          cnt--;
      P.pb(mp(ranges[i].first, cnt));
  }
  int A[200005] = {0};
  ms(A,0);
  cnt = 0;
  for(int i = 0, it = 0;i < 200005;i++){
      if(P[it].first == i){
          while(P[it].first == i){
              cnt = P[it].second;
              it++;
          }
      }
      A[i] = (cnt >= K) ? 1:0;
  }
  for(int i = 1;i < 200005;i++){
      A[i] = A[i] + A[i-1];
  }
  //cout << endl;

  for(int i = 0;i < Q;i++){
      int a,b;
      cin >> a >> b;
      //trace2(A[b], A[a-1]);
      cout << A[b]-A[a-1] << endl;
  }
  return 0;
}
