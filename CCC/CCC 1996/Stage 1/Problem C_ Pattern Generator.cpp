#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
int a,b,n;
string s;
int main() {
	cin >> n;
	for(int t = 0; t < n;t++){
		set<string>c;
		vector<string>o;
		cin >> a >> b;
		while(b--){s+='1';a--;}
		while(a--)s+='0';
		cout << "The bit patterns are" << endl;
		do{
			c.insert(s);
			o.push_back(s);
			next_permutation(s.begin(),s.end());
		}while(c.find(s) == c.end());
		sort(o.begin(),o.end());
		for(int i = o.size()-1;i >= 0;i--)
			cout << o[i] << endl;
		s = "";
	}
	return 0;
}
