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
#define MAXN 1000005
#define inf 0x3f3f3f3f
using namespace std;

int N;
double P[MAXN];

int main(){
    #ifdef DBa
    freopen("input.txt","r",stdin);
    #endif
    needforspeed;
    for(int i = 1;i < MAXN;i++){
       P[i] = log10(i)+P[i-1];
    }
    P[0] = P[1] = 1;
    while(cin >> N){
       cout << (int)ceil(P[N]) << endl;
    }
    return 0;
}

