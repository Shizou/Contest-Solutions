#include <iostream>
#include <stdio.h>
#include <fstream>

using namespace std;


char grid[10][10];
bool visitedV[10][10] = {false,false};
bool visitedH[10][10] = {false,false};

int r = 0;
int c = 0;

int eX = 0, eY = 0;
int vX = 0, vY = 0;
int hX = 0, hY = 0;
bool encounter = false;
bool escape = false;
int survivalCount = 0;


void findpathV(int x, int y){
    if(x < 0 || y < 0 || x > r-1 || y > c-1 || visitedV[x][y])
        return;
    if(grid[x][y] == 'V'){
        visitedV[x][y] = true;
        return;
    }
    if(grid[x][y] == '#'){
        visitedV[x][y] = true;
        return;
    }

    visitedV[x][y] = true;

    findpathV(x+1,y);
    findpathV(x-1,y);
    findpathV(x,y+1);
    findpathV(x,y-1);

    return;
}
void findpathH(int x, int y){
    if(x < 0 || y < 0 || x > r-1 || y > c-1 || visitedH[x][y])
        return;
    if(grid[x][y] == 'H'){
        visitedH[x][y] = true;
        return;
    }
    if(grid[x][y] == '#'){
        visitedH[x][y] = true;
        return;
    }

    visitedH[x][y] = true;

    findpathH(x+1,y);
    findpathH(x-1,y);
    findpathH(x,y+1);
    findpathH(x,y-1);

    return;
}


void followpathV(int x, int y){
    visitedV[x][y] = false;

     if(x+1 <= r-1){
        if(visitedV[x+1][y]){
           if(grid[x+1][y] != '#'){
                vX +=1;
                return;
           }
           else{
                visitedV[x+1][y] = false;
           }
        }
    }
    if(x-1 >= 0){
        if(visitedV[x-1][y]){
           if(grid[x-1][y] != '#'){
                vX -=1;
                return;
           }
           else{
                visitedV[x-1][y] = false;
           }

        }
    }
    if(y+1 <= c-1){
        if(visitedV[x][y+1]){
           if(grid[x][y+1] != '#'){
                vY +=1;
                return;
           }
           else{
                visitedV[x][y+1] = false;
           }
        }
    }
    if(y-1 >= 0){
        if(visitedV[x][y-1]){
           if(grid[x][y-1] != '#'){
                vY -=1;
                return;
           }
           else{
                visitedV[x][y-1] = false;
           }
        }
    }

}
void followpathH(int x, int y){
    visitedH[x][y] = false;

     if(x+1 <= r-1){
        if(visitedH[x+1][y]){
           if(grid[x+1][y] != '#'){
                hX +=1;
                return;
           }
           else{
                visitedH[x+1][y] = false;
           }
        }
    }
    if(x-1 >= 0){
        if(visitedH[x-1][y]){
           if(grid[x-1][y] != '#'){
                hX -=1;
                return;
           }
           else{
                visitedH[x-1][y] = false;
           }

        }
    }
    if(y+1 <= c-1){
        if(visitedH[x][y+1]){
           if(grid[x][y+1] != '#'){
                hY +=1;
                return;
           }
           else{
                visitedH[x][y+1] = false;
           }
        }
    }
    if(y-1 >= 0){
        if(visitedH[x][y-1]){
           if(grid[x][y-1] != '#'){
                hY -=1;
                return;
           }
           else{
                visitedH[x][y-1] = false;
           }
        }
    }


}

int main(){
    freopen("input.txt", "r", stdin);


        cin >> r >> c;

        string input[r];

        for(int x = 0;x < r;x++)
            cin >> input[x];


        for(int x = 0;x < r;x++){
            for(int y = 0;y < c; y++){
                grid[x][y] = input[x].at(y);

                if(grid[x][y] == 'E'){
                    eX = x;
                    eY = y;
                }
                else if(grid[x][y] == 'H'){
                    hX = x;
                    hY = y;
                }
                else if(grid[x][y] == 'V'){
                    vX = x;
                    vY = y;
                }


            }
        }

    // finds the path the entity has to follow
    findpathV(eX,eY);
    findpathH(eX,eY);

    // simulation
    while(!encounter && !escape){

        if(vX == hX && vY == hY){
            encounter = true;
            break;
        }
        else if(hX == eX && hY == eY){
            escape = true;
            break;
        }
        printf("Raptor: ( %d , %d ) ", vX,vY);
        printf("Human: ( %d , %d )\n", hX,hY);

        survivalCount++;
        followpathH(hX,hY);
        if(vX != eX && vY != eY)
            followpathV(vX,vY);

    }
    if(encounter)
        cout <<  survivalCount << endl;
    else
        cout << "escape" << endl;

    fclose(stdin);
    return 0;
}

