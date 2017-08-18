#include<iostream>

using namespace std;

int main(){
    string s;
    getline(cin,s);
    int n = s.size();
    for(int i = 0;i < n;i++){
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||s[i] == 'u' ){
            s.erase(i,2);
            n-=2;
        }
    }
    cout << s << endl;
    return 0;
}
