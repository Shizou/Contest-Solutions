#include<bits/stdc++.h>
#define DB
#define needforspeed ios::sync_with_stdio(false);
#define endl '\n'
#define len(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define mp make_pair
#define LL long long
#define MOD 1000000007
using namespace std;


LL M,N,T;


bool factorial(LL m,LL n){
    LL a = 1;
    for(int i = 1;i <= n;i++){
        a*=i;
        if(a > m)
           return false;
    }
    return a <= m;
}
bool twopow(LL m, LL n){
     LL a = 1;
     for(int i = 1;i <= n;i++){
         a *=2;
         if(a > m)
             return false;
     }
     return a <= m;
}
bool ntothe4(LL m, LL n){
    return n*n*n*n <= m;
}
bool ntothe3(LL m, LL n){
    return n*n*n <= m;
}
bool ntothe2(LL m, LL n){
    return n*n <= m;
}
bool nlogn(LL m, LL n){
    return n*log2(n) <= (double)m;
}
bool on(LL m, LL n){
    return n <= m;
}



bool go(LL m,LL n,LL t){
  if(t == 1)
     return factorial(m,n);
  if(t == 2)
     return twopow(m,n);
  if(t == 3)
     return ntothe4(m,n);
  if(t == 4)
     return ntothe3(m,n);
  if(t == 5)
     return ntothe2(m,n);
  if(t == 6)
     return nlogn(m,n);
  if(t == 7)
     return on(m,n);
  return false;
}



int main(){
     #ifdef DBa
     freopen("input.txt","r",stdin);
     #endif
     needforspeed;
     cin >> M >> N >> T;
     if(go(M,N,T))
        cout << "AC" << endl;
     else
        cout << "TLE" << endl;
     return 0;
}