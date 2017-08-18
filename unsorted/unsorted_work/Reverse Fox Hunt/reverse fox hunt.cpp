    #include <iostream>
    #include <cstdio>
    #include <cstring>
    #include <vector>
    #include <queue>
    #define fill2D(v) for(int i = 0; i < 6;i++)for(int j = 0; j < 6;j++)v[i][j] = false;
    #define reset(g) for(int i = 0; i < 6;i++)g[i] = "      ";
    using namespace std;

    int R,C,T,D;
    int fr,fc;
    string g[6];
    string in_id;
    bool v[6][6];


    bool pos_path(string g[6]){
        fill2D(v);
        queue< pair<int,int> > q2;
        q2.push( make_pair(fr,fc));
        while(!q2.empty()){
            int r = q2.front().first;
            int c = q2.front().second;
            q2.pop();
            if(r < 0 || c < 0 || r > R-1 || c > C-1)continue;
            if(v[r][c])continue;
            v[r][c]=true;
            if(g[r][c] == 'X' || g[r][c] == 'T')continue;
            if(g[r][c] == 'H')return true;
            q2.push( make_pair(r+1,c));
            q2.push( make_pair(r-1,c));
            q2.push( make_pair(r,c+1));
            q2.push( make_pair(r,c-1));
        }
        return false;
    }

int main(){
        //freopen("input.txt","r",stdin);
        cin >> T;
        reset(g);
        while(T--){
            cin >> R >> C;
            for(int r = 0; r < R;r++){
                for(int c = 0; c < C;c++){
                    cin >> g[r][c];
                    if(g[r][c] == 'F'){fr = r;fc = c;}
                }
            }
            D = 4;
            // try no foxen
            if(!pos_path(g)){
                D = 0;
                goto end;
            }
            // try one foxen
            for(int r = 0; r < R;r++){
                for(int c = 0; c < C;c++){
                    if(g[r][c] == 'G'){
                        g[r][c] = 'X';
                        if(!pos_path(g)){
                            D = 1;
                            goto end;
                        }
                        g[r][c] = 'G';
                    }
                }
            }
            // try two foxen
            for(int r = 0; r < R;r++){
                for(int c = 0; c < C;c++){
                    for(int r2 = 0; r2 < R;r2++){
                        for(int c2 = 0; c2 < C;c2++){
                            if(g[r][c] == 'G' && g[r2][c2] == 'G'){
                                g[r][c] = g[r2][c2] = 'X';
                                if(!pos_path(g)){
                                    D = 2;
                                    goto end;
                                }
                                g[r][c] = g[r2][c2] = 'G';
                            }
                        }
                    }
                }
            }
            // try three foxen
            for(int r = 0; r < R;r++){
                for(int c = 0; c < C;c++){
                    for(int r2 = 0; r2 < R;r2++){
                        for(int c2 = 0; c2 < C;c2++){
                            for(int r3 = 0; r3 < R;r3++){
                                for(int c3 = 0; c3 < C;c3++){
                                    if(g[r][c] == 'G' && g[r2][c2] == 'G' && g[r3][c3] == 'G'){
                                        g[r][c] = g[r2][c2] = g[r3][c3] = 'X';
                                        if(!pos_path(g)){
                                            D = 3;
                                            goto end;
                                        }
                                        g[r][c] = g[r2][c2] = g[r3][c3] = 'G';
                                    }
                                }
                            }
                        }
                    }
                }
            }
            end: cout << D << endl;
        }

        return 0;
    }
