#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define db 1
#define lb(x) ((x)&(-x))
#define all(x) (x).begin(),(x).end()
#define needforspeed ios::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define x first
#define y second
#define LL long long
using namespace std;

const int MAXN = 500000;
int N,M;
int atm[MAXN];
vector<int>adj[MAXN];

int main(){
    freopen("input.txt","r",stdin);
    needforspeed;
    cin >> N >> M;
    for(int i = 0,a,b;i < M;i++){
        cin >> a >> b;
        adj[a].pb(b);
    }
    for(int i = 0;i < N;i++){
        cin >> atm[i];
    }
    return 0;
}