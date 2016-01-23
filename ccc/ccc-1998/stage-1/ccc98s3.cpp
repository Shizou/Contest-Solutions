#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int dr[] = {1,0,-1,0};
int dc[] = {0,1,0,-1};

int N,cmd,r,c,d;


void turn_right(){
    printf("2\n");
}
void turn_left(){
    printf("3\n");
}
void ahead(int x){
    printf("1\n%d\n",x);
}


int main(){
   // freopen("input.txt","r",stdin);
    cin >> N;
    while(N--){
        r = c = d = 0;
        while(cin >> cmd && cmd != 0){
            if(cmd == 1){
                cin >> cmd;
                r += cmd*dr[d];
                c += cmd*dc[d];
            }
            else if(cmd == 2){//turn right
                d++;
                d%=4;
            }
            else if(cmd == 3){//turn left
                d-= (d == 0) ? -3:1;
            }
        }
        int dx = abs(c),dy = abs(r);
        printf("Distance is %d\n",dx+dy);
        if(!(r == 0 && c == 0)){
            if(r > 0){
                if(c > 0){
                    if(d == 0){
                        turn_left();
                        ahead(dx);
                        turn_left();
                        ahead(dy);
                    }
                    else if(d == 1){
                        turn_right();
                        ahead(dy);
                        turn_right();
                        ahead(dx);
                    }
                    else if(d == 2){
                        ahead(dy);
                        turn_right();
                        ahead(dx);
                    }
                    else if(d == 3){
                        ahead(dx);
                        turn_left();
                        ahead(dy);
                    }
                }
                else if(c < 0){
                    if(d == 0){
                        turn_right();
                        ahead(dx);
                        turn_right();
                        ahead(dy);
                    }
                    else if(d == 1){
                        ahead(dx);
                        turn_right();
                        ahead(dy);
                    }
                    else if(d == 2){
                        ahead(dy);
                        turn_left();
                        ahead(dx);
                    }
                    else if(d == 3){
                        turn_left();
                        ahead(dy);
                        turn_left();
                        ahead(dx);
                    }
                }
                else{
                    if(d == 0){
                        turn_left();
                        turn_left();
                        ahead(dy);
                    }
                    else if(d == 1){
                        turn_right();
                        ahead(dy);
                    }
                    else if(d == 2){
                        ahead(dy);
                    }
                    else if(d == 3){
                        turn_left();
                        ahead(dy);
                    }
                }
            }
            else if(r < 0){
                if(c > 0){
                    if(d == 0){
                        ahead(dy);
                        turn_left();
                        ahead(dx);
                    }
                    else if(d == 1){
                        turn_left();
                        ahead(dy);
                        turn_left();
                        ahead(dx);
                    }
                    else if(d == 2){
                        turn_right();
                        ahead(dx);
                        turn_right();
                        ahead(dy);
                    }
                    else if(d == 3){
                        ahead(dx);
                        turn_right();
                        ahead(dy);
                    }
                }
                else if(c < 0){
                    if(d == 0){
                        ahead(dy);
                        turn_right();
                        ahead(dx);
                    }
                    else if(d == 1){
                        ahead(dx);
                        turn_left();
                        ahead(dy);
                    }
                    else if(d == 2){
                        turn_left();
                        ahead(dx);
                        turn_left();
                        ahead(dy);
                    }
                    else if(d == 3){
                        turn_right();
                        ahead(dy);
                        turn_right();
                        ahead(dx);
                    }
                }
                else{
                    if(d == 0){
                        ahead(dy);
                    }
                    else if(d == 1){
                        turn_left();
                        ahead(dy);
                    }
                    else if(d == 2){
                        turn_left();
                        turn_left();
                        ahead(dy);
                    }
                    else if(d == 3){
                        turn_right();
                        ahead(dy);
                    }
                }
            }
        }
        printf("\n");
    }
    return 0;
}
