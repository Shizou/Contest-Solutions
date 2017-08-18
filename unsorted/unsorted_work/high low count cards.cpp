#include<iostream>
#include<stdio.h>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

vector<int>cards(13,4);
map< string, int > query;
string input;
int index;
float high,low,mid,deck_size = 52;

void init(){
    query["A"] = 12; query["K"] = 11;
    query["Q"] = 10; query["J"] = 9;
    query["10"] = 8; query["9"] = 7;
    query["8"] = 6; query["7"] = 5;
    query["6"] = 4; query["5"] = 3;
    query["4"] = 2; query["3"] = 1;
    query["2"] = 0;
}
int main(){
    init();
    while(getline(cin,input)&& input != "QQ"){
        if(map[input] == map.end() && input == "R"){
            deck_size=52.0;
            fill(cards.begin(),cards.end(),4);
            continue;
        }
        index = query[input];
        cards[index]-= (cards[index] - 1 >= 0) ? 1:0;
        deck_size-=1.0;
        for(int i = 0;i < index;i++){
            low+=(float)cards[i];
        }
        for(int i = index+1; i < 13;i++){
            high+=(float)cards[i];
        }
        mid = cards[index];
        printf("High:%.2f\nMid:%.2f\nLow:%.2f\n",high/deck_size,mid/deck_size,low/deck_size);

        deck_size-=1.0;
        high = mid = low = 0;

        getline(cin,input);
        if(input == "QQ")break;

        index = query[input];
        cards[index]--;
        deck_size-=1.0;

        printf("\n");
    }
    return 0;
}
