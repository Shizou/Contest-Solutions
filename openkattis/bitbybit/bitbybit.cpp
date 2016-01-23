#include<bits/stdc++.h>
#define DBa
using namespace std;

struct bit{
     int val;
     bit(){
       val = -1;
     }
     void CLEAR(){
        val = 0;
     }
     void SET(){
        val = 1;
     }
     void RESET(){
        val = -1;
     }
     void OR(bit i){
        if(val == 0 && i.val == 0)
           val = 0;
        if(val == 0 && i.val == 1)
           val = 1;
        if(val == 0 && i.val == -1)
           val = -1;

        if(val == 1 && i.val == 0)
           val = 1;
        if(val == 1 && i.val == 1)
           val = 1;
        if(val == 1 && i.val == -1)
           val = 1;

        if(val == -1 && i.val == 0)
           val = -1;
        if(val == -1 && i.val == 1)
           val = 1;
        if(val == -1 && i.val == -1)
           val = -1;
     }
     void AND(bit i){
        if(val == 0 && i.val == 0)
           val = 0;
        if(val == 0 && i.val == 1)
           val = 0;
        if(val == 0 && i.val == -1)
           val = 0;

        if(val == 1 && i.val == 0)
           val = 0;
        if(val == 1 && i.val == 1)
           val = 1;
        if(val == 1 && i.val == -1)
           val = -1;

        if(val == -1 && i.val == 0)
           val = 0;
        if(val == -1 && i.val == 1)
           val = -1;
        if(val == -1 && i.val == -1)
           val = -1;
     }
};

int N;
string cmd;
bit integer[32];

int main(){
    #ifdef DB
    freopen("input.txt","r",stdin);
    #endif
    while(cin >> N && N!= 0){
        for(int i = 0;i < 32;i++)
            integer[i].RESET();
        for(int t = 0,i,j;t < N;t++){
            cin >> cmd;
            if(cmd == "CLEAR"){
               cin >> i;
               integer[i].CLEAR();
            }
            if(cmd == "SET"){
               cin >> i;
               integer[i].SET();
            }
            if(cmd == "OR"){
               cin >> i >> j;
               integer[i].OR(integer[j]);
            }
            if(cmd == "AND"){
               cin >> i >> j;
               integer[i].AND(integer[j]);
            }
        }
        for(int i = 31;i >= 0;i--){
            if(integer[i].val == 1 || integer[i].val == 0)
               cout << integer[i].val;
            else
               cout << "?";
        }cout << endl;
    }

    return 0;
}