#include<iostream>
#include<fstream>
#include<stdio.h>
using namespace std;
int main(){
    int a = 91,b,c,d;
    cin >> b >> c >> d;
    a+= b*1 + c*3 + d*1;
    cout << "The 1-3-sum is " << a << endl;
    return 0;
}
