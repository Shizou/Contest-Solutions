#include<iostream>
#include<fstream>

using namespace std;

int main(){
    //freopen("input.txt","r",stdin);
    bool g[3] = {1,0,0};
    string s;
    getline(cin,s);
    bool t = 0;
    for(int i = 0;i < s.size();i++){
        if(s.at(i) == 'A') {
            t = g[0];
            g[0] = g[1];
            g[1] = t;
        }
        else if(s.at(i) == 'B'){
            t = g[1];
            g[1] = g[2];
            g[2] = t;
        }
        else if(s.at(i) == 'C'){
            t = g[0];
            g[0] = g[2];
            g[2] = t;
        }
    }
    if(g[0])
        cout << 1 << endl;
    else if(g[1])
        cout << 2 << endl;
    else if(g[2])
        cout << 3 << endl;

    //fclose(stdin);
    return 0;
}
