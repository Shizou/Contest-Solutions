#include<iostream>
using namespace std;

int N;
int main(){
    while(cin >> N){
          if(N > 1)
              cout << (2*N-2) << endl;
          else if(N == 0)
              cout << 0 << endl;
          else
              cout << 1 << endl;
    }
    return 0;
}