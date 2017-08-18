#include<iostream>
#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;

int X,Y;
bool NOT_OK;
set<int>OK,BAD;

int main(){
    //freopen("input.txt","r",stdin);
    while(cin >> X >> Y && !(X == -1 && Y == -1)){
        if( X == 0 && Y == 0){
            if(NOT_OK || OK.size()!=1)
                printf("INVALID\n");
            else
                printf("%d\n",*OK.begin());
            OK.clear(),BAD.clear();
            NOT_OK = false;
        }else{
            OK.insert(X);
            if(BAD.count(Y))
                NOT_OK = true;
            BAD.insert(Y);
            if(OK.count(X) && BAD.count(X))
                OK.erase(X);
            if(OK.count(Y) && BAD.count(Y))
                OK.erase(Y);
        }
    }
    return 0;
}