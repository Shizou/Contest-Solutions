#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define db 0
#define all(x) (x). begin(),(x).end()
#define x first
#define y second
using namespace std;

const int MAXN = (int)1e6;
int N,M,S,E;
int arr[MAXN];
vector<int> adj[MAXN];

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d%d%d%d",&N,&M,&S,&E);
    for(int i =0;i < N;i++)
        scanf("%d",&arr[i]);
    for(int i = 0,a,b;i < M;i++){
        scanf("%d%d",&a,&b);
        adj[a].pb(b);
    }

    return 0;
}