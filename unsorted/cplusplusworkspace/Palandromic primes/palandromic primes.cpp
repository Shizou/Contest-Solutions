#include<iostream>
#include<fstream>
#include<sstream>
#include<string>

using namespace std;

bool check(string s){
    if(s.size()%2!=0){
        s = s.substr(0,s.size()/2) + s.substr(s.size()/2, s.size());
    }
    for(int i = 0;i < s.size()/2;i++){
        if(s[i] != s[s.size()-1-i])
            return false;
    }

    return true;
}

int main(){
    //freopen("input.txt","r",stdin);
    int in = 0; cin >> in;
    string s = "";

    for(int i = 1;;i++){
        s = static_cast<ostringstream*>( &(ostringstream() << in*i) )->str();

        if(check(s)){
            cout << i << endl;
            break;
        }
    }
    //fclose(stdin);
    return 0;
}
