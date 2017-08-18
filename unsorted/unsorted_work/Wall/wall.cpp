#include<bits/stdc++.H>
#define pb push_back
#define mp make_pair
#define db 1
#define lb(x) ((x)&(-x))
#define all(x) (x).begin(),(x).end()
#define needforspeed ios::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define x first
#define y second
#define ADD 1
#define REV 2
#define LL long long
using namespace std;

const int MAXN = 4*2*(int)1e6+1,inf = 0x3f3f3f3f;
int N,K;
int OP,L,R,H,T;
int tree[MAXN];
pair<int,int>up[MAXN],dn[MAXN];


void propagate(int n,int lo, int hi){
    if(up[n].x != 0 || up[n].y != 0){
        if(lo!=hi){
           // both operations needed
           if(up[n].x != 0 && dn[n].x != 0){
              // if adding operation occurs before removing operation
              if(up[n].x < dn[n].x){
                 // do UP
                 tree[n] = max(tree[n],up[n].y);
                 up[2*n+1].x = up[n].x, up[2*n+1].y = up[n].y;
                 up[2*n+2].x = up[n].x, up[2*n+2].y = up[n].y;
                 up[n].x = up[n].y = 0;
                 // do DN
                 tree[n] = min(tree[n],dn[n].y);
                 dn[2*n+1].x = dn[n].x, dn[2*n+1].y = dn[n].y;
                 dn[2*n+2].x = dn[n].x, dn[2*n+2].y = dn[n].y;
                 dn[n].x = dn[n].y = 0;
              }else{
                // do DN
                 tree[n] = min(tree[n],dn[n].y);
                 dn[2*n+1].x = dn[n].x, dn[2*n+1].y = dn[n].y;
                 dn[2*n+2].x = dn[n].x, dn[2*n+2].y = dn[n].y;
                 dn[n].x = dn[n].y = 0;
                 // do UP
                 tree[n] = max(tree[n],up[n].y);
                 up[2*n+1].x = up[n].x, up[2*n+1].y = up[n].y;
                 up[2*n+2].x = up[n].x, up[2*n+2].y = up[n].y;
                 up[n].x = up[n].y = 0;
              }
           }else{
              // only one operation is needed
              if(up[n].x != 0){
                 tree[n] = max(tree[n],up[n].y);
                 up[2*n+1].x = up[n].x, up[2*n+1].y = up[n].y;
                 up[2*n+2].x = up[n].x, up[2*n+2].y = up[n].y;
                 up[n].x = up[n].y = 0;
              }else{
                 tree[n] = min(tree[n],dn[n].y);
                 dn[2*n+1].x = dn[n].x, dn[2*n+1].y = dn[n].y;
                 dn[2*n+2].x = dn[n].x, dn[2*n+2].y = dn[n].y;
                 dn[n].x = dn[n].y = 0;
              }
           }
        }
        up[n].x = up[n].y = 0;
        dn[n].x = dn[n].y = 0;
    }
}

void update(int n,int lo,int hi){
   propagate(n,lo,hi);
   if(lo > R || hi < L || lo > hi)
      return;
   else{
        if(lo >= L && hi <= R){
           if(OP == ADD){
              tree[n] = max(tree[n],H);
              if(lo!=hi)
                 up[2*n+1].x = T,up[2*n+2].y = H;
           }
           else{
              tree[n] = min(tree[n],H);
              if(lo!=hi)
                 dn[2*n+1].x = T,dn[2*n+2].y = H;
           }
        }else{
           update(2*n+1,lo,(lo+hi)/2);
           update(2*n+2,(lo+hi)/2+1,hi);
           tree[n] = max(tree[2*n+1],tree[2*n+2]);
        }
   }
}

int query(int n,int lo, int hi){
    propagate(n,lo,hi);
    cout  << n << " " << lo << " " << hi << endl;
    if(lo > R || hi < L)
       return 0;
    else{
       if(lo >= L && hi <= R)
          return tree[n];
       else
          return max( query(2*n+1,lo,(lo+hi)/2), query(2*n+2,(lo+hi)/2+1,hi) );
    }
}
int main(){
    freopen("input.txt","r",stdin);
    needforspeed;
    memset(tree,0,sizeof(tree));
    cin >> N >> K;
    for(int i = 1;i <= K;i++){
        cin >> OP >> L >> R >> H;
        T = i;
        update(0,0,N);
       // print();
    }
    for(int i = 0;i <= K;i++){
        L = R = i;
        cout << query(0,0,N) << endl;
    }
    return 0;
}