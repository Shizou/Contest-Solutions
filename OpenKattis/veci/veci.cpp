#include<bits/stdc++.h>
#define DB 1
#define MAXN 1005
#define all(x) (x).begin(),(x).end()
using namespace std;


int n,m;
string s,t;
stringstream ss;

int main(){
    #ifdef DBa
    freopen("input.txt","r",stdin);
    #endif
    cin >> n;
    ss << n;
    ss >> s;
    t = s;
    m = n;
    ss.clear();
    sort(all(t));

    do{
       ss << t;
       int i;
       ss >> i;
       if(n == m && i > m)
          m = i;
       else if(m != n && i < m){
           m = i;
       }
       ss.clear();
    }while( next_permutation(all(t)) );

    if(m == n)
      cout << 0 << endl;
    else
      cout << m << endl;
    return 0;
}