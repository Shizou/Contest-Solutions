#include<iostream>
#include<stdio.h>
using namespace std;

string a,b;
int c;

void add(string &a, string &b){
     for(int i = a.size()-1; i >= 0;i--){
        int sum = (a[i] - '0') + (b[i] - '0') + c;
        if(sum == 3){
            a[i] = '1';
            c = 1;
        }
        else if(sum == 2){
            a[i] = '0';
            c = 1;
        }
        else if(sum == 1){
            a[i] = '1';
            c = 0;
        }
    }
    if(c == 1)a.insert(0,"1");
    cout << a << endl;
}
int main(){
    //freopen("input.txt","r",stdin);
    getline(cin,b);
    a = b + "0000";
    b = "0000" + b;
    add(a,b);
}
