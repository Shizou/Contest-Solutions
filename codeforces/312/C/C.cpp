#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define db 0
#define nullptr 0
#define lb(x) ((x)&(-x))
#define all(x) (x).begin(),(x).end()
#define needforspeed ios::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define x first
#define y second
#define LL long long
using namespace std;

const LL MAXN = 100000,inf = (LL)1e10;
LL N,LCM;
LL arr[MAXN];
map<LL, pair<LL,LL> >dp;

int main(){
    freopen("C-input.txt","r",stdin);
    needforspeed;
    cin >> N;
    for(int i = 0;i < N;i++){
        cin >> arr[i];
        queue< pair<int,int> >q;
        q.push(mp(i,0));
        while(!q.empty()){
            pair<int,int>p = q.front();
            q.pop();
            if(!dp.count(p.x))dp[p.x].x = inf;
            dp[p.x].x = min(dp[p.x].x,p.y);

            if(p.x > 100000 || p.x == 0)continue;
            q.push(mp( p.x*2 ,p.y+1);
            q.push(mp( p.x/2 ,p.y+1);
        }
    }

    LL ans = inf;
    for( map<LL, pair<LL,LL> >::iterator it = dp.begin();it!=dp.end();it++){
        pair<LL,LL> p= it->second;
        if(p.y == N)
            ans = min(ans,p.x);
    }
    cout << ans << endl;
    return 0;
}

