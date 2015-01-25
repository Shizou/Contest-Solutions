#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <sstream>
#define MAXR 10
#define MAXC 9
#define to_s(N) static_cast<ostringstream*>( &(ostringstream() << N) )->str()
#define to_i(S) atoi(S.c_str())
using namespace std;


int g[MAXR][MAXC];
string in[MAXR][MAXC];
map<char,int>m;

bool check_alpha(string&s){
	for(int i = 0; i < s.size();i++)if(isalpha(s[i]))return true;
	return false;
}
void split(string &s, vector<string>&arr){
    stringstream test(s);
    string segment;
    while(getline(test,segment,'+')){
        arr.push_back(segment);
    }
}
void init(){
    fill( &g[0][0], &g[0][0] + MAXR*MAXC, -1);
    m['A']=0;m['B']=1;m['C']=2;m['D']=3;
    m['E']=4;m['F']=5;m['G']=6;m['H']=7;
    m['I']=8;m['J']=9;
}
void print_arr(){
    for(int r = 0; r < MAXR;r++){
        for(int c = 0; c < MAXC;c++){
            if(g[r][c]!=-1)printf("%d ",g[r][c]);
            else           printf("* ");
        }
        printf("\n");
    }
}
int main() {
    //freopen("input.txt","r",stdin);
    init();
    for(int r = 0; r < MAXR;r++)
        for(int c = 0; c < MAXC;c++)
            cin >> in[r][c];
    for(int r = 0; r < MAXR;r++){
        for(int c = 0; c < MAXC;c++){
            if(isdigit(in[r][c][0])){
                g[r][c] = to_i(in[r][c]);
                in[r][c] = "";
            }
        }
    }
    int t = 1;
    while(t != 0){
        t = 0;
        for(int r = 0; r < MAXR;r++){
            for(int c = 0; c < MAXC;c++){
                if(g[r][c] == -1){
                    vector<string>qry;
                    split(in[r][c],qry);
                    int ans = 0;
                    for(int k = 0; k < qry.size();k++){

                        int nr = m[qry[k][0]];
                        int nc = to_i(qry[k].substr(1,qry[k].size()-1))-1;
                        //cout << qry[k] << endl;
                        //printf("(%d %d)\n",nr,nc);
                        if(g[nr][nc] == -1)// not initialized reference
                            goto end;
                        else
                            ans+=g[nr][nc];
                    }
                    g[r][c] = ans;
                    in[r][c] = "";
                    t++;
                }
                end:;
            }
        }
    }
    print_arr();
	return 0;
}
