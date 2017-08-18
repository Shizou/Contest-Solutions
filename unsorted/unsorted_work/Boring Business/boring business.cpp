#include <iostream>
#include <stdio.h>
using namespace std;

int main(){

    bool tunneled[201][402] = {0};
    bool safe = true;
    char dir = 'q';
    int steps = 0;
    int x = 4;
    int y = 198;
    int x2 = -5;
    int y2 = -1;


    //init
    tunneled[0][199] = 1;
    tunneled[1][199] = 1;
    tunneled[2][199] = 1;
    tunneled[2][200] = 1;
    tunneled[2][201] = 1;
    tunneled[2][202] = 1;
    tunneled[3][202] = 1;
    tunneled[4][202] = 1;
    tunneled[4][203] = 1;
    tunneled[4][204] = 1;
    tunneled[3][204] = 1;
    tunneled[2][204] = 1;
    tunneled[2][205] = 1;
    tunneled[2][206] = 1;
    tunneled[3][206] = 1;
    tunneled[4][206] = 1;
    tunneled[5][206] = 1;
    tunneled[6][206] = 1;
    tunneled[6][205] = 1;
    tunneled[6][204] = 1;
    tunneled[6][203] = 1;
    tunneled[6][202] = 1;
    tunneled[6][201] = 1;
    tunneled[6][200] = 1;
    tunneled[6][199] = 1;
    tunneled[6][198] = 1;
    tunneled[5][198] = 1;
    tunneled[4][198] = 1;


   while(safe){
        cin >> dir >> steps;

        if(dir == 'd'){

            for(int i = 1;i <= steps;i++){
                  x++;
                  x2--;
                if(tunneled[x][y] == false){
                    tunneled[x][y] = true;
                }
                else{
                    safe = false;
                    x2 -= steps-i;
                    break;
                }
            }
            if(safe)
                printf("%d %d safe\n", y2,x2);
            else{
                printf("%d %d DANGER\n", y2,x2);
                break;
            }
        }
        else if(dir == 'u'){

            for(int i = 1;i <= steps;i++){
                  x--;
                  x2++;
                if(tunneled[x][y] == false){
                    tunneled[x][y] = true;
                }
                else{
                    safe = false;
                    x2 +=  steps-i;
                    break;
                }
            }
            if(safe)
                printf("%d %d safe\n", y2,x2);
            else{
                printf("%d %d DANGER\n", y2,x2);
                break;
            }
        }
        else if(dir == 'l'){

             for(int i = 1;i <= steps;i++){
                  y--;
                  y2--;
                if(tunneled[x][y] == false){
                    tunneled[x][y] = true;
                }
                else{
                    safe = false;
                    y2 -= steps-i;
                    break;
                }
            }
            if(safe)
                printf("%d %d safe\n", y2,x2);
            else{
                printf("%d %d DANGER\n", y2,x2);
                break;
            }
        }
        else if(dir == 'r'){

             for(int i = 1;i <= steps;i++){
                  y++;
                  y2++;
                if(tunneled[x][y] == false){
                    tunneled[x][y] = true;
                }
                else{
                    safe = false;
                    y2 += steps-i;
                    break;
                }
            }
            if(safe)
                printf("%d %d safe\n", y2,x2);
            else{
                printf("%d %d DANGER\n", y2,x2);
                break;
            }
        }
        else{
            break;
        }
    }
    return 0;
}
