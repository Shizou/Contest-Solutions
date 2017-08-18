#include<iostream>
#include<fstream>
#include<stdio.h>

using namespace std;

int r,c;
int main(){
    freopen("input.txt", "r", stdin);
    cin >> r >> c;
    bool grid[r][c];
    int record[r][c];

    char w = ' ';
    string wu; getline(cin,wu);

    for(int i = 0;i < r;i++){
        for(int j = 0;j < c;j++){
            scanf("%c",&w);
            if(w == 'X')
                grid[i][j] = 1;
            else
                grid[i][j] = 0;
        }
        getline(cin,wu);
    }
    for(int i = 1;i <= 100;i++){

     int cnt = 0;
     for(int x2 = 0;x2 < r;x2++){
            for(int y2 = 0;y2 < c;y2++){
                cnt = 0;
                //up
                if(x2-1 >= 0)
                    if(grid[x2-1][y2] == 1)
                        cnt++;

                // up right
                if(x2-1 >= 0 && y2+1 < 7)
                    if(grid[x2-1][y2+1] == 1)
                        cnt++;

                //right
                if(y2+1 < 7)
                    if(grid[x2][y2+1] == 1)
                        cnt++;

                // right down
                if(x2+1 < 7 && y2+1 < 7)
                    if(grid[x2+1][y2+1] == 1)
                        cnt++;

                // down
                if(x2+1 < 7)
                    if(grid[x2+1][y2] == 1)
                        cnt++;

                // left down
                if(x2+1 < 7 && y2-1 >= 0)
                    if(grid[x2+1][y2-1] == 1)
                        cnt++;

                // left
                if(y2-1 >= 0)
                    if(grid[x2][y2-1] == 1)
                        cnt++;

                // left up
                if(x2-1 >= 0 && y2-1 >= 0)
                    if(grid[x2-1][y2-1] == 1)
                        cnt++;

                record[x2][y2] = cnt;
            }
        }


        for(int x2 = 0;x2 < r;x2++){
            for(int y2 = 0;y2 < c;y2++){
                if(grid[x2][y2] == 1){
                    //survival
                        if(record[x2][y2] == 2 || record[x2][y2] == 3 ){
                            grid[x2][y2] = 1;
                             continue;
                        }
                        // death
                        else if(record[x2][y2] >= 4 || record[x2][y2] <= 1){
                            grid[x2][y2] = 0;
                        }
                }
                else{
                        //birth
                        if(record[x2][y2] == 3){
                            grid[x2][y2] = 1;
                            continue;
                        }

                }
            }

        }

        int wa = 0;
        if(i == 1 || i == 5 || i == 10 || i == 50 || i == 100){
            for(int x = 0;x < r;x++){
                for(int y = 0;y < c;y++){
                    if(grid[x][y] == 1)
                        wa++;
                }
            }
            cout << wa << endl;
            wa = 0;
        }
    }


    fclose(stdin);
    return 0;
}
