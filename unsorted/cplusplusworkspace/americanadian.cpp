#include <iostream>
using namespace std;
string s;
int main() {
	while(getline(cin,s) && s!= "quit!"){
		if(s.size()<=4){
			cout << s << endl;
			continue;
		}
		else{
			for(int i = 0;i <= s.size()-2;i++){
				if(s[i] != 'a' || s[i] != 'e' || s[i] != 'i'|| s[i] != 'o' || s[i] != 'u' || s[i] != 'y'){
					if(s[i+1] == 'o' && s[i+2] == 'r'){
						cout << s.substr(0,i+1)  << "ou" << s.substr(i+2, s.size()-i) <<  endl;
						break;
					}
				}
			}
		}

	}
	return 0;
}
