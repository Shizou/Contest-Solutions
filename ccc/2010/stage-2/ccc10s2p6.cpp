#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define db 0
#define all(x)(x).begin(),(x).end()
#define x first
#define y second
using namespace std;

int N;
string in;
map<char,char>m;
set<string>past;
map<string,int>idx;

void shift(string &s){
     for(int i = 0;i < (int)s.size();i++)
          s[i] = m[s[i]];
}
int main(){
    freopen("Input/shuffle10.in","r",stdin);
    for(char i = 'A';i <= 'Z';i++){
        cin >> m[i];
    }
    cin >> m['_'];
    cin >> N >> in;
    string s = in;
    for(int t = 0;t < N;t++){
      shift(s);
      if(past.count(s)){
         int cyc = t-idx[s];
         int rem = N-t;
         rem%=cyc;
         t = N-rem;
      }
      else{
         past.insert(s);
         idx[s] = t;
      }
    }
    cout << s << endl;
    return 0;
}

