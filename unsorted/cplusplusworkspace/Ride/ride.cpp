/*
ID: will.gr1
PROG: ride
LANG: C++
*/
#include<iostream>
#include<stdio.h>
using namespace std;

string s1,s2;
int a1 = 1,a2 = 1;
int main(){
    freopen("ride.in","r",stdin);
    freopen("ride.out","w",stdout);

    getline(cin,s1);
    getline(cin,s2);

    for(int i = 0;i < s1.size();i++)
        a1 *= s1[i]-64;
    for(int i = 0;i < s2.size();i++)
        a2 *= s2[i]-64;

    a1%= 47;
    a2%= 47;
    //printf("%d %d\n",a1,a2);
    printf("%s\n",(a1 == a2) ? "GO":"STAY" );
}
