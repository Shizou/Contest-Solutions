#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("input.txt","r",stdin);
    int a,b,c = 45;
    cin >> a >> b;
    if(a == 0)
        a = 24;
    if(b-c >= 0){
        if(a == 24)
            a = 0;

        b-=c;
        cout << a << " " << b << endl;
    }
    else if(b-c < 0){
        a--;
        b+=15;
        cout << a << " " << b << endl;
    }
    return 0;
}