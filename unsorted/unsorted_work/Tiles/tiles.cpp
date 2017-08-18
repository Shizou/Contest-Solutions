#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

typedef pair<int,int> point;

struct shape{
    point pt[3];
    shape(point pt0,point pt1,point pt2){
      pt[0] = pt0,pt[1] = pt1, pt[2] = pt2;
    }
};

const int MAXN = 256;
int N,X,Y;
bool v[MAXN][MAXN];




void rec(){


}

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d%d%d",&N,&X,&Y);
    v[X][Y] = true;
    rec();
    return 0;
}