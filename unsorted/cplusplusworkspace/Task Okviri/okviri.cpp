#include<iostream>

using namespace std;
string s;
string g[5];
int main(){
    getline(cin,s);

            g[0] += "..#..";
            g[1] += ".#.#.";
            g[2] += "#."+s.substr(0,1)+".#";
            g[3] += ".#.#.";
            g[4] += "..#..";

    int cnt = 2;
    for(int i = 1;i < s.size();i++){
        if(cnt%3 != 0){
            g[0] += ".#..";
            g[1] += "#.#.";
            g[2] += "."+s.substr(i,1)+".#";
            g[3] += "#.#.";
            g[4] += ".#..";
        }
        else{
            g[0] += ".*..";
            g[1] += "*.*.";
            g[2] += "."+s.substr(i,1)+".*";
            g[3] += "*.*.";
            g[4] += ".*..";
            g[2][i*4] = '*';
            cnt = 0;
        }
        cnt++;
    }
    for(int i = 0;i < 5;i++)
        cout << g[i] << endl;


    return 0;
}
