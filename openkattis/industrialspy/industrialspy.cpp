#include<bits/stdc++.h>
#define DB 1
#define all(x) (x).begin(),(x).end()
#define len(x) (int)(x).size()
using namespace std;

int N;
string s;
set<int>OK;

int POW(int n,int p){
    int ret = 1;
    while(p > 0 && p--)
          ret *= n;
    return ret;
}

bool prime(int n){
   if(n < 2)return false;
   for(int i = 2;i <= (int)sqrt(n);i++){
       if(n%i == 0)
          return false;
   }
   return true;
}

int main(){
    #ifdef DBa
    freopen("input.txt","r",stdin);
    #endif
    cin >> N;
    while(N--){
       cin >> s;
       sort(all(s));
       do{
          for(int sz = 0;sz <= len(s);sz++){
              for(int i = 0;i < len(s);i++){
                  int t = 0;
                  if(i+sz >= len(s))break;
                  for(int j = i,pwr = 0;j <= i+sz;j++){
                      t += (int)(s[j]-'0')*POW(10,pwr++);
                  }
                  if(prime(t))
                     OK.insert(t);
              }
          }
       }while(next_permutation(all(s)));
       cout << len(OK) << endl;
       OK.clear();
    }
}