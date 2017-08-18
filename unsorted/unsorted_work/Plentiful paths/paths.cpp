#include<iostream>
using namespace std;
int row,col,c,d;
bool g[100][100];
bool v[100][100];
int ap;
int search(int x,int y,int a){
    if(x > row-1 || y > col-1)return 0;
    if(v[x][y])return 0;
    if(g[x][y])a++;
    if(x == col-1 && y == col-1){
        if(a > ap)ap = a;
        return 0;
    }
    v[x][y]=1;
    return search(x+1,y,a) + search(x,y+1,a);
}
int main(){
    cin >> row >> col;
    while(true){
        cin >> c >> d;
        if(c == 0 && d == 0) break;
        g[c-1][d-1]=1;//GCD WAWOWAOW
    }
    search(0,0,0);
    if(g[row-1][col-1]) ap++;
    cout << ap << endl;
    return 0;
}
