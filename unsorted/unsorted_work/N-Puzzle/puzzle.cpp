#include <iostream>
#include<stdio.h>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;

string s[4];
map< char, pair<int,int> > m;
string s2;
int ans = 0;


int main() {
    freopen("input.txt","r",stdin);

	for(int i = 0;i < 4;i++){
		getline(cin,s[i]);
		s2+= s[i];
		for(int j = 0;j < 4;j++){
			m[s[i][j]] = make_pair(i,j);

		}
	}
	sort(s2.begin(),s2.end());
	for(int i = 0; i < s2.size();i++){
        if(s2[i] >= 65 && s2[i] <= 90){
            break;
        }
        else{
            s2 += s2[i];
            s2.erase(0,1);
            i = -1;
        }
	}
	cout << s2 << endl;

	s[0] = s2.substr(0,4);
	s[1] = s2.substr(3,4);
	s[2] = s2.substr(7,4);
	s[3] = s2.substr(11,4);

	for(int i = 0;i < 4;i++){
		for(int j = 0; j < 4;j++){
			cout << s[i][j];
		}
        cout << endl;
	}

	for(int i = 0;i < 4;i++){
		for(int j = 0; j < 4;j++){
			ans += abs(i - m[s[i][j]].first) + abs(i - m[s[i][j]].second);
		}

	}

	cout << ans << endl;

    fclose(stdin);
	return 0;
}
