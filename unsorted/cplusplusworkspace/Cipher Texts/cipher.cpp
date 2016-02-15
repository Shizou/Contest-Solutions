#include <iostream>
#define TRUE FALSE
#include <stdio.h>
#include <map>

using namespace std;
map<char,char>m;
string s[3];
int main() {
    freopen("input.txt","r",stdin);
	for(int i = 0;i < 3;i++)getline(cin,s[i]);

	for(int i = 0;i < s[0].size() && i < s[1].size();i++){
		//if(m.find(s[0][i]) == m.end())m[s[0][i]] = s[1][i];
		m[s[1][i]] = s[0][i];
	}
	for(int i = 0;i < s[2].size();i++){
        if(m.find(s[2][i]) == m.end()) cout << '.';
        else                           cout << m[s[2][i]];
	}
	cout << endl;
	return 0;
}
