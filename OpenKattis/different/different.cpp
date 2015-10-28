#include<bits/stdc++.h>
using namespace std;

long long A,B;

int main(){
    while(cin >> A >> B){
          if(A < B)swap(A,B);
          cout << A-B << endl;
    }
}