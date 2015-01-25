#include <iostream>
using namespace std;
int N;
string s;
int main() {
	cin >> N;
	getline(cin,s);
	while(N--){
		getline(cin,s);
		int h = 0;
		for(int i = 0; i < s.size();i++){
			if(i != s.size()-1 && s.substr(i,2) == "<3")h++;
		}
		h++;
		for(int i = 0;i < h;i++){
			if(i != h-1)cout << "<3 ";
			else 		cout << "<3" << endl;
		}
	}
	return 0;
}
