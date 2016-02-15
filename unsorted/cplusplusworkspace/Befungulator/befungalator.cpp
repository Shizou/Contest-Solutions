#include<stdio.h>
#include<iostream>

using namespace std;

int N,M,x,y;
string g[100];
bool v[100][100];

bool valid(string &dir){
        if(dir == ">" && y+1 <= M-1)     return true;
        else if(dir == "<" && y-1 >= 0)  return true;
        else if(dir == "v" && x+1 <= N-1)return true;
        else if(dir == "^" && x-1 >= 0)  return true;
        return false;
}
void update_direction(string &dir){
        if(dir == ">")     y++;
        else if(dir == "<")y--;
        else if(dir == "v")x++;
        else if(dir == "^")x--;
}
int main(){
    //freopen("input.txt","r",stdin);
    cin >> N >> M;
    getline(cin,g[0]);
    for(int i =  0; i < N;i++)
        getline(cin,g[i]);
    int value = 0;
    string dir = ">";
    string opr = "";
    for(;;){
        if(g[x][y] == 'X'){
            printf("%d\n",value);
            break;
        }
        else if(g[x][y] == '+' || g[x][y] == '-' || g[x][y] == '*' || g[x][y] == '/' || g[x][y] == '%'){
            opr = g[x][y];
        }
        else if( (int)g[x][y] >= 48 && (int)g[x][y] <= 57){
            if(value == 0){
                value = g[x][y]-'0';
            }
            else{
                if(opr == "+")     value+= g[x][y]-'0';
                else if(opr == "-")value-= g[x][y]-'0';
                else if(opr == "*")value*= g[x][y]-'0';
                else if(opr == "/"){
                    if(g[x][y]-'0' == 0){
                        printf("Zero Division Error\n");
                        break;
                    }
                    value/= g[x][y]-'0';
                }
                else if(opr == "%"){
                    if(g[x][y]-'0' == 0){
                        printf("Invalid Modulo\n");
                        break;
                    }
                    value%= g[x][y]-'0';
                }
            }
        }
        else if( (g[x][y] == '<' || g[x][y] == '>' || g[x][y] == 'v' || g[x][y] == '^' ) && !v[x][y]){
                dir = g[x][y];
                v[x][y] = true;
        }
        else if(v[x][y]){
            printf("Infinite Loop\n");
            break;
        }

        if(valid(dir))
            update_direction(dir);
        else{
            printf("Invalid Direction\n");
            break;
        }
    }
}
