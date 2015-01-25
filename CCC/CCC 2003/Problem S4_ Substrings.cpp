#include <iostream>
#include <set>
using namespace std;

int N;
string s;
set<string>used;
int main() {
	cin >> N;
	for(int t = 0; t < N;t++){
		cin >> s;
		used.insert("");
		for(int i = 1; i <= s.size();i++){
			for(int j = 0; j < s.size();j++){
				if(j+i<=s.size())
					used.insert(s.substr(j,i));
				else
					break;
			}
		}
		cout << used.size() << endl;
		used.clear();
	}	
	return 0;
}
