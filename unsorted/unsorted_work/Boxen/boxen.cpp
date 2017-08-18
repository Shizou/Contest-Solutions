#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
#define x first
#define y second
#define pb push_back
#define mp make_pair
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
        return (cross(A,B,ln.B)!=cross(B,ln.A,ln.B))^(cross(A,B,ln.A)!=cross(A,B,ln.B));
    }
    void operator = (const line_segment &ln){
        A = ln.A,B = ln.B;
    }
};
struct box{
  line_segment side[4];
  point A,B;
  int id;
  box(int x,int y,int w,int h,int _id){
      side[0] = (line_segment){ point(x,y),  point(x+w,y)};
      side[1] = (line_segment){ point(x,y),  point(x,y+h)};
      side[2] = (line_segment){ point(x,y+h),point(x+w,y+h)};
      side[3] = (line_segment){ point(x+w,y),point(x+w,y+h)};
      A = mp(x,y),B = mp(x+w,y+h);
      id = _id;
  }
  int intersects(line_segment ln){
    for(int i = 0;i < 4;i++)
      if(ln.intersects(side[i]))
          return i;
    return -1;
  }
  bool operator < (box &bx)const{
      return (A == bx.A) ? (B < bx.B): A < bx.A;
  }
};
bool compare(box A,box B){return A < B;}


int N,sx,sy;
line_segment ln;
vector<box>v;

int main(){
   freopen("input.txt","r",stdin);
   scanf("%d%d%d",&N,&sx,&sy);
   ln = (line_segment){mp(0,0),mp(sx,sy)};
   for (int i = 0,x,y,w,h; i < N; ++i){
      scanf("%d%d%d%d",&x,&y,&w,&h);
      v.pb((box){x,y,w,h,i+1});
   }
   sort(v.begin(),v.end(),compare);
   for(int i = 0;i < (int)v.size();i++){
      if(v[i].intersects(ln) != -1){
          printf("%d\n",v[i].id);
      }
   }
   return 0;
}