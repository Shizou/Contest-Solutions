#include<bits/stdc++.h>
#define needforspeed ios_base::sync_with_stdio(false);
#define endl '\n'
#define DB
#define ms(a,b) memset((a),(b),sizeof( (a) ))
#define W 0
#define L 1
using namespace std;

int N,K;
int stats[105][2];

int main(){
    #ifdef DBa
    freopen("input.txt","r",stdin);
    #endif
    needforspeed;
    for(int t = 0;;t++){
       cin >> N;
       if(N == 0)break;
       if(t > 0) cout << endl;
       cin >> K;
       ms(stats,0);
       for(int i = 0;i < K*N*(N-1)/2;i++){
           int a,b;
           string as,bs;
           cin >> a >> as >> b >> bs;

           if(as == "rock" && bs == "scissors")
              stats[a][W]++, stats[b][L]++;
           if(as == "rock" && bs == "paper")
              stats[a][L]++, stats[b][W]++;
           if(as == "rock" && bs == "rock");
              // nothing happens

           if(as == "paper" && bs == "scissors")
              stats[a][L]++, stats[b][W]++;
           if(as == "paper" && bs == "paper");
              // nothing happens
           if(as == "paper" && bs == "rock")
              stats[a][W]++, stats[b][L]++;

           if(as == "scissors" && bs == "scissors");
              // nothing happens
           if(as == "scissors" && bs == "paper")
              stats[a][W]++, stats[b][L]++;
           if(as == "scissors" && bs == "rock")
              stats[a][L]++, stats[b][W]++;

       }
       for(int i = 1;i <= N;i++){
           if(stats[i][W]+stats[i][L] == 0)
              cout << "-" << endl;
           else{
              double ans = (double)stats[i][W]/(stats[i][W]+stats[i][L]);
              cout << setprecision(3) << fixed << ans << endl;
          }
       }
    }
    return 0;
}