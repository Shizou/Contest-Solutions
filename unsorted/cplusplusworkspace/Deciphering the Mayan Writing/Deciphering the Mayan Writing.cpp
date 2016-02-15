#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define db 1
#define lb(x) ((x)&(-x))
#define all(x) (x).begin(),(x).end()
#define needforspeed ios::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define pb push_back
#define mp make_pair
#define LL long long
using namespace std;

int W,S,cnt;
string A,B;
int a[60],b[60];

int F(char c){
  return isupper(c) ? (c-'A')+26:(c-'a');
}

int main(){
  //freopen("input.txt","r",stdin);
  needforspeed;
  cin >> W >> S;
  cin >> A >> B;
  W--,S--;
  for(int i = 0;i <= W;i++)
     a[F(A[i])]++;
  for(int i = 0;i <= S;i++){
    if(i < W)
      b[F(B[i])]++;
    else if(i == W){
      b[F(B[i])]++;
      bool OK = true;
      for(int j = 0;j < 60;j++){
          if(a[j]!=b[j]){
            OK = false;
            break;
          }
      }
      if(OK)cnt++;
    }
    else{
      b[F(B[i])]++;
      b[F(B[i-(int)A.size()])]--;
      bool OK = true;
      for(int j = 0;j < 60;j++){
          if(a[j]!=b[j]){
            OK = false;
            break;
          }
      }
      if(OK)cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}

