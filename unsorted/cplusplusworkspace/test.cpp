#include <iostream>
#include<stdio.h>
#include <stdlib.h>
#include<string>
using namespace std;
int a,b;
char c;
string s;
int main() {
	for(;;){
		getline(cin,s);
		if(s[0] == '1'){
            if(s[2] == 'A')
                a = atoi(s.substr(4, s.size()-1).c_str());
            else
                b = atoi(s.substr(4, s.size()-1).c_str());
		}
		else if(s[0] == '2'){
            if(s[2] == 'A')
                cout << a << endl;
            else
                cout << b << endl;
		}
		else if(s[0] == '3'){
            if(s[2] == 'A')
                if(s[4] == 'A'){
                    a*=2;
                }
                else
                    a += b;
            else{
                if(s[4] == 'B'){
                    b*=2;
                }
                else
                    b+=a;
            }
		}
		else if(s[0] == '4'){
            if(s[2] == 'A')
                if(s[4] == 'A'){
                    a*=a;
                }
                else
                    a *= b;
            else{
                if(s[4] == 'B'){
                    b*=b;
                }
                else
                    b*=a;
            }
		}
		else if(s[0] == '5'){
            if(s[2] == 'A')
                if(s[4] == 'A'){
                    a = 0;
                }
                else
                    a -= b;
            else{
                if(s[4] == 'B'){
                    b= 0;
                }
                else
                    b-=a;
            }
		}
		else if(s[0] == '6'){
            if(s[2] == 'A')
                if(s[4] == 'A'){
                    a = 1;
                }
                else
                    a /= b;
            else{
                if(s[4] == 'B'){
                    b = 1;
                }
                else
                    b/=a;
            }
		}
		else if(s[0] == '7')
			break;

		s = "";
	}
	return 0;
}
