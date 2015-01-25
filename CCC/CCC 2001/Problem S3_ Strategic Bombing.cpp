#include<iostream>
#include<fstream>
#include<queue>
#include<map>
#include<vector>
#include<string.h>
#include<stdio.h>
using namespace std;
bool g[26][26];
bool v[26];
map<char,int>p;
vector<string>r;
string s;
int cnt;
void init(){
    p['A'] = 0;  p['B'] = 1;
    p['C'] = 2;  p['D'] = 3;
    p['E'] = 4;  p['F'] = 5;
    p['G'] = 6;  p['H'] = 7;
    p['I'] = 8;  p['J'] = 9;
    p['K'] = 10; p['L'] = 11;
    p['M'] = 12; p['N'] = 13;
    p['O'] = 14; p['P'] = 15;
    p['Q'] = 16; p['R'] = 17;
    p['S'] = 18; p['T'] = 19;
    p['U'] = 20; p['V'] = 21;
    p['W'] = 22; p['X'] = 23;
    p['Y'] = 24; p['Z'] = 25;
    memset(v,0,sizeof v);
}
int main(){
   // freopen("input.txt","r",stdin);
    init();
    while(true){
        getline(cin,s);
        if(s[0] == '*') break;
        g[p[s[0]]] [p[s[1]]] = 1;
        g[p[s[1]]] [p[s[0]]] = 1;
        r.push_back(s);
    }
    queue< int > q;
    string ss;
    bool pos = 0,f = 0;
    for(int j = 0;j < r.size();j++){
        q.push(0);
        ss = r[j];
        g[p[ss[0]]] [p[ss[1]]] = 0;
        g[p[ss[1]]] [p[ss[0]]] = 0;
        pos = 0;
            while(!q.empty()){
                    int n = q.front();
                    q.pop();
                    if(v[n]) continue;
                    if(n == 1){
                        pos = 1;
                        break;
                    }
                    v[n] = 1;
                    for(int i = 0;i < 26;i++) if(g[n][i] == 1){ q.push(i);}
                }
            if(!pos){
             cnt++;
             cout << ss << endl;
            }
        g[p[ss[0]]] [p[ss[1]]] = 1;
        g[p[ss[1]]] [p[ss[0]]] = 1;
        q = queue<int>();
        memset(v,0,sizeof v);
    }
    printf("There are %d disconnecting roads.\n",cnt);
    //fclose(stdin);
    return 0;
}
