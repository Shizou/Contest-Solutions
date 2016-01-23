#include<bits/stdc++.h>
using namespace std;

int N;
vector<string> words;
string s;

void input(){
    s = "";
    getline(cin,s);
    for(int i = 0; i < s.size();i++)
        s[i] = tolower(s[i]);
    stringstream ss(s);
    string t;
    while(getline(ss,t,' '))
        words.push_back(t);
}

int main(){
    //freopen("input.txt","r",stdin);
    cin >> N;
    getline(cin,s);
    for(int i = 0; i < N;i++){
        input();
            if(words[0].size() >= 2 && words[0][words[0].size()-2] == '\'' && words[0][words[0].size()-1] == 's')
                printf("Set\n");
            else if(words[0] == "damaged")
                printf("Normal\n");
            else if(words.size() > 2 && words.size() <= 4 && words[words.size()-2] == "of")
                printf("Magic\n");
            else if(words.size() == 2 && words[0] == "of")
                printf("Rare\n");
            else if(words.size() == 2)
                printf("Not sure, take anyways\n");
            else
                printf("Normal\n");
        words.clear();
    }
}
