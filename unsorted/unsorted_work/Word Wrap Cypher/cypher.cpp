#include <iostream>
#include <cstdio>
#include <cctype>

using namespace std;

int R,C,it;
string in;
string g[100];

void init(){
    cin >> C;
    getline(cin,in);
    getline(cin,in);
    R = in.size()/C;
    for(int i = 0; i < R;i++){
        g[i] = "";
        for(int j = 0;j < C;j++){
            g[i] += ".";
        }
    }
    for(int i = 0;i < C;i++)
        for(int j = 0;j < R;j++)
            g[j][i] = in[it++];
}
void print_array(){
    for(int i = 0;i < R;i++){
        for(int j = 0; j < C;j++){
            cout << g[i][j];
        }
        cout << endl;
    }
    cout << endl;
}
int main(){
    freopen("input.txt","r",stdin);
    //for(int k = 0; k < 5;k++){
        init();
        print_array();
        for(int i = 0;i < R;i++){
            int space_count = 0;
            for(int j = 0; j < C && g[i][j] == '_';j++)
                space_count++;
            g[i].erase(0,space_count);
            while(space_count--)
                g[i].append("_");

            for(int j = 0;j < C;j++)
                g[i][j] = (g[i][j] == '_') ? ' ' : g[i][j];

        }
        string out;
        for(int i = 0;i < R;i++)
            out+=g[i];
        for(int i = 0;i < out.size()-1;i++){
            if(out[i] == '_' && out[i+1] == '_'){
                out.erase(i,1);
                i--;
            }
        }
        cout << out << endl;
        print_array();
   // }
    return 0;
}
