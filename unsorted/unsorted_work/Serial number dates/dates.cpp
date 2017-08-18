#include<iostream>
#include<stdio.h>
#include <stdlib.h>
#include<fstream>
#include<string>
#include<cstdlib>
using namespace std;

string s,ss;
int year = 1904, mon = 1, day = 1;
int hour = 0, mint = 0, sec = 0;
int dm[] = {31,28,31,30,31,30,31,31,30,31,30,31};
int main(){
    //freopen("input.txt","r",stdin);
    int t = 5;
    while(t--){
        getline(cin,s);
        for(int i = 0;i < s.size();i++){
            if(s[i] == '.'){
                ss = "0" + s.substr(i,s.size());
                s = s.substr(0,i);
                break;
            }
        }
        int td = atoi(s.c_str());
        while(td--){
            day++;
            year%4 == 0 ? dm[1] = 29:dm[1] = 28;
            if(day > dm[mon-1]){
                mon++;
                day = 1;
                if(mon == 13){
                    year++;
                    mon = 1;
                }
            }
        }
        double ts = atof(ss.c_str())*1440*60;
        while(ts --> 0){
            sec++;
            if(sec == 60){
                mint++;
                sec = 0;
            }
            if(mint == 60){
                hour++;
                mint = 0;
            }
        }
        if(hour == 24){
            day++;
            hour = 0;
            year%4 == 0 ? dm[1] = 29:dm[1] = 28;
            if(day > dm[mon-1]){
                mon++;
                day = 1;
                if(mon == 13){
                    year++;
                    mon = 1;
                }
            }
        }
        printf("year = %d month = %d day = %d\n",year,mon,day);
        if(hour > 0 && mint > 10 && sec > 10) printf("time is: %d:%d:%d\n\n",hour,mint,sec);
        else{
            if(mint > 10){
                printf("time is: %d:",hour);
                printf("%d:0%d\n\n",mint,sec);
            }
            else if(sec > 10){
                printf("time is: %d:",hour);
                printf("0%d:%d\n\n",mint,sec);
            }
            else{
                printf("time is: %d:",hour);
                printf("0%d:0%d\n\n",mint,sec);
            }
        }
        year = 1904; mon = 1; day = 1;
        hour = 0; mint = 0; sec = 0;
        dm[1] = 28;
    }
    fclose(stdin);
    return 0;
}
