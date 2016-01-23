#include<iostream>
#include<math.h>
#include<algorithm>

using namespace std;

int n,com;
int fj[3];
int ml[3];



bool f(int a, int b){
    if(a == b || a == b-1 || a == b-2 || a == b+1 || a == b+2)return true;
    if(a == 1 && (b == n-1 || b == n) )return true;
    if(a == 2 && b == n) return true;
    if(b == 1 && (a == n-1 || a == n) )return true;
    if(b == 2 && a == n)return true;
    return false;
}
bool checkEm(int a, int b, int c){
    if( f(a, fj[0]) && f(b, fj[1]) && f(c, fj[2]) ) return true;
    if( f(a, ml[0]) && f(b, ml[1]) && f(c, ml[2]) ) return true;
    return false;
}

int main(){
    cin >> n;
    for(int i = 0;i < 3;i++) cin >> fj[i];
    for(int i = 0;i < 3;i++) cin >> ml[i];

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            for(int k = 1;k <= n;k++){
                if(checkEm(i,j,k))
                    com++;
            }
        }
    }

    cout << com << endl;
    return 0;
}

