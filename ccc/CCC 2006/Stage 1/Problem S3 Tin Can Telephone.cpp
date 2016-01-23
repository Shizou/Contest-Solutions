#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define x first
#define y second
#define sgn(x) (0 < x) - (x < 0)
#define cross(A,O,B) sgn((A.x - O.x)*(B.y - O.y) - (A.y - O.y)*(B.x - O.x))
using namespace std;

typedef pair<int,int> point;

struct line_segment{
    point A;
    point B;
    line_segment(){A = point(0,0), B = point(0,0);}
    line_segment(point _A,point _B){
        A = _A,B = _B;
    }
    bool intersects(line_segment ln){
        if(cross(A,ln.A,ln.B) == cross(B,ln.A,ln.B))
            return false;
        else if(cross(A,B,ln.A) == cross(A,B,ln.B))
            return false;
        else
            return true;
    }
    void operator = (const line_segment &ln){
        A = ln.A,B = ln.B;
    }
};

const int MAXN = 32;
int xr,yr,xj,yj,cnt,N,E;
point arr[MAXN];
line_segment line;
vector<line_segment>lines;

int main(){
    scanf("%d%d%d%d%d",&xr,&yr,&xj,&yj,&N);
    line = (line_segment){point(xr,yr),point(xj,yj)};
    for(int i = 0;i < N;i++){
        scanf("%d",&E);
        for(int j = 0;j < E;j++)
            scanf("%d%d",&arr[j].x,&arr[j].y);
        for(int j = 0;j < E;j++)
            lines.push_back((line_segment){arr[j],arr[(j+1)%E]});
        for(int j = 0;j < (int)lines.size();j++){
            if(line.intersects(lines[j])){
                cnt++;
                break;
            }
        }
        lines.clear();
    }
    printf("%d\n",cnt);
    return 0;
}