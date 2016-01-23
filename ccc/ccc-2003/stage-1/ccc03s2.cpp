#include <iostream>
#include <cctype>
using namespace std;

int T;
string w[4];
bool isvowel(char&c){
	return c == 'a' ? true:((c == 'e') ? true: ((c == 'i') ? true:((c == 'o') ? true:((c == 'u')?true:false))));
}
int main() {
	cin >> T;
	getline(cin,w[0]);
	while(T--){
		for(int i = 0; i < 4;i++){
			getline(cin,w[i]);
			int last = 0;bool vowel = false;
			for(int j = 0; j < w[i].size();j++){
				w[i][j] = tolower(w[i][j]);
				if(w[i][j] == ' ')
					last = j;
				if(isvowel(w[i][j]))
					vowel = true;
			}
			if(last!=0)
				w[i] = w[i].substr(last+1,w[i].size()-last-1);
			if(!vowel)continue;
			for(int j = w[i].size()-1; j >= 0;j--){
				if(isvowel(w[i][j])){
					w[i] = w[i].substr(j,w[i].size()-j);
					break;
				}
			}
		}
		if(w[0] == w[1] && w[1] == w[2] && w[2] == w[3])
			printf("perfect\n");
		else if(w[0] == w[1] && w[2] == w[3])
			printf("even\n");
		else if(w[0] == w[2] && w[1] == w[3])
			printf("cross\n");
		else if(w[0] == w[3] && w[1] == w[2])
			printf("shell\n");
		else
			printf("free\n");
	}
	return 0;
}
