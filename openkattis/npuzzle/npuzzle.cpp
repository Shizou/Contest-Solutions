#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;

int sd;
string a[] = {"ABCD","EFGH","IJKL","MNO."},b[4];
map< char, pair<int,int> >m;

int main() {
    freopen("input.txt","r",stdin);
    for(int i = 0; i < 4;i++)
         cin >> b[i];
    for(int r = 0; r < 4;r++)
        for(int c = 0; c < 4;c++)
            m[a[r][c]] = make_pair(r,c);
    for(int r = 0; r < 4;r++)
        for(int c = 0; c < 4;c++)
            if(b[r][c] != '.')
                sd += abs(r-m[b[r][c]].first) + abs(c-m[b[r][c]].second);
    cout << sd << endl;
    return 0;
}