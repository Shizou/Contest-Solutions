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

int N;
int arr[51];

bool valid(int a, int b, int c)
{
    if(db)trace3(a,b,c);
    if(a == b || b == c || a == c)
        return false;
    if(abs(a-b) > 2 || abs(b-c) > 2 || abs(a-c) > 2)
        return false;
    return true;
}

int main()
{
  //fi("A-input.txt");
  needforspeed;
  cin >> N;
  for(int i = 0;i < N;i++)
  {
    cin >> arr[i];
    if(db)trace1(arr[i]);
  }
  bool pos = false;
  for(int i = 0;i < N;i++)
  {
      for(int j = i+1;j < N;j++)
      {
            for(int k = j+1;k < N;k++)
            {
                if(valid(arr[i], arr[j], arr[k]))
                    pos = true;
            }
      }
  }
  if(pos)
     cout << "YES" << endl;
  else
     cout << "NO" << endl;
  return 0;
}