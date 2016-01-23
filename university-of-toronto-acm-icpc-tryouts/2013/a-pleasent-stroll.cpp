#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define db 0
#define lb(x) ((x)&(-x))
#define all(x) (x).begin(),(x).end()
#define needforspeed ios::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define xx first
#define yy second
#define LL long long
using namespace std;

int S,R,C;
int DP[50][50][50];// row, alice col, bob col
bool V[50][50][50];
char G[50][50];

bool adjacent(int r,int ca,int cb){
    return abs(ca-cb) == 1;
}
bool valid(int r,int ca,int cb){
     if(r < 0 || ca < 0 || cb < 0 || r >= R || ca >= C || cb >= C || ca == cb)
        return false;
     else if(G[r][ca] == '#' || G[r][cb] == '#')
        return false;
     else
        return true;
}

int main(){
    //freopen("input.txt","r",stdin);
    needforspeed;
    cin >> S;
    while(S--){
        cin >> R >> C;
        for(int r = 0;r < R;r++)
            for(int c = 0;c < C;c++)
                cin >> G[r][c];
        memset(DP,0,sizeof(DP));
        memset(V,false,sizeof(V));
        for(int ca = 0;ca < C;ca++)
            for(int cb = 0;cb < C;cb++)
                if(valid(0,ca,cb))V[0][ca][cb] = true;
        for(int r = 0;r < R;r++){
            for(int ca = 0;ca < C;ca++){
                for(int cb = 0;cb < C;cb++){
                    if(!V[r][ca][cb])
                        continue;

                    if(adjacent(r,ca,cb))
                       DP[r][ca][cb]++;

                    // down 3
                    if(valid(r+1,ca,cb)){
                       DP[r+1][ca][cb]   = max(DP[r+1][ca][cb],DP[r][ca][cb]);
                       V[r+1][ca][cb] = true;
                    }
                    if(valid(r+1,ca,cb+1)){
                       DP[r+1][ca][cb+1] = max(DP[r+1][ca][cb+1],DP[r][ca][cb]);
                       V[r+1][ca][cb+1] = true;
                    }
                    if(valid(r+1,ca,cb-1)){
                       DP[r+1][ca][cb-1] = max(DP[r+1][ca][cb-1],DP[r][ca][cb]);
                       V[r+1][ca][cb-1] = true;
                    }

                    // right down 3
                    if(valid(r+1,ca+1,cb)){
                       DP[r+1][ca+1][cb]   = max(DP[r+1][ca+1][cb],DP[r][ca][cb]);
                       V[r+1][ca+1][cb] = true;
                    }
                    if(valid(r+1,ca+1,cb+1)){
                       DP[r+1][ca+1][cb+1]   = max(DP[r+1][ca+1][cb+1],DP[r][ca][cb]);
                       V[r+1][ca+1][cb+1] = true;
                    }
                    if(valid(r+1,ca+1,cb-1)){
                       DP[r+1][ca+1][cb-1]   = max(DP[r+1][ca+1][cb-1],DP[r][ca][cb]);
                       V[r+1][ca+1][cb-1] = true;
                    }

                    // left down 3
                    if(valid(r+1,ca-1,cb)){
                       DP[r+1][ca-1][cb]   = max(DP[r+1][ca-1][cb],DP[r][ca][cb]);
                       V[r+1][ca-1][cb] = true;
                    }
                    if(valid(r+1,ca-1,cb+1)){
                       DP[r+1][ca-1][cb+1]   = max(DP[r+1][ca-1][cb+1],DP[r][ca][cb]);
                       V[r+1][ca-1][cb+1] = true;
                    }
                    if(valid(r+1,ca-1,cb-1)){
                       DP[r+1][ca-1][cb-1]   = max(DP[r+1][ca-1][cb-1],DP[r][ca][cb]);
                       V[r+1][ca-1][cb-1] = true;
                    }
                }

            }
        }
        int ans = -1;
        for(int ca = 0;ca < C;ca++)
            for(int cb = 0;cb < C;cb++)
                if(V[R-1][ca][cb])ans = max(ans,DP[R-1][ca][cb]);
        if(ans == -1)
           cout << "Detour" << endl;
        else
           cout << ans << endl;
    }

    return 0;
}

