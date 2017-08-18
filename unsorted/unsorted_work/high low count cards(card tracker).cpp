#include<iostream>
#include<stdio.h>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

int cards[13][4]{1};
int index;
float high,low,mid,deck_size = 52;
map< string, int > query;
string input;


void init(){
    query["A"] = 12; query["K"] = 11;
    query["Q"] = 10; query["J"] = 9;
    query["10"] = 8; query["9"] = 7;
    query["8"] = 6;  query["7"] = 5;
    query["6"] = 4;  query["5"] = 3;
    query["4"] = 2;  query["3"] = 1;
    query["2"] = 0;

    /*query["S"] = 0;
    query["C"] = 1;  query["D"] = 2;
    query["H"] = 3;*/
}
void reset(){
    for(int i = 0;i < 13;i++){
        for(int j =0; j < 4;j++){
            cards[i][j] = 1;
        }
    }
}
bool validate_input(string & in){
    if(in.size() >= 2 && in.size() <= 3){
        if(in.size() == 3){
            if(query.find(in.substr(0,2)) != query.end() && query.find(in.substr(2,1)) != query.end()){
                return true;
            }
                return false;
        }
        else{
            return true;

        }
    }
    else
        return false;

   // return (query.find(in) == query.end()) ? ((in == "QQ" || in == "RR") ? true:false):true;
}
int main(){
    init();
    while(getline(cin,input)){
        printf("%s\n",(validate_input(input)) ? "OKAY":"INVALID");
    }

    return 0;
}
