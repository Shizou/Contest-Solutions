#include<iostream>
#include<fstream>

using namespace std;

int main(){
    //freopen("input.txt","r",stdin);
    int n; cin >> n;
    string g[n];
    bool ongoing = true;
    getline(cin,g[0]);

    for(int x = 0;x < n;x++)
        getline(cin,g[x]);

    for(int x = 0;x < n && ongoing;x++){
        for(int y = 0;y < n && ongoing;y++){
            if(x-2 > 0){
                if(g[x][y] != '.'){
                    if(g[x][y] == g[x-1][y] && g[x][y] == g[x-2][y]){
                        cout << g[x][y] << endl;
                        ongoing = 0;
                    }
                }
            }
            else if(x+2 < n){
                if(g[x][y] != '.'){
                    if(g[x][y] == g[x+1][y] && g[x][y] == g[x+2][y]){
                        cout << g[x][y] << endl;
                        ongoing = 0;
                    }
                }
            }
            else if(y-2 > 0){
                if(g[x][y] != '.'){
                    if(g[x][y] == g[x][y-1] && g[x][y] == g[x][y-1]){
                        cout << g[x][y] << endl;
                        ongoing = 0;
                    }
                }
            }
            else if(y+2 < n){
                if(g[x][y] != '.'){
                    if(g[x][y] == g[x][y+1] && g[x][y] == g[x][y+2]){
                        cout << g[x][y] << endl;
                        ongoing = 0;
                    }
                }
            }
            else if( x-2 > 0 && y-2 > 0 ){
                if(g[x][y] != '.'){
                    if(g[x][y] == g[x-1][y-1] && g[x][y] == g[x-2][y-2]){
                        cout << g[x][y] << endl;
                        ongoing = 0;
                    }
                }
            }
            else if( x-2 > 0&& y+2 < n){
                if(g[x][y] != '.'){
                    if(g[x][y] == g[x-1][y+1] && g[x][y] == g[x-2][y+2]){
                        cout << g[x][y] << endl;
                        ongoing = 0;
                    }
                }
            }
            else if( x+2 < n&& y+2 < n){
                if(g[x][y] != '.'){
                    if(g[x][y] == g[x+1][y+1] && g[x][y] == g[x+2][y+2]){
                        cout << g[x][y] << endl;
                        ongoing = 0;
                    }
                }
            }
            else if(x+2 < n && y-2 > 0){
                if(g[x][y] != '.'){
                    if(g[x][y] == g[x+1][y-1] && g[x][y] == g[x+2][y-2]){
                        cout << g[x][y] << endl;
                        ongoing = 0;
                    }
                }
            }

        }
    }

    if(ongoing)
        cout << "ongoing" << endl;


    //fclose(stdin);
    return 0;
}
