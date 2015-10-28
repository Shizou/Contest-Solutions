#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
   if(a == 0)return b;
   else      return gcd(b%a,a);
}

int N,X,Y;

int main(){
    cin >> N;
    cin >> X;
    for(int i = 1;i < N;i++){
        cin >> Y;
        if(X%Y == 0)cout << X/Y << "/" << 1 << endl;
        else        cout << X/gcd(X,Y) << "/" << Y/gcd(X,Y) << endl;
    }
    return 0;
}