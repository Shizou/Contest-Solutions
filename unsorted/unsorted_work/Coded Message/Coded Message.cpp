#include <iostream>
#include<fstream>
#include <string>
#include <stdio.h>
#include <string.h>

using namespace std;
int size;
string enc(string s){
    char grid[size][5];
    memset (grid,' ',sizeof grid);
    int x = 0,y = 0;
    for(int i = 0;i < s.size();i++){
        grid[x][y] = s[i];
        if(y == 4){
            y = 0;
            x++;
            continue;
        }
        y++;
    }
    s = "";
    for(int i = 0;i < 5;i++){
        for(int j = 0;j < size;j++){
            s+= grid[j][i];
        }
    }
    return s;
}
string dec(string s){
    char grid[size][5];
    memset (grid,' ',sizeof grid);
    int x = 0,y = 0;
    for(int i = 0;i < s.size();i++){
        grid[x][y] = s[i];
        if(x == size-1){
            x = 0;
            y++;
            continue;
        }
        x++;
    }
    s = "";
    for(int i = 0;i < size;i++){
        for(int j = 0;j < 5;j++){
            s+= grid[i][j];
        }
    }
    return s;
}
int main(){
    //freopen("input.txt","r",stdin);
    char c;
    string s;
    for(int i = 0;i < 5;i++){
        cin >> c;
        getline(cin,s);
        getline(cin,s);
        size = s.size();
        while(size%5 != 0)
            size++;
        size/=5;

        if(c == 'D')
            cout << dec(s) << endl;
        else
            cout << enc(s) << endl;
    }
    //fclose(stdin);
    return 0;
}
