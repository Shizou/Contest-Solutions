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

int P,K;
int arr[20];

int main(){
    #ifdef DBa
    freopen("input.txt","r",stdin);
    #endif
    needforspeed;
    cin >> P;
    for(int p = 1;p <= P;p++){
        cin >> K;
        for(int i = 0;i < 20;i++)
            cin >> arr[i];

        int cnt = 0;
        set<int>s;
        s.insert(arr[0]);
        for(int i = 1;i < 20;i++){
            auto it = s.upper_bound(arr[i]);
            if(it == s.end())s.insert(arr[i]);
            else{
                cnt += len(s)-distance(s.begin(),it);
                s.insert(arr[i]);
            }
        }
        cout << p << " " << cnt << endl;
    }
    return 0;
}