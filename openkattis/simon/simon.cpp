#include<bits/stdc++.h>
#define len(x) (int)( (x).size() )
using namespace std;

int N;
string s,t;

int main(){
    cin >> N;
    getline(cin,s);
    for(int j = 0;j < N;j++){
          getline(cin,s);
          stringstream ss(s);
          vector<string>v;
          while(getline(ss,t,' '))
                v.push_back(t);
          string out = "";
          if(len(v) > 2 && v[0] == "simon" && v[1] == "says")
             for(int i = 2;i < len(v);i++)out+= v[i] + " ";
          cout << out << endl;
    }
    return 0;
}