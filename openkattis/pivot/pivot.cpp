#include<bits/stdc++.h>
#define DB 0
#define needforspeed ios::sync_with_stdio(false);
#define endl '\n'
#define len(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define ms(a,b) memset( (a),(b),sizeof( (a) ) )
#define pb push_back
#define mp make_pair
#define LL long long
#define MOD 1000000007
#define MAXN (int)1e5+5
#define inf 10000000000
using namespace std;


int N,qlo,qhi,ans;
LL arr[MAXN];
LL mintree[4*MAXN],maxtree[4*MAXN];


void build(int n,int lo,int hi){
    if(lo == hi){
       mintree[n] = arr[lo];
       maxtree[n] = arr[lo];
    }
    else{
       build(2*n+1,lo,(lo+hi)/2);
       build(2*n+2,(lo+hi)/2+1,hi);
       mintree[n] = min(mintree[2*n+1],mintree[2*n+2]);
       maxtree[n] = max(maxtree[2*n+1],maxtree[2*n+2]);
    }
}

LL minquery(int n,int lo,int hi){
   if(lo > qhi || hi < qlo || lo > hi)
      return inf;
   else if(lo >= qlo && hi <= qhi)
      return mintree[n];
   else
      return min( minquery(2*n+1,lo,(lo+hi)/2),
                   minquery(2*n+2,(lo+hi)/2+1,hi) );
}

LL maxquery(int n,int lo,int hi){
   if(lo > qhi || hi < qlo || lo > hi)
      return -inf;
   else if(lo >= qlo && hi <= qhi)
      return maxtree[n];
   else
      return max( maxquery(2*n+1,lo,(lo+hi)/2),
                   maxquery(2*n+2,(lo+hi)/2+1,hi) );
}

int main(){
     #ifdef DBa
     freopen("input.txt","r",stdin);
     #endif
     needforspeed;
     cin >> N;
     for(int i = 0;i < N;i++){
          cin >> arr[i];
     }
     build(0,0,N-1);
     for(int i = 0;i < N;i++){
         if(i == 0){
            qlo = 1,qhi = N-1;
            LL right = minquery(0,0,N-1);
            if(arr[i] <= right)
               ans++;
         }
         else if(i == N-1){
            qlo = 0,qhi = N-2;
            LL left = maxquery(0,0,N-1);
            if(arr[i] >= left)
               ans++;
         }
         else{
             qlo = 0,qhi = i-1;
             LL left = maxquery(0,0,N-1);
             qlo = i+1,qhi = N-1;
             LL right = minquery(0,0,N-1);
             if(arr[i] >= left && arr[i] <= right){
                ans++;
            //cout << i+1 << ":" << arr[i] << " " << left << " " << right << endl;
             }
         }
     }
     cout << ans << endl;
     return 0;
}