#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
using namespace std;

bool x;
string s;

int main(){
    //freopen("input.txt","r",stdin);
    cin >> s;
    for(int i = 0;i < (int)s.size();i++){
        for(int k = 0;k < (int)s.size();k++){
            string t = "";
            for(int j = 0;j < (int)s.size();j++){
                if(!(j >= i && j <= i+k))t+=s[j];
            }
            if(t == "CODEFORCES")
               x = true;
        }
    }
    printf("%s\n",x ? "YES":"NO");
    return 0;
}