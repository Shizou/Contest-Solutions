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

int n, a;

int main() {
    needforspeed;
    cin >> n >> a;
    double interior = (n-2)*180/(double)n;
    double ind_ang = interior/(n-3+1); 
    double best = abs(interior-a);
    pair<int, pair<int,int> >vert = mp(2, mp(1, n));
    for(int i = 1;i <= n-3+1;i++){
        double cur_ang = i*ind_ang;
        if(abs(cur_ang-a) < best){
            best = abs(cur_ang-a);
            vert = mp(2,mp(1, i+2));
        }
    }
    trace3(vert.first, vert.second.first, vert.second.second);
    return 0;
}
