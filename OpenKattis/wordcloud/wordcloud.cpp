#include<bits/stdc++.h>
#define endl '\n'
#define needforspeed ios_base::sync_with_stdio (false);
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


int W,N;
int OM = 5;
vector< pair<string,int> >v;


int main(){
    #ifdef DBa
    freopen("input.txt","r",stdin);
    #endif
    needforspeed;
    for(int t = 1;cin >> W >> N && !(W == 0 && N == 0);t++){
          v.clear();
          OM = 5;
          for(int i = 0;i < N;i++){
              string s;
              int c;
              cin >> s >> c;
              v.pb(mp(s,c));
              OM = max(OM,c);
          }
          int CW = 0,CH = 0,TH = 0;
          for(int i = 0;i < N;i++){
              int  P   = 8 + ceil(  abs( (double)40*(v[i].yy-4) / abs((double)(OM-4)) ));
              int  WW  = ceil(len(v[i].xx)*P*9.0/16.0);
              if(CW + WW <= W){
                 CW += WW + 10;
                 CH = max(CH,P);
              }
              else{
                 if(DB)cout << TH+CH << " " << W-CW << " " << v[i].xx << endl;
                 TH += CH;
                 CW = 0;
                 CH = 0;
                 if(CW + WW <= W){
                    CW += WW + 10;
                    CH = max(CH,P);
                 }
              }
              if(i == N-1 && CH > 0)
                 TH += CH;
          }
          // OUTPUT
          int ans = TH;
          cout << "CLOUD " << t << ": " << ans << endl;
    }


    return 0;
}

