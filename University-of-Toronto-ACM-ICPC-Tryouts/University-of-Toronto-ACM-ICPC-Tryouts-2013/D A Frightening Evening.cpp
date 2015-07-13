#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define db 0
#define lb(x) ((x)&(-x))
#define all(x) (x).begin(),(x).end()
#define needforspeed ios::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define t first
#define f second
#define LL long long
using namespace std;

int N,D,M,H,L;

int main(){
    //freopen("input.txt","r",stdin);
    needforspeed;
    cin >> N;
    while(N--){
        cin >> D >> M >> H >> L;
        vector< pair<int,int> >m;
        for(int i = 0,a,b;i < M;i++){
            cin >> a >> b;
            m.pb(mp(a,b));
        }
        int ans = D+1;
        for(int i = 0;i <= M;i++){
            int fear = 0, hold = 0;
            for(int j = 0;j < M;j++){
                if(i == j)        continue;
                else if(fear >= L)break;
                else if(fear >= H){
                    if(j-1 == i)// last one was skipped
                       hold += m[j].t - m[j-2].t;
                    else
                       hold += m[j].t - m[j-1].t;
                }
                fear += m[j].f;
                fear = max(fear,0);
            }
            if(fear >= H && fear < L){
                if(i == M-1)// last one was skipped
                   hold += D-m[M-2].t;
                else
                   hold += D-m[M-1].t;
            }
            ans = min(ans,hold);
        }
        if(ans == D+1)
           cout << 0 << endl;
        else
           cout << ans << endl;
    }

    return 0;
}

