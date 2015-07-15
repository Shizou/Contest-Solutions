//http://www.quora.com/Given-a-string-how-do-I-find-the-number-of-distinct-substrings-of-the-string
#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define db 1
#define lb(x) ((x)&(-x))
#define all(x) (x).begin(),(x).end()
#define len(x) (int)(x).size()
#define needforspeed ios::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define x first
#define y second
#define LL long long
using namespace std;


int lcp(string &a,string &b){
    for(int i = 0;i < (int)min(a.size(),b.size());i++){
        if(a[i]!=b[i]){
          return i;
        }
    }
    return (int)b.size();
}

const int MAXN = 5005;
int T,N,ans;
string s,suffix[MAXN];


int main(){
    //freopen("input.txt","r",stdin);
    needforspeed;
    cin >> T;
    while(T--){
        cin >> s;
        N = len(s);
        for(int i = 0;i < N;i++){
            suffix[i] = s;
            s.erase(0,1);
        }
        sort(suffix,suffix+N);
        ans = len(suffix[0]) + 1;// "" string
        for(int i = 1;i < N;i++){
            ans+= len(suffix[i]) - lcp(suffix[i],suffix[i-1]);
        }
        cout << ans << endl;
    }
    return 0;
}

