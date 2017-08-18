#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

string s, best = "~";

int main() {
    //freopen("in.txt","r",stdin);
	getline(cin,s);
	for(int i = 1; i < s.size();i++){
		for(int j = i+1; j < s.size();j++){
			string s1 = s.substr(0,i), s2 = s.substr(i,j-i), s3 = s.substr(j);
			reverse(s1.begin(),s1.end());
			reverse(s2.begin(),s2.end());
			reverse(s3.begin(),s3.end());
			string b = s1+s2+s3;
			if(b < best)best = b;
		}
	}
	cout << best << endl;
	return 0;
}
