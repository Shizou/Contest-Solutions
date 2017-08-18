/*
William Granados
Woburn Collegiate Institute
ACSL 2013-2014, Contest #3
Intermediate Division
Program: Fanorona
*/
#include<iostream>
#include<cmath>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
char g[5][5];
int  v[5][5];
int n,x,y,p,cnt,m,tmp;
bool a;
vector<int>num;
void in(char c){
    cin >> n;
        for(int i = 0;i < n;i++){
            cin >> p;
            x = 0; y = 0;
            p%5 == 0 ? x = p/5: x = ceil((double)p/5);
            p%5 == 0 ? y = 5: y = p%5;
            g[x-1][y-1] = c;
        }
}
void out(){
     if(num.size() > 1){
        for(int i = 0;i < num.size()-1;i++)cout << num[i]<< ", ";
                cout << num[num.size()-1];
        }
        else if(num.size() == 1)  cout << num[num.size()-1];
}

void fw(){
 cnt = 0;
        for(x = 0;x < 5;x++){
            for(y = 0;y < 5;y++){
                cnt++;
                if(g[x][y] == 'w'){
                    if(cnt == 21 || cnt == 17 || cnt == 13 || cnt == 9){
                        num = vector<int>();
                        if( y+2 < 5 && g[x-1][y+1] == '.'){
                            for(int i = 2;i < 5;i++){
                                if(g[x-i][y+i] == 'b') {num.push_back(v[x-i][y+i]); a = 0;}
                                else                   break;
                            }
                            sort(num.begin(),num.end());
                            out();
                        }
                        if( y-2 >= 0 && g[x-1][y-1] == '.'){
                            for(int i = 2;i < 5;i++){
                                if(g[x+i][y-i] == 'b') {num.push_back(v[x+i][y-i]); a = 0;}
                                else                   break;
                            }
                            sort(num.begin(),num.end());
                            out();
                        }

                    }
                    if(cnt == 25 || cnt == 19 || cnt == 13 || cnt == 7){
                        num = vector<int>();
                        if(y-2 >= 0 && g[x-1][y-1] == '.'){
                            for(int i = 2;i < 5;i++){
                                if(g[x-i][y-i] == 'b') {num.push_back(v[x-i][y-i]); a = 0;}
                                else                   break;
                            }
                            sort(num.begin(),num.end());
                            out();
                        }
                        if( y+2 < 5 && g[x+1][y+1] == '.'){
                            for(int i = 2;i < 5;i++){
                                if(g[x+i][y+i] == 'b') {num.push_back(v[x+i][y+i]); a = 0;}
                                else                   break;
                            }
                            sort(num.begin(),num.end());
                            out();
                        }
                    }
                       //left
                       if( y-2 >= 0 && g[x][y-1] == '.'){
                             num = vector<int>();
                           for(int i = 2;i < 5;i++){
                                if(g[x][y-i] == 'b') {num.push_back(v[x][y-i]); a = 0;}
                                else                 break;
                            }
                            sort(num.begin(),num.end());
                            out();
                        }
                        //right
                       if(y+2 < 5 && g[x][y+1] == '.'){
                            num = vector<int>();
                            for(int i = 2;i < 5;i++){
                                if(g[x][y+i] == 'b') {num.push_back(v[x][y+i]); a = 0;}
                                else                 break;
                            }
                            sort(num.begin(),num.end());
                            out();
                        }
                        //up
                        if(x-2 >= 0 && g[x-1][y] == '.'){
                            num = vector<int>();
                            for(int i = 2;i < 5;i++){
                                if(g[x-i][y] == 'b') {num.push_back(v[x-i][y]); a = 0;}
                                else                 break;
                            }
                            sort(num.begin(),num.end());
                            out();
                        }
                        // down
                        if(x+2 >= 0 && g[x+1][y] == '.'){
                            num = vector<int>();
                            for(int i = 2;i < 5;i++){
                                if(g[x+i][y] == 'b') {num.push_back(v[x+i][y]); a = 0;}
                                else                 break;
                            }
                            sort(num.begin(),num.end());
                            out();
                        }
                }
            }
        }
}
void bw(){
    cnt = 0;
        for(x = 0;x < 5;x++){
            for(y = 0;y < 5;y++){
                cnt++;
                if(g[x][y] == 'w'){
                    if(cnt == 21 || cnt == 17 || cnt == 13 || cnt == 9){
                        num = vector<int>();
                        if( y+2 < 5 && y-1 >= 0 && g[x-1][y+1] == 'b' && g[x+1][y-1] == '.'){
                            for(int i = 1;i < 5;i++){
                                if(g[x-i][y+i] == 'b') {num.push_back(v[x-i][y+i]); a = 0;}
                                else                   break;
                            }
                            sort(num.begin(),num.end());
                            out();
                        }
                        if( y-2 >= 0 && y+1 < 5 && g[x+1][y-1] == 'b' && g[x-1][y+1] == '.'){
                            for(int i = 1;i < 5;i++){
                                if(g[x+i][y-i] == 'b') {num.push_back(v[x+i][y-i]); a = 0;}
                                else                   break;
                            }
                            sort(num.begin(),num.end());
                            out();
                        }
                    }
                    if(cnt == 25 || cnt == 19 || cnt == 13 || cnt == 7){
                        num = vector<int>();
                        if(y-2 >= 0 && y+1 < 5 && g[x-1][y-1] == 'b' && g[x+1][y+1] == '.'){
                            for(int i = 1;i < 5;i++){
                                if(g[x-i][y-i] == 'b') {num.push_back(v[x-i][y-i]); a = 0;}
                                else                   break;
                            }
                            sort(num.begin(),num.end());
                            out();
                        }
                        if(y+2 < 5 && y-1 >= 0 && g[x+1][y+1] == 'b' && g[x-1][y-1] == '.'){
                            for(int i = 1;i < 5;i++){
                                if(g[x+i][y+i] == 'b') {num.push_back(v[x+i][y+i]); a = 0;}
                                else                   break;
                            }
                            sort(num.begin(),num.end());
                            out();
                        }
                    }
                       //left
                       if( y-2 >= 0 && y+1 < 5 && g[x][y-1] == 'b' && g[x][y+1] == '.'){
                             num = vector<int>();
                           for(int i = 1;i < 5;i++){
                                if(g[x][y-i] == 'b') {num.push_back(v[x][y-i]); a = 0;}
                                else                 break;
                            }
                            sort(num.begin(),num.end());
                            out();
                        }
                        //right
                       if(y+2 < 5 && y-1 >= 0 && g[x][y+1] == 'b' && g[x][y-1] == '.'){
                            num = vector<int>();
                            for(int i = 1;i < 5;i++){
                                if(g[x][y+i] == 'b') {num.push_back(v[x][y+i]); a = 0;}
                                else                 break;
                            }
                            sort(num.begin(),num.end());
                            out();
                        }
                        //up
                        if(x-2 >= 0 && x+1 < 5 &&  g[x-1][y] == 'b' && g[x+1][y] == '.'){
                            num = vector<int>();
                            for(int i = 1;i < 5;i++){
                                if(g[x-i][y] == 'b') {num.push_back(v[x-i][y]); a = 0;}
                                else                 break;
                            }
                            sort(num.begin(),num.end());
                            out();
                        }
                        // down
                        if(x+2 >= 0 && x-1 < 5 &&  g[x+1][y] == 'b' && g[x-1][y] == '.'){
                            num = vector<int>();
                            for(int i = 1;i < 5;i++){
                                if(g[x+i][y] == 'b') {num.push_back(v[x+i][y]); a = 0;}
                                else                 break;
                            }
                            sort(num.begin(),num.end());
                            out();
                        }
                }
            }
        }
}
int main(){
    int wu = 5;
    cnt=1;
    for(x = 0;x < 5;x++){ for(y = 0;y < 5;y++){v[x][y] = cnt; cnt++;}}
    while(wu--){
        memset(g, '.', sizeof g);
        in('w');
        in('b');
        cnt=1;
        a = 1;
        fw();
        bw();
        if(a) cout << "NONE" << endl;
        else  cout << endl;
    }
    return 0;
}
