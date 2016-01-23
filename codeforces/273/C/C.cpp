#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define db 0
#define lb(x) ((x)&(-x))
#define all(x) (x).begin(),(x).end()
#define needforspeed ios::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define x first
#define y second
#define LL long long
using namespace std;

const int MOD = 1000000007;
int A,B,C,ans;


int main(){
    //  freopen("C-input.txt","r",stdin);
    cin >> A >> B;
    C = B+1;
    for(int i = 1; (i/C)/(C-1) <= A;i++){
        if(db)cout << i << endl;
        if(i%B != 0){
            int t = (i/B)/(i%B);
            if(t >= 1 && t <= A){
               if(db)cout << i << endl;
               ans += i;
               ans %= MOD;
            }
        }
    }
    cout << ans << endl;
    return 0;
}