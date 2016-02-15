#include <iostream>
#include <sstream>
#include <map>
using namespace std;

int N;
string in;
string a[30],b[30];
map < string,string> mp;

void input(string x[]){
	getline(cin,in);
	stringstream ss(in);
	for(int i = 0;i < N;i++)
		ss >> x[i];
}
int main() {
	cin >> N;
	getline(cin,in);
	input(a);input(b);
	for(int i = 0;i < N;i++){
		if(a[i] == b[i]){
			cout << "bad" << endl;
			return 0;
		}
		else if(mp.find(a[i]) == mp.end()){
			mp[a[i]] = b[i];
			mp[b[i]] = a[i];
		}
		else if(mp[a[i]] != b[i]){
			cout << "bad" << endl;
			return 0;
		}

	}
	cout << "good" << endl;
	return 0;
}
