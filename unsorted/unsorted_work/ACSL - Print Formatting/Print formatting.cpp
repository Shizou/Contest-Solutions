/*
William Granados
Woburn Collegiate Institute
ACSL 2013-2014, Contest #2
Intermediate Division
Program: Print Formatting
*/
#include<iostream>
#include<cmath>
#include<fstream>
#include<string>
#include <stdlib.h>
#include<stdio.h>
#include<sstream>
#include <iomanip>
using namespace std;

int cash,justi,deciC,amp,roundT;
bool deci,comma,print;
double n;
string s,sn;
bool isN(char c){
    return ((c >= 48 && c <= 57) ? 1:0);
}
int main(){
    freopen("input.txt","r",stdin);
    for(int m = 0;m < 5;m++){
        cin >> s;
        cin >> sn;
        n = atof(sn.c_str());
        justi = sn.size();
        //cash
        for(int i = 0;i < s.size();i++){if(s[i] == '$'){ s.erase(i,1); cash++;}}
        // comma
        for(int i = 0;i < s.size();i++){if(s[i] == ','){ s.erase(i,1); comma=1;}}
        //decimal
        if(floor(n) != n){
            for(int i = 0;i < s.size();i++){if(s[i] == '.'){ deci=1; deciC = s.size() - i+1; s.erase(i,s.size()-1); justi = i-1; break;}}
        }
        // amp
        amp = s.size();
        s= "";
        s=sn;
        amp-=justi;
        while(amp--){s.insert(0,"*");}
        //comma
        if(comma){
            int cnt = 0;
            for(int i = s.size()-1;i > 0;i--){
                if(isN[s[i]]){cnt++;}else{break;}
                if(cnt%3 == 0){s.insert(i,",");}
            }
        }
        //cash
        if(cash){
            int cnt = 0;
            for(int i = 0;i < s.size();i++){if(isN(s[i]))break;else cnt++;}
            while(cash--){
                s.insert(cnt,"$");
            }
        }
        //decimal
        if(deci){
            int cnt = 0;
            for(int i = sn.find("."); i < sn.size();i++){cnt++;}
            if(cnt < deciC){
                cout << cnt << " " << deciC << endl;
                deciC -=cnt;
                while(deciC--){sn.append("0");}
            }
            else if(cnt > deciC){
                n = ceil( ( n * pow( 10, deciC ) ) - 0.49 ) / pow( 10,deciC);
                roundT = cnt;
                cnt = 0;
                while(1){if(isN(s[cnt]))break;else cnt++;}
                s.erase(cnt,s.size());
                print = 1;
            }


        }

        if(print){
            cout << s ;
            cout << fixed <<  setprecision(deciC) <<   n << endl;
        }
        else
            cout << s << endl;

        cash = 0;justi = 0;deciC = 0;amp = 0;roundT = 0;
        deci = 0;comma = 0;print = 0;
        s = ""; sn = "";

    }
    fclose(stdin);
}
