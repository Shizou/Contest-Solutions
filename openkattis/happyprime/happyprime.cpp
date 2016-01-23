#include<bits/stdc++.h>
#define endl '\n'
#define needforspeed ios_base::sync_with_stdio (false);cin.tie();
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

int P;

bool checkem(int n){
    if(n < 2)return false;
    if(n == 2)return true;
    if(n%2 == 0)return false;
    for(int i = 3;i <= (int)sqrt(n);i+=2)
        if(n%i == 0)return false;
    return true;
}

LL decompose(int n){
    LL ret = 0;
    while(n != 0){
          ret += (n%10)*(n%10);
          n/= 10;
    }
    return ret;
}

int main(){
    #ifdef DBa
    freopen("input.txt","r",stdin);
    #endif
    needforspeed;
    cin >> P;
    for(int i = 0,it,m;i < P;i++){
        cin >> it >> m;
        bool happyprime = checkem(m);
        LL n = m;
        set<LL>s;
        s.insert(m);
        while(n!=1){
              n = decompose(n);
              if(n == 1){
                 happyprime &= true;
                 break;
              }
              else if(s.count(n)){
                 happyprime &= false;
                 break;
              }
              else
                  s.insert(n);
        }
        cout << it << " " << m << " " << (happyprime ? "YES":"NO") << endl;
    }
    return 0;
}