#include<iostream>
#include<fstream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;
char g[7][7];
bool r = true;
bool ongoing = true;
string s;
string ss;
int c;
int main(){
    //freopen("input.txt","r",stdin);
    for(int m = 1;m <= 5;m++){
        getline(cin,s);
        memset (g,'0',sizeof g);
        ongoing = true;
        ss = "";
        r = true;
        for(int i = 0;ongoing && i < s.size();i++){
                if(r){
                    ss+=s[i];
                    c = atoi(ss.c_str())-1;
                    for(int j = 6;j >= 0;j--){
                        if(g[j][c] == '0'){
                            g[j][c] = 'r';
                            break;
                        }
                    }
                }
                else{
                    ss+=s[i];
                    c = atoi(ss.c_str())-1;
                    for(int j = 6;j >= 0;j--){
                        if(g[j][c] == '0'){
                            g[j][c] = 'b';
                            break;
                        }
                    }
                }


            for(int x = 0;ongoing && x < 7 ;x++){
                for(int y = 0;ongoing && y < 7;y++){
                   if(g[x][y] != '0'){
                        if(x-3 > 0){// up
                            if(g[x][y] == g[x-1][y] && g[x][y] == g[x-2][y] && g[x][y] == g[x-3][y]){
                                if(g[x][y] == 'r')
                                    cout << "RED-" << i+1 << endl;
                               else
                                    cout << "BLUE-" << i+1 << endl;
                                ongoing = false;
                                break;
                            }
                        }
                        if(x+3 < 7){//down
                            if(g[x][y] == g[x+1][y] && g[x][y] == g[x+2][y] && g[x][y] == g[x+3][y]){
                                if(g[x][y] == 'r')
                                    cout << "RED-" << i+1 << endl;
                               else
                                    cout << "BLUE-" << i+1 << endl;
                                ongoing = false;
                                break;
                            }
                        }
                        if(y-2 > 0){//left
                            if(g[x][y] == g[x][y-1] && g[x][y] == g[x][y-2] && g[x][y] == g[x][y-3]){
                                if(g[x][y] == 'r')
                                    cout << "RED-" << i+1 << endl;
                                else
                                    cout << "BLUE-" << i+1 << endl;
                                ongoing = false;
                                break;
                            }
                        }
                        if(y+2 < 7){//right
                            if(g[x][y] == g[x][y+1] && g[x][y] == g[x][y+2] && g[x][y] == g[x][y+3]){
                               if(g[x][y] == 'r')
                                    cout << "RED-" << i+1 << endl;
                               else
                                    cout << "BLUE-" << i+1 << endl;
                               ongoing = false;
                               break;
                            }
                        }
                        if(x-3 > 0 && y-3 > 0){//left up
                            if(g[x][y] == g[x-1][y-1] && g[x][y] == g[x-2][y-2] && g[x][y] == g[x-3][y-3]){
                                if(g[x][y] == 'r')
                                    cout << "RED-" << i+1 << endl;
                                else
                                    cout << "BLUE-" << i+1 << endl;
                                ongoing = false;
                                break;
                            }
                        }
                        if(x-3 > 0 && y+3 < 7){//right up
                            if(g[x][y] == g[x-1][y+1] && g[x][y] == g[x-2][y+2] && g[x][y] == g[x-3][y+3]){
                               if(g[x][y] == 'r')
                                    cout << "RED-" << i+1 << endl;
                               else
                                    cout << "BLUE-" << i+1 << endl;
                               ongoing = false;
                               break;
                            }
                        }
                        if(x+3 < 7 && y+3 < 7){//right down
                            if(g[x][y] == g[x+1][y+1] && g[x][y] == g[x+2][y+2] && g[x][y] == g[x+3][y+3]){
                                if(g[x][y] == 'r')
                                    cout << "RED-" << i+1 << endl;
                                else
                                    cout << "BLUE-" << i+1 << endl;
                                ongoing = false;
                                break;
                            }
                        }
                        if(x+3 < 7 && y-3 > 0){//left down
                            if(g[x][y] == g[x+1][y-1] && g[x][y] == g[x+2][y-2] && g[x][y] == g[x+3][y-3]){
                                if(g[x][y] == 'r')
                                    cout << "RED-" << i+1 << endl;
                                else
                                    cout << "BLUE-" << i+1 << endl;
                                ongoing = false;
                                break;
                            }
                        }
                   }
                }
            }

                    r = !r;
                    ss = "";
        }
    }

    //fclose(stdin);
    return 0;
}
