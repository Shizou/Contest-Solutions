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

string s;
set<string>ok;

int main(){
    freopen("A-input.txt","r",stdin);
    needforspeed;
    cin >> s;
    for(int i = 0;i < (int)s.size();i++){
        for(char c = 'a'; c <= 'z';c++){
            string ss = s.substr(0,i)+c+s.substr(i,-1);
            ok.insert(ss);
            if(db)cout << ss << endl;
        }
    }
    for(char c = 'a'; c<= 'z';c++)
        ok.insert(s+c);
    cout << (int)ok.size() << endl;
    return 0;
}