#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>

using namespace std;
char grid[8][8];
char c;
int n,x,y,wu;
int w,b;
bool d;

void def(){
    if(c == 'a'){
        grid[3][3] = 'w';
        grid[4][4] = 'w';
        grid[3][4] = 'b';
        grid[4][3] = 'b';
    }
    else if(c == 'b'){
        grid[0][0] = 'b';
        grid[1][1] = 'b';
        grid[2][2] = 'b';
        grid[3][3] = 'b';
        grid[3][3] = 'b';
        grid[4][4] = 'b';
        grid[5][5] = 'b';
        grid[6][6] = 'b';
        grid[7][7] = 'b';
        grid[0][7] = 'w';
        grid[1][6] = 'w';
        grid[2][5] = 'w';
        grid[3][4] = 'w';
        grid[4][3] = 'w';
        grid[5][2] = 'w';
        grid[6][1] = 'w';
        grid[7][0] = 'w';
    }
    else{
        grid[0][2] = 'b';
        grid[0][3] = 'b';
        grid[1][2] = 'b';
        grid[1][3] = 'b';
        grid[2][2] = 'b';
        grid[2][3] = 'b';
        grid[3][2] = 'b';
        grid[3][3] = 'b';
        grid[4][2] = 'b';
        grid[4][3] = 'b';
        grid[5][2] = 'b';
        grid[5][3] = 'b';
        grid[6][2] = 'b';
        grid[6][3] = 'b';
        grid[7][2] = 'b';
        grid[7][3] = 'b';
        grid[0][4] = 'w';
        grid[0][5] = 'w';
        grid[1][4] = 'w';
        grid[1][5] = 'w';
        grid[2][4] = 'w';
        grid[2][5] = 'w';
        grid[3][4] = 'w';
        grid[3][5] = 'w';
        grid[4][4] = 'w';
        grid[4][5] = 'w';
        grid[5][4] = 'w';
        grid[5][5] = 'w';
        grid[6][4] = 'w';
        grid[6][5] = 'w';
        grid[7][4] = 'w';
        grid[7][5] = 'w';
    }
}
void count(){
    for(int m = 0;m < 8;m++){
        for(int n = 0;n < 8;n++){
            if(grid[m][n] == 'w'){
                w++;
            }
            else if(grid[m][n] == 'b'){
                b++;
            }
        }
     }
    return;
}
void update(char p){
    grid[x][y] = p;
    //up
    d = 0;
    for(int i = x-1;i >= 0 ;i--){
        if(!d && grid[i][y] == p){
           d = 1;
           i = x;
       }
       else if(d){
            if(grid[i][y] != p)
                grid[i][y] = p;
            else
                break;
       }
       else if(grid[i][y] == '.')
                break;
    }
    //down
    d = 0;
    for(int i = x+1;i < 8 ;i++){
       if(!d && grid[i][y] == p){
           d = 1;
           i = x;
       }
       else if(d){
            if(grid[i][y] != p)
                grid[i][y] = p;
            else
                break;
       }
       else if(grid[i][y] == '.')
                break;
    }
    //left
    d = 0;
    for(int i = y-1;i >= 0 ;i--){
       if(!d && grid[x][i] == p){
           d = 1;
           i = y;
       }
       else if(d){
            if(grid[x][i] != p)
                grid[x][i] = p;
            else
                break;
       }
       else if(grid[x][i] == '.')
                break;
    }
     //right
    d = 0;
    for(int i = y+1;i < 8 ;i++){
       if(!d && grid[x][i] == p){
           d = 1;
           i = y;
       }
       else if(d){
            if(grid[x][i] != p)
                grid[x][i] = p;
            else
                break;
       }
       else if(grid[x][i] == '.')
                break;
    }
    // up left
    d = 0;
    wu = x-1;
        for(int j = y-1;j >= 0 ;j--){
          if(!d && grid[wu][j] == p){
                d = 1;
                wu = x;
                j = y;
            }
            else if(d){
                if(grid[wu][j] != p)
                    grid[wu][j] = p;
                else
                    break;
            }
            else if(grid[wu][j] == '.'){
                break;
            }
            if(wu-1 >= 0)
                wu--;
            else
                break;
        }

    // up right
    d = 0;
    wu = x-1;
        for(int j = y+1;j < 8 ;j++){
          if(!d && grid[wu][j] == p){
                d = 1;
                wu = x;
                j = y;
            }
            else if(d){
                if(grid[wu][j] != p)
                    grid[wu][j] = p;
                else
                    break;
            }
            else if(grid[wu][j] == '.'){
                break;
            }
            if(wu-1 >= 0)
                wu--;
            else
                break;
        }
    // down right
       d = 0;
       wu = x+1;
        for(int j = y+1;j < 8 ;j++){
          if(!d && grid[wu][j] == p){
                d = 1;
                wu = x;
                j = y;
            }
            else if(grid[wu][j] == '.'){
                break;
            }
            else if(d){
                if(grid[wu][j] != p)
                    grid[wu][j] = p;
                else
                    break;
            }

            if(wu+1 < 8)
                wu++;
            else
                break;
        }
    // down left
       d = 0;
       wu = x+1;
        for(int j = y-1;j >= 0 ;j--){
          if(!d && grid[wu][j] == p){
                d = 1;
                wu = x;
                j = y;
            }
            else if(grid[wu][j] == '.'){
                break;
            }
            else if(d){
                if(grid[wu][j] != p)
                    grid[wu][j] = p;
                else
                    break;
            }
            if(wu+1 < 8)
                wu++;
            else
                break;
        }
}
int main(){
    //freopen("input.txt","r",stdin);
    memset(grid,'.',sizeof grid);
    scanf("%c", &c);
    def();
    cin.ignore();
    cin >> n;
    for(int j = 1;j <= n;j++){
        cin >> x >> y;
        x--;
        y--;
       if(j%2 != 0)
            update('b');
        else
            update('w');
    }
    count();
    cout << b << " " << w << endl;
    //fclose(stdin);
    return 0;
}
