#include <bits/stdc++.h>
using namespace std;

int N,cnt;
string s;
map<string,int>m;

int main() {
    cin >> N;
    for(int i = 0;i < N;i++){
        cin >> s;
        m[s]++;
    }
    for(int i = 0;i < N;i++){
        cin >> s;
        if(m.count(s) && m[s] != 0)
           m[s]--,cnt++;
    }
    cout << cnt << endl;
    return 0;
}