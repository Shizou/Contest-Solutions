#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define db 0
#define nullptr 0
#define lb(x) ((x)&(-x))
#define all(x) (x).begin(),(x).end()
#define needforspeed ios::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define x first
#define y second
#define LL long long
using namespace std;


const int MAXN = (int)1e5;
int N;
int arr[MAXN];
map<int,int>s;
map<int,int>m;

int main(){
    // freopen("B-input.txt","r",stdin);
    needforspeed;
    cin >> N;
    for(int i = 0;i < N;i++){
        cin >> arr[i];
        if(!m.count(arr[i]))
          m[arr[i]] = i;
    }
    int abest = 0,tbest = 0;
    for(int i = 0;i < N;i++){
       s[arr[i]]++;
       abest = max(abest,s[arr[i]]);
    }
    s.clear();
    int cbest = N,B = 0,E = 0;
    for(int i = 0;i < N;i++){
        s[arr[i]]++;
        if(s[arr[i]] == abest){
           int it = m[arr[i]];
           if(abs(it-i+2) < cbest){
              B = it+1, E = i+1;
              cbest = abs(it-i+2);
           }
        }
    }
    cout << B << " " << E << endl;
    return 0;
}

