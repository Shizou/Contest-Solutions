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

LL N,ans;

int highest_power(int x){
   return (int)log10(x);
}
int pow(int x,int r){
   int i = x;
   while(--r)i*=x;
   return i;
}


int main(){
    freopen("B-input.txt","r",stdin);
    needforspeed;
    cin >> N;
    while(N != 0){
       //cout << N << endl;
       if(highest_power(N) == 9){
            ans += (N-999999999)*(highest_power(N)+1);
            N = 999999999;
       }
       else if(highest_power(N) == 8){
            ans += (N-99999999)*(highest_power(N)+1);
            N = 99999999;
       }
       else if(highest_power(N) == 7){
            ans += (N-9999999)*(highest_power(N)+1);
            N = 9999999;
       }
       else if(highest_power(N) == 6){
            ans += (N-999999)*(highest_power(N)+1);
            N = 999999;
       }
       else if(highest_power(N) == 5){
            ans += (N-99999)*(highest_power(N)+1);
            N = 99999;
       }
       else if(highest_power(N) == 4){
            ans += (N-9999)*(highest_power(N)+1);
            N = 9999;
       }
       else if(highest_power(N) == 3){
            ans += (N-999)*(highest_power(N)+1);
            N = 999;
       }
       else if(highest_power(N) == 2){
            ans += (N-99)*(highest_power(N)+1);
            N = 99;
       }
       else if(highest_power(N) == 1){
            ans += (N-9)*(highest_power(N)+1);
            N = 9;
       }
       else if(highest_power(N) == 0){
         ans+=N;
         N = 0;
       }
    }
    cout << ans << endl;
    return 0;
}