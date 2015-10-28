#include<bits/stdc++.h>
#define endl '\n'
#define needforspeed ios_base::sync_with_stdio (false);cin.tie();
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define len(x) (int)(x).size()
#define ms(a,b) memset( (a), (b), sizeof( (a) ) )
#define xx first
#define yy second
#define LL long long
#define DB 0
#define MAXN (int)2000
#define inf 0x3f3f3f3f
using namespace std;

LL N,C;
map<LL,LL>depth;

int main(){
    #ifdef DBa
    freopen("input.txt","r",stdin);
    #endif
    needforspeed;
    cin >> N;
    for(int i = 0,n = 0;i < N;++i){
        cin >> n;
        auto it = depth.upper_bound(n);
        LL d = 0;
        if(it != depth.end())  d = max(d,it->second+1);
        if(it != depth.begin())d = max(d, (--it)->second+1);
        depth[n] = d;
        C += d;
        cout << C << endl;
    }
    return 0;
}