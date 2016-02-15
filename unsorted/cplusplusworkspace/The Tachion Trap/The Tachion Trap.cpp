#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<algorithm>
#define x first
#define y second
#define sgn(x) (0 < x) - (x < 0)
#define cross(A,O,B) sgn((A.x - O.x)*(B.y - O.y) - (A.y - O.y)*(B.x - O.x))
using namespace std;

typedef pair<int,int>point;
struct line_segment{
    point A;
    point B;
    line_segment(){A = point(0,0), B = point(0,0);}
    line_segment(point _A,point _B){
        A = _A,B = _B;
    }
    bool intersects(line_segment ln){
        if(A == ln.A || A == ln.B || B == ln.A || B == ln.B)
          return false;
        else if(cross(A,ln.A,ln.B) == cross(B,ln.A,ln.B))
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

const int MAXN = 10;
int N,cnt;
point arr[MAXN];
vector<line_segment>lines;

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&N);
    for(int i = 0;i < N;i++)
      scanf("%d%d",&arr[i].x,&arr[i].y);
    sort(&arr[0]+1,&arr[0]+N);
    do{
        for(int i = 0;i < N;i++){
            lines.push_back((line_segment){arr[i],arr[(i+1)%N]});
            for(int j = 0;j < i;j++)
              if(lines[i].intersects(lines[j]))
                  goto end;
        }cnt++;
        end:lines.clear();
    }while(next_permutation(&arr[0]+1,&arr[0]+N));
    printf("%d\n",cnt/2);
    return 0;
}