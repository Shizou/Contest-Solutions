#include <algorithm>
#include <iostream>
#include <stack>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <climits>
#include <numeric>

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
#define MAXN (long long)1e9
#define inf 2*(long long)1e9
#define db 0
using namespace std;

int n, x;

map<int, vector< pair< pair<int,int> , pair<int,int> > > >m;

int main() {
    needforspeed;
    cin >> n >> x;
    vector< pair< pair<int,int> , pair<int,int> > >tk;
    for(int i = 0;i < n;i++){
        int l,r,c,x;
        cin >> l >> r >> c;
        x = (r-l)+1;
        m[x].pb(mp(mp(l,r), mp(c, i)));
        tk.pb(mp(mp(r,l), mp(c,i)));
    }
    sort(all(tk));
    for(auto it: m){
        sort(all(it.second));
    }
    long long ans = inf;
    for(int i = 0;i < n;i++){
        int r = tk[i].xx.xx, l = tk[i].xx.yy;
        int comp =  x-((r-l)+1);
        if(comp > 0){
            vector< pair< pair<int,int> , pair<int,int> > >v = m[comp];
            int it = upper_bound(all(v),mp(mp(tk[i].xx.xx, -1), mp(-1,-1))) - v.begin();
            for(int j = it;j < len(v);j++){
                if(tk[i].yy.yy != v[j].yy.yy){
                    if(ans > tk[i].yy.xx + v[j].yy.xx){
                        ans = tk[i].yy.xx + v[j].yy.xx;
                    }
                }
            }
        }
    }
    if(ans != inf){
        cout << ans << endl;
    }else{
        cout << -1 << endl;
    }
    return 0;

}
