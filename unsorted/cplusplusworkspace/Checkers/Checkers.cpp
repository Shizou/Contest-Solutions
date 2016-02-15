#include<iostream>
#include<fstream>

using namespace std;
int pX, pY;
int s;
int cnt;
bool grid[8][8];
bool move;
bool up;
bool king = 0;

bool searchUp(int x, int y){
    // right
   if(x+1 < 8 && y+1 < 8){
        if(x+2 < 8 && y+2 < 8){{

        }
   }
   }

}
bool searchDown(int x, int y){

   /* for(;x < 8;x--){
        for(;y < 8;y++){
            if(x)
        }
    }*/

}

int main(){
    freopen("input.txt","r",stdin);
    cin >> pX >> pY >> s;
    int eX,eY;


    for(int i = 0;i < s;i++){
        cin >> eX >> eY;
        eX--;
        eY--;
        grid[eX][eY] = 1;
    }

    pX--;
    pY--;

   /* while(move){
        if(up && searchUp(pX-1,pY-1)){

            cnt++;
        }
        else if(searchDown(pX-1,pY-1])){

                cnt++;
        }
        else
            break;
    }*/
    for(int i = 0;i < 8;i++){
        for(int j = 0;j < 8;j++){
            cout << grid[i][j];
        }
        cout << endl;
    }


    cout <<  "count : "<< cnt << endl;
    fclose(stdin);
    return 0;
}
