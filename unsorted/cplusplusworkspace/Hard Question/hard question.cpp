#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

double g,c,t;
int main(){
    freopen("input.txt","r",stdin);
    cin >> g >> c >> t;
    double tr = (c - sqrt(c*c - 2*-g*c*t))/-g;
    cout << tr*g/2 << endl;
    return 0;
}
