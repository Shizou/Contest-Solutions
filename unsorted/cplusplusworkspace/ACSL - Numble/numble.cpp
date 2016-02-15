/*
William Granados
Woburn Collegiate Institute
ACSL 2013-2014, Contest #4
Intermediate Division
Program: Acsl Numble
*/

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int v1[7],v2[7];
int g[7][7];
string s1,s2;
int a,b,c;

void bub1(){
    int e,t;
    for(int i = 0;i < 6;i++){
        e = 0;
        for(int j = 0;j < 6 ;j++){
            if(v1[j] < v1[j+1]){
                t = v1[j];
                v1[j] = v1[j+1];
                v1[j+1] = t;
                e++;
            }
        }
        if(e == 0)break;
    }
}
void bub2(){
    int e,t;
    for(int i = 0;i < 6;i++){
        e = 0;
        for(int j = 0;j < 6 ;j++){
            if(v2[j] < v2[j+1]){
                t = v2[j];
                v2[j] = v2[j+1];
                v2[j+1] = t;
                e++;
            }
        }
        if(e == 0)break;
    }
}

int main(){
    freopen("input.txt","r",stdin);
    cin >> s1 >> s2;
    for(int i = 0;i < 7;i++){
        v1[i] = s1[i]-'0';
        v2[i] = s2[i]-'0';
    }
    getline(cin,s1);
    cin >> a >> b >> c;
    bub1();
    bub2();
    int n = -1;
    for(int i = 0;i < 7;i++){
        for(int j = 0;j < 7;j++){
            g[i][j] = -1;
        }
    }
    for(int i = 0;i < 7;i++){
        if(v2[i] >= c){
            n++;
        }
        else break;
    }
    int m = 0;
    for(int i = 0;i < a;i++){
        g[n][i] = v1[i];
        if(v1[i] == c)m = i;
    }
    for(int i = 0;i < b;i++){
        g[i][m] = v2[i];
    }

    for(int i = 0;i < 7;i++){
        for(int j = 0;j < 7;j++){
            if(g[i][j] == -1) cout << " ";
            else cout << g[i][j];
        }
        cout << endl;
    }

    fclose(stdin);
    return 0;
}
