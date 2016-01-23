#include <iostream>
#include <cstdio>
#include <sstream>
#include <algorithm>
using namespace std;

int N;
string s,c;
int main() {
	cin >> N;
	getline(cin,s);
	for(int i = 0; i < N;i++){
		getline(cin,s);
		stringstream ss(s);
		while(getline(ss,c,' ')){
			if(c.size() == 4)
				printf("**** ");
			else
				printf("%s ",c.c_str());
		}
		printf("\n\n");
	}
	return 0;
}
