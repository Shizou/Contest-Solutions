#include <algorithm>
#include <iostream>
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
#define all(x) (x).begin(),(x).end()
#define len(x) (int)(x).size()
#define xx first
#define yy second
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define MAXN (int)1e9
#define inf 0x3f3f3f3f
#define db 0
using namespace std;

int n,m;
int a[1005];
string s,t;

int main() {
    needforspeed;
    cin >> n >> m;
    cin >> s >> t;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(s[i] == t[j]){
                if(j >= 1 && a[j-1] == i){
                    a[j] = i+1;
                }

            }
        }
    }
    int ans = n;
    vector<int> ans_loc;
    for(int i = 0;i < n;i++)ans_loc.pb(i);

    for(int i = 0;i < m;i++)cout << a[i] << " " ;
    cout << endl;

    for(int i = 0;i < m;i++){
        if(a[i] > 0 && i+(n-a[i]) < m && i-(a[i]-1) >= 0){
            int cnt = 0;
            vector<int>cur;

            for(int j = i+1, it = a[i]; it < n && j < m;j++, it++){
                if(t[j] != s[it]){
                    cnt++;
                    cur.pb(it);
                }
            }
            for(int j = i-1, it = a[i]-2;it >= 0 && j >= 0;j--, it--){
                if(t[j] != s[it]){
                    cnt++;
                    cur.pb(it);
                }
            }
            if(cnt < ans){
                ans = cnt;
                ans_loc = cur;
            }
        }
    }
    cout << ans << endl;
    for(int i = 0;i < ans;i++){
        cout << ans_loc[i]+1 << " " ;
    }
    return 0;
}
