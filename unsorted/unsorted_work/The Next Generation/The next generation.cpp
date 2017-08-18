#include<iostream>
#include<fstream>

using namespace std;

bool grid[7][7] = {0};
bool grid2[7][7] = {0};
int n,x,y;
int rb,rs;

void buu(){
    if(grid2[x][y] == 1)
            cout << "A";
        else
            cout << "D";

    int cnt = 0;
            //up
                if(x-1 >= 0)
                    if(grid2[x-1][y] == 1)
                        cnt++;
                // up right
                if(x-1 >= 0 && y+1 < 7)
                    if(grid2[x-1][y+1] == 1)
                        cnt++;
                //right
                if(y+1 < 7)
                    if(grid2[x][y+1] == 1)
                        cnt++;
                // right down
                if(x+1 < 7 && y+1 < 7)
                    if(grid2[x+1][y+1] == 1)
                        cnt++;
                // down
                if(x+1 < 7)
                    if(grid2[x+1][y] == 1)
                        cnt++;
                // left down
                if(x+1 < 7 && y-1 >= 0)
                    if(grid2[x+1][y-1] == 1)
                        cnt++;
                // left
                if(y-1 >= 0)
                    if(grid2[x][y-1] == 1)
                        cnt++;
                // keft up
                if(x-1 >= 0 && y-1 >= 0)
                    if(grid2[x-1][y-1] == 1)
                        cnt++;

        cout << cnt;
}
void bleh(int s[],int b[]){
    int record[7][7] = {0};
    int cnt = 0;
        for(int x2 = 0;x2 < 7;x2++){
            for(int y2 = 0;y2 < 7;y2++){
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

        for(int x2 = 0;x2 < 7;x2++){
            for(int y2 = 0;y2 < 7;y2++){
                if(grid[x2][y2] == 1){
                    //survival
                    bool test = 1;
                    for(int t = 0;t < rs;t++){
                        if(record[x2][y2] == s[t]){
                            grid[x2][y2] = 1;
                            test = 0;
                            continue;
                        }
                    }
                    if(test){
                        grid[x2][y2] = 0;
                    }
                }
                else{
                    //birth
                    bool test = 1;
                    for(int t = 0;t < rb;t++){
                        if(record[x2][y2] == b[t]){
                            grid[x2][y2] = 1;
                            test = 0;
                            continue;
                        }
                    }
                    if(test){
                        grid[x2][y2] = 0;
                    }
                }
            }

        }
}

int main(){
    //freopen("input.txt","r",stdin);
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> x >> y;
        x--;
        y--;
        grid[x][y] = 1;
        grid2[x][y] = 1;
    }
    cin >> rb;
    int b[rb];//lol
    for(int i = 0;i < rb;i++){
        cin >> b[i];
    }
    cin >> rs;
    int s[rs];
    for(int i = 0;i < rs;i++){
        cin >> s[i];
    }
    bleh(s,b);

    for(int i = 0;i < 5;i++){
        cin >> x >> y;
        x--;
        y--;
        buu();

        if(grid[x][y] == 1)
            cout << "A" << endl;
        else
            cout << "D" << endl;

    }

    //fclose(stdin);
    return 0;

}

