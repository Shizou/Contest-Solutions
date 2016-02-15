#include<iostream>
#include<fstream>
#include<vector>
#include<stdio.h>
#include<string>

using namespace std;
vector< pair<char,string> > code;

int main(){
    //freopen("input.txt","r",stdin);
    int n; cin >> n;
    char c = ' ';
    string s = "";
    string ss = "";
    for(int i = 0;i < n;i++){
        cin >> c >> s;
        code.push_back( make_pair(c,s));
    }
    getline(cin,s);
    getline(cin,s);
    while(s.size() != 0){
        for(int j = 0;j < n;j++){
            if(code[j].second == s.substr(0,code[j].second.size())){
                ss+=code[j].first;
                s.erase(0,code[j].second.size());
            }
        }
    }
    cout << ss << endl;
    //fclose(stdin);
    return 0;
}
