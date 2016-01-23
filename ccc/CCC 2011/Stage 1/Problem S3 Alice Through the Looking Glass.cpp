#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

bool cryst(int m,int x,int y){
    if(m == 0) return false;

    if(x > pow(5,m-1) && x < 5*pow(5,m-1) && y < 3*pow(5,m-1) ){
        //left
        if( x > pow(5,m-1)  && x <= 2*pow(5,m-1) && y <= pow(5,m-1)){
            return true;
        }
        //right
        if(  x < 5*pow(5,m-1) && x >= 3*pow(5,m-1) && y <= pow(5,m-1)){
            return true;
        }//middle
        if( x > 2*pow(5,m-1) && x < 4*pow(5,m-1) && y <= 2*pow(5,m-1)){
            return true;
        }

        if(cryst(m-1,x%(int)pow(5,m-1),y%(int)pow(5,m-1))){
            return true;
        }

    }

    return false;
}
int main(){
    //freopen("input.txt","r",stdin);
    int m,n,x,y;
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> m >> x >> y;
        if( cryst(m,x+1,y+1))
            cout << "crystal" << endl;
        else
            cout << "empty" << endl;
    }
    //fclose(stdin);
    return 0;
}
