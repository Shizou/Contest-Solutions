#include<iostream>
#include<fstream>
#include<vector>
#include<stdio.h>

using namespace std;
int grid[10][10] = {0};
int a,b;
bool up,dn,lt,rt;

int main(){
    freopen("input.txt","r",stdin);
    int x = 5,y = 5;
    cin >> a >> b;

    grid[4][4] = a++;
    grid[5][4] = a++;
    grid[5][5] = a++;
    int riseU = 2,runL = 2, riseD = 3, runR = 3;
    int prevU = 2,preL = 2, prevD = 3, preR = 3;
    bool done = 0;

    up = 1;
    while(a != b+1){
        if(!done){
        if(up){
            if(x-1 >= 0){
                x--;
                grid[x][y] = a++;
                riseU--;
                if(riseU == 0){
                    prevU += 2;
                    riseU = prevU;
                    up = 0;
                    lt = 1;
                }
            }

        }
        else if(dn){
            if(x+1 < 10){
               x++;
               grid[x][y] = a++;
               riseD--;
                if(riseD == 0){
                   prevD +=2;
                   riseD = prevD;
                   dn= 0;
                   rt = 1;
                }
            }
        }
        else if(rt){
            if(y+1 < 10){
                y++;
                grid[x][y] = a++;
                runR--;
                if(runR == 0){
                   preR += 2;
                   runR = preR;
                   rt = 0;
                   up = 1;
                }
            }
        }
        else if(lt){
            if(y-1 >= 0){
                y--;
                grid[x][y] = a++;
                runL--;
                if(runL == 0){
                   preL += 2;
                   runL = preL;
                   lt= 0;
                   dn = 1;
                }
            }
        }
        }
        if(a == b+1){
            done = 1;
            if(up){
                riseU--;
                a-=riseU;
            }
            else if(dn){
                riseD--;
                a-=riseD;
            }
            else if(lt){
                runL--;
                a-=runL;
            }
            else if(rt){
                runR--;
                a-=runR;
            }
        }
        if(done){
            if(up){
                x--;
                grid[x][y] = 101;
                a++;
            }
            else if(dn){
                x++;
                grid[x][y] = 102;
                a++;
            }
            else if(lt){
                y--;
                grid[x][y] = 103;
                a++;
            }
            else if(rt){
                y++;
                a++;
                grid[x][y] = 101;

            }

        }

    }
    bool row = 0;
    for(int x = 0;x < 10;x++){
        row = 0;
        for(int y = 0;y < 10;y++){
            if(grid[x][y] == 101){
                cout << "  ";
                row = 1;
            }
            else if(grid[x][y] == 102 || grid[x][y] == 103){
                cout << "   ";
                row = 1;
            }
            else if(grid[x][y] == 0)
                continue;
            else if(grid[x][y] < 10){
                printf("%2d ", grid[x][y]);
                row = 1;
            }
            else{
                printf("%2d ",grid[x][y]);
                row = 1;
            }
        }
        if(row){
            cout << endl;
        }
    }



    fclose(stdin);
    return 0;
}
