#include<iostream>
#include<fstream>
#include <stdlib.h>
#include<vector>

using namespace std;

vector< pair< int,int> > ranks;
int main(){
    //freopen("input.txt","r",stdin);
    int x,y;
    cin >> x >> y;
    string g[x];
    getline(cin,g[0]);
    for(int i = 0;i < x;i++){
        getline(cin,g[i]);
    }
    for(int i = 0;i < 9;i++)
        ranks.push_back( make_pair(i+1, 0));

    int r = 1;
    int num = 0;
    bool v = 0;
    string ss = "";
    for(int i = y-2;i > 0;i--){
        v = 0;
        for(int j = 0;j < x;j++){
            if(g[j][i] != '.' && g[j][i] != 'F'){
                ss+= g[j][i];
                num = atoi(ss.c_str())-1;
                ranks[num].second = r;
                g[j].replace(i-2,3,"...");
                v = 1;
                ss = "";
            }
        }
        if(v == 1)
            r++;
        ss = "";
    }
    for(int i = 0;i < 9;i++)
        cout << ranks[i].second << endl;

    //fclose(stdin);
    return 0;
}
