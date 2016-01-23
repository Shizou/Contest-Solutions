#include<iostream>
#include<fstream>
#include<vector>
#include<stdio.h>
using namespace std;
int game[52] = {0};
int a,b;
int main(){
    //freopen("input.txt","r",stdin);
    string s = "";

    for(int i = 0;i < 52;i++){
        getline(cin,s);
        if(s == "jack")
            game[i] += 11;
        else if(s == "queen")
            game[i] += 12;
        else if(s == "king")
            game[i] += 13;
        else if(s == "ace")
            game[i] += 14;
        else
            game[i] += 1;
    }

    bool aT = true;
    for(int i = 0;i < 52;i++){
        if(game[i] == 14){
            if(i + 4 < 52){
                if(game[i+1] < 11 && game[i+2] < 11 && game[i+3] < 11 && game[i+4] < 11){
                    if(aT){
                        cout << "Player A scores 4 point(s)." << endl;
                        a+=4;
                    }
                    else{
                        cout << "Player B scores 4 point(s)." << endl;
                        b+=4;
                    }
                }
            }
        }
        else if(game[i] == 13){
            if(i + 3 < 52){
                if(game[i+1] < 11 && game[i+2] < 11 && game[i+3] < 11){
                    if(aT){
                        cout << "Player A scores 3 point(s)." << endl;
                        a+=3;
                    }
                    else{
                        cout << "Player B scores 3 point(s)." << endl;
                        b+=3;
                    }
                }
            }
        }
        else if(game[i] == 12){
            if(i + 2 < 52){
                if(game[i+1] < 11 && game[i+2] < 11){
                    if(aT){
                        cout << "Player A scores 2 point(s)." << endl;
                        a+=2;
                    }
                    else{
                        cout << "Player B scores 2 point(s)." << endl;
                        b+=2;
                    }
                }
            }
        }
        else if(game[i] == 11){
            if(i + 1 < 52){
                if(game[i+1] < 11){
                    if(aT){
                        cout << "Player A scores 1 point(s)." << endl;
                        a++;
                    }
                    else{
                        cout << "Player B scores 1 point(s)." << endl;
                        b++;
                    }
                }
            }
        }

        aT = !aT;
    }
    cout << "Player A: " << a << " point(s)." << endl;
    cout << "Player B: " << b << " point(s)." << endl;
    //fclose(stdin);
    return 0;
}
