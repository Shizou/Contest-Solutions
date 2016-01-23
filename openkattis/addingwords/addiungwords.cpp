#include<bits/stdc++.h>
#define len(x) (int)(x).size()
#define _DB
using namespace std;

string input;
map<string,int>m;
map<int,string>mr;

int main(){
    #ifdef DB
    freopen("input.txt","r",stdin);
    #endif
    while(getline(cin,input)){
        vector<string>s;
        stringstream ss(input);
        string str;
        while(getline(ss,str,' '))
              s.push_back(str);
        if(s[0] == "def"){
           string key = s[1];
           int value = atoi(s[2].c_str());
           if(m.count(key)){
              mr.erase(m[key]);
              m.erase(key);
           }
           m[key] = value;
           mr[value] = key;
        }
        if(s[0] == "calc"){
           int value  = 0;
           int sgnbit = 1;
           bool OK = true;
           for(int i = 1;i < len(s)-1;i++){
               if(s[i] == "+")
                  sgnbit =  1;
               else if(s[i] == "-")
                  sgnbit = -1;
               else{
                  if(m.count(s[i]))
                     value += sgnbit*m[s[i]];
                  else
                     OK = false;;
               }
               cout << s[i] << " ";
           }
           cout << "= ";
           if(mr.count(value) && OK)
              cout << mr[value] << endl;
           else
              cout << "unknown" << endl;

        }
        if(s[0] == "clear")
           m.clear();
    }
    return 0;
}