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
			for(int i = 0;i < s.size();i++){
				if(s[i] != 'a' || s[i] != 'e' || s[i] != 'i'|| s[i] != 'o' || s[i] != 'u' || s[i] != 'y'){
					if(i+2 < s && s[i+1] == 'o' && s[i+1] == 'r'){
						cout << s.substr(0,i+1) << "u" << s.substr(i+1,s.size()-i);
						break;
					}
				}
			}

		}

	}
	return 0;
}
