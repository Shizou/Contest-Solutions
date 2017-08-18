#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#define x first
#define y second
#define sgn(x) (0<x) - (x < 0)
#define cross(A,O,B) sgn((A.x-O.x)*(B.y-O.y) - (A.y-O.y)*(B.x-O.x))
using namespace std;

typedef pair<int,int>point;
struct line_segment{
    point A;
    point B;
    line_segment(){}
    line_segment(point _A,point _B){
        A = _A, B = _B;
    }
    bool intersects(line_segment ln){
      if(A == ln.A || A == ln.B || B == ln.A || B == ln.B)return false;
      return cross(A,ln.A,ln.B)*cross(B,ln.A,ln.B) <= 0 &&
             cross(ln.A,A,B)*cross(ln.B,A,B) <= 0;
    }
};
struct shape{
  line_segment seg[3];
  shape(line_segment ln1,line_segment ln2, line_segment ln3){
    seg[0] = ln1,seg[1] = ln2, seg[2] = ln3;
  }
  bool intersects(line_segment ln){
    for(int i = 0;i < 3;i++)
      if(ln.intersects(seg[i]))
         return true;
    return false;
  }
};

const int MAXN = 1000;
int T,N,F,xs,ys,xd,yd,cnt;
point arr[MAXN];
line_segment line;
vector<line_segment>lines;
vector<shape>shapes;

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d",&T);
    while(T--){
      scanf("%d%d",&N,&F);
      scanf("%d%d%d%d",&xs,&ys,&xd,&yd);
      line = (line_segment){point(xs,ys),point(xs+xd*F,ys+yd*F)};
      for(int i = 0;i < N;i++)
          scanf("%d%d",&arr[i].x,&arr[i].y);
      for(int i = 0;i < N;i++)
          lines.push_back((line_segment){arr[i],arr[(i+1)%N]});
      for(int i = 0,c = 0;i < N;i++){
          if(c<3){
            c++;
            continue;
          }else{
            shapes.push_back((shape){lines[i],lines[i-1],lines[i-2]});
            c = 0;
          }
      }
      for(int i = 0;i < (int)shapes.size();i++){
        if(shapes[i].intersects(line))
            cnt++;
      }
      lines.clear();
      shapes.clear();
      printf("%d\n",cnt);cnt = 0;
    }
    return 0;
}