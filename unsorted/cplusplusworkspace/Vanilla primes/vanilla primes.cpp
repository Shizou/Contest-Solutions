#include <iostream>
#include <math.h>

using namespace std;

bool primeChecker(int a){
    if(a == 1 || a == 2)
        return true;
    if(a % 2 == 0 || a < 0)
        return false;

    for(int i = 3;i <= (int)sqrt(a);i+=2){
        if(a%i == 0)
            return false;
    }

    return true;
}

int main(){
    int a;
    cin >> a;

    if(primeChecker(a))
        cout << "prime\n" ;
    else
        cout << "not";

    return 0;
}
