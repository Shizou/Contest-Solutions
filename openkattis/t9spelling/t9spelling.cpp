#include<bits/stdc++.h>
#define DB
#define len(x) (int)(x).size()
using namespace std;

int N;
string s,p;
map<char,string >v;


void init(){
    v['a'] = "2";
    v['b'] = "22";
    v['c'] = "222";

    v['d'] = "3";
    v['e'] = "33";
    v['f'] = "333";

    v['g'] = "4";
    v['h'] = "44";
    v['i'] = "444";

    v['j'] = "5";
    v['k'] = "55";
    v['l'] = "555";

    v['m'] = "6";
    v['n'] = "66";
    v['o'] = "666";

    v['p'] = "7";
    v['q'] = "77";
    v['r'] = "777";
    v['s'] = "7777";

    v['t'] = "8";
    v['u'] = "88";
    v['v'] = "888";

    v['w'] = "9";
    v['x'] = "99";
    v['y'] = "999";
    v['z'] = "9999";

    v[' '] = "0";
}

int main(){
    #ifdef DBa
    freopen("input.txt","r",stdin);
    #endif
    init();
    cin >> N;
    getline(cin,s);
    for(int t = 1;t <= N;t++){
        getline(cin,s);
        p = "";
        for(int i = 0;i < len(s);i++){
            if(!p.empty() && v[s[i]].substr(0,1) == p.substr(len(p)-1,1))
               p += " ";
            p += v[s[i]];
        }
        cout << "Case #" << t << ": "  << p << endl;
    }
    return 0;
}