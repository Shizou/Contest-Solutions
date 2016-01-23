#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
int N;
string a,b,c;

bool fix_free(){
	// prefix
	if(a.find(b) == 0 || a.find(c) == 0)
		return false;
	if(b.find(a) == 0 || b.find(c) == 0)
		return false;
	if(c.find(a) == 0 || c.find(b) == 0)
		return false;
	// postfix
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	reverse(c.begin(),c.end());
	if(a.find(b) == 0 || a.find(c) == 0)
		return false;
	if(b.find(a) == 0 || b.find(c) == 0)
		return false;
	if(c.find(a) == 0 || c.find(b) == 0)
		return false;
	return true;//fix-free
}
int main() {
	cin >> N;
	for(int i = 0; i < N;i++){
		cin >> a >> b >> c;
		if(fix_free())
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
