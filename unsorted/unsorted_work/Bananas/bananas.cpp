#include <iostream>
#include <cstdio>
using namespace std;

string s;
int main() {
    freopen("input.txt","r",stdin);
	while(cin>>s && s != "X"){
	    string s2 = "";
        while(s2 != s){
            s2 = s;
            for(int i = 0; i < s.size();i++){
                if(i+1 < s.size()){
                    if(s[i] == 'A' &&  s[i+1] == 'N'){
                        s.erase(i+1,1);
                        i--;
                    }
                }
            }
            for(int  i = 0; i < s.size();i++){
                if(i+2 < s.size()){
                    if(s[i] == 'B' && s[i+1] == 'A' && s[i+2] == 'S'){
                        s.erase(i,3);
                        s.insert(i,"A");
                        i--;
                    }
                }
            }
            for(int i = 0; i < s.size();i++){
                if(i+1 < s.size()){
                    if(s[i] == 'A' && s[i+1] == 'A' ){
                        s.erase(i+1,1);
                        i--;
                    }
                }
            }
        }
        if(s == "A")cout << "YES" << endl;
        else        cout << "NO"  << endl;
	}
	return 0;
}
