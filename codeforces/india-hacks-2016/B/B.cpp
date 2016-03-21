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

int N,Q;
map<string,string>opr;

bool solve(string s)
{
    set<string>v;
    queue<string>q;
    q.push(s);
    while(!q.empty())
    {
        string str = q.front();
        q.pop();
        if(db)cout << str << endl;
        for(map<string,string>::iterator it = opr.begin(); it != opr.end();it++)
        {
            pair<string,string>cur = *it;
            if(db)cout << str.substr(0,2) << " "<< cur.xx<< endl;
            if(len(str) >= 2 && str.substr(0,2) == cur.xx)
            {
                string nxt = cur.yy+str.substr(2,len(str)-2);
                if(!v.count(nxt))
                {
                    q.push(nxt);
                    v.insert(nxt);
                }
            }

        }
    }
    return v.count("a");
}

void generate(int n, string cur, set<string>&comb)
{
    if(n == 0)
    {
        comb.insert(cur);
        return;
    }
    else
    {
        string ch[] = {"a","b","c","d","e","f"};
        for(int i = 0;i < 6;i++)
        {
            string nxt = cur + ch[i];
            generate(n-1, nxt, comb);
        }
    }
}

int main() {
  //fi("B-input.txt");
  needforspeed;
  cin >> N >> Q;
  for(int i = 0;i < Q;i++)
  {
      string s,t;
      cin >> s >> t;
      opr[s] = t;
  }
  set<string>c;
  generate(N, "", c);
  int pos = 0;
  for(set<string>::iterator it = c.begin();it != c.end();it++)
  {
      string cur = *it;
      //if(db)cout << cur << endl;
      if(solve(cur))
      {
         pos++;
         //cout << "OK:" << cur << endl;
      }
  }
  cout << pos << endl;
  return 0;
}