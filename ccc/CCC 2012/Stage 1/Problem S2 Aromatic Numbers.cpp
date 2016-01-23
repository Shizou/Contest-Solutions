#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <map>

using namespace std;

map<char,int> t;
string s;
int total,temp;

void init(){
    t['I'] = 1;
    t['V'] = 5;
    t['X'] = 10;
    t['L'] = 50;
    t['C'] = 100;
    t['D'] = 500;
    t['M'] = 1000;
    t['1'] = 1;
    t['2'] = 2;
    t['3'] = 3;
    t['4'] = 4;
    t['5'] = 5;
    t['6'] = 6;
    t['7'] = 7;
    t['8'] = 8;
    t['9'] = 9;
}
int main(){
    //freopen("input.txt", "r", stdin);
    init();
    getline(cin,s);
    while(s.size()!= 2){
        if(t[s[3]] > t[s[1]])
            total -= t[s[0]]*t[s[1]];
        else
            total += t[s[0]]* t[s[1]];
        s.erase(0,2);
    }
    total += t[s[0]]* t[s[1]];
    cout << total << endl;
   // fclose(stdin);
    return 0;
}
