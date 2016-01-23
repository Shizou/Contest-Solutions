#include<iostream>
#include<stdio.h>
#include<sstream>
#include<map>
using namespace std;
int N,it = 1;
string s[100];
map< string, int >m;

int nextSpace(int i, string ss){
    int cnt = 0;
    for(i+1;i < ss.size();i++){
        cnt++;
        if(ss[i] == ' ')return cnt-1;
    }

    return cnt;
}
string itoa(int a){
    stringstream ss;
    ss << a;
    return ss.str();
}

int main(){
    //freopen("input.txt","r",stdin);
    cin >> N;
    getline(cin,s[0]);
    string out = "";
    for(int i = 0;getline(cin,s[i]);i++){

        if(s[i]!= ""){
            for(int j = 0; j < s[i].size();j++){
                if(j == 0){
                    int ns = nextSpace(j,s[i]);
                    string sub = s[i].substr(j, ns);
                    if(m.find(sub) == m.end()){
                        m[sub] = it;
                        out += sub + " " ;
                        it++;
                    }
                    else{
                        out += itoa(m[sub]) + " ";
                    }
                }
                else if(s[i][j] == ' '){
                    int ns = nextSpace(j+1,s[i]);
                    string sub = s[i].substr(j+1, ns);
                    if(m.find(sub) == m.end()){
                        m[sub] = it;
                        out += sub + " " ;
                        it++;
                    }
                    else{
                        out += itoa(m[sub])+ " ";
                    }
                }

            }
            cout << out << endl;
        }
        else{
            m.clear();
            it = 1;
            cout << endl;
        }
        out = "";

    }
    //fclose(stdin);
}
