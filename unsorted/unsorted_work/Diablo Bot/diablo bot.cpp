#include<iostream>
#include<stdio.h>
#include<ctype.h>
#include<vector>

using namespace std;

int N;
vector<string> wrds;
string s;
void input(){
    char c;
    while(scanf("%c",&c) && c != '\n'){
        if(c == ' '){
            wrds.push_back(s);
        //    cout << s << " ";
            s = "";
            continue;
        }
        s+=tolower(c);
    }
    wrds.push_back(s);
    //cout << s << endl;
    s = "";
}
bool is_set(){
     for(int j = 0; j < wrds[0].size();j++)
        if(j+1 < wrds[0].size() && wrds[0][j] == '\'' && wrds[0][j+1] == 's')
            return true;
    return false;
}

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d",&N);
    getline(cin,s);
    while(N--){
    wrds.clear();
    input();
        if(is_set())
            printf("Set\n");
        else if(wrds[0] == "damaged")
            printf("Normal\n");
        else if(wrds.size() > 1 && wrds[wrds.size()-2] == "of"){
            if(wrds.size() == 3 || wrds.size() == 4)
                printf("Magic\n");
            else if(wrds.size() == 2)
                printf("Rare\n");
            else
                printf("Normal\n");
        }
        else if(wrds.size() == 2)
            printf("Not sure, take anyways\n");
        else
            printf("Normal\n");
    }
}
