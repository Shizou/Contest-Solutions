#include<iostream>
#include<cstdio>
#include<string>
#include<set>
#include<queue>
#include<cstring>
using namespace std;
bool g[50][50];
bool v[50];
int x,y,cnt;
string s;
struct path{
    int p,d;
};
void init(){
    g[1][6] = 1;   g[6][1] = 1;
	g[2][6] = 1;   g[6][2] = 1;
	g[3][6] = 1;   g[6][3] = 1;
	g[4][6] = 1;   g[6][4] = 1;
	g[5][6] = 1;   g[6][5] = 1;
	g[7][6] = 1;   g[6][7] = 1;
	g[3][4] = 1;   g[4][3] = 1;
	g[4][5] = 1;   g[5][4] = 1;
	g[3][5] = 1;   g[5][3] = 1;
	g[3][15] = 1;  g[15][3] = 1;
	g[13][15] = 1; g[15][13] = 1;
	g[14][13] = 1; g[13][14] = 1;
	g[12][13] = 1; g[13][12] = 1;
	g[7][8] = 1;   g[8][7] = 1;
	g[8][9] = 1;   g[9][8] = 1;
	g[9][10] = 1;  g[10][9] = 1;
	g[9][12] = 1;  g[12][9] = 1;
	g[10][11] = 1; g[11][10] = 1;
    g[11][12] = 1; g[12][11] = 1;
	g[16][17] = 1; g[17][16] = 1;
	g[16][18] = 1; g[18][16] = 1;
	g[18][17] = 1; g[17][18] = 1;
}
int main(){
    //freopen("input.txt","r",stdin);
    init();
    string t = "";
    while(true){
        getline(cin,s);
        if(s[0] == 'i'){
            cin >> x >> y;
            g[x][y] = 1;
            g[y][x] = 1;
        }
        else if(s[0] == 'd'){
            cin >> x >> y;
            g[x][y] = 0;
           // g[y][x] = 0;
        }
        else if(s[0] == 'n'){
            cin >> x;
            cnt = 0;
            for(int i = 1;i < 50;i++){if(g[x][i] == 1){cnt++;}}
            cout << cnt << endl;
        }
        else if(s[0] == 'f'){
            cin >> x;
            cnt = 0;
            set<int>set;
            set.insert(x);
            for(int i = 1;i < 50;i++){ if(g[x][i] == 1){ set.insert(i);}}

            for(int i = 1;i < 50;i++){
                if(g[x][i] == 1){
                    for(int j = 1;j < 50;j++)
                        if(g[i][j] == 1 && set.find(j) == set.end()) {
                            cnt++;
                        }
                }
            }
            cout << cnt << endl;
            set.clear();
        }
        else if(s[0] == 's'){
            cin >> x >> y;
            queue< path > q;
            q.push((path){x,0});
            memset(v,0,sizeof v);
            bool con = 0;
            while(!q.empty()){
                int p = q.front().p;
                int d = q.front().d;
                q.pop();
                if(v[p]) continue;
                if(p == y){
                    cout << d << endl;
                    con = 1;
                    break;
                }
                v[p] = 1;
                for(int i = 1;i < 50;i++)
                    if(g[p][i] == 1)
                        q.push( (path){i,d+1});

            }
            if(!con){
                cout << "Not connected" << endl;
            }

        }
        else
            break;
        getline(cin,t);
        s = "";
    }
   //fclose(stdin);
    return 0;
}
