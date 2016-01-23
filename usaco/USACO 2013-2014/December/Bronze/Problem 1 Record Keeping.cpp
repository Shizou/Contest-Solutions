#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;

int N,M;
string s[3];
map<string,int> mp;
int main(){
    cin >> N;
    getline(cin,s[0]);
    for(int i = 0; i < N;i++){
        cin >> s[0] >> s[1] >> s[2];
        sort(s,s+3);
        string in = s[0]+s[1]+s[2];
        if(mp.find(in) == mp.end())
            mp[in] = 1;
        else
             M = max(++mp[in],M);
    }
    cout << M << endl;
}

