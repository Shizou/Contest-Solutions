#include<stdio.h>
#include<vector>

using namespace std;

struct point{
    int x,y;
};
struct line{
    double a,b,c;
};

int N,x1,x2,y1,y2;
vector< point > points;
line current;

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d",&N);
    for(int i = 0;i < N;i++){
        scanf("%d%d",&x1,&y1);
        points.push_back( (point){x1,y1});
    }
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
}
