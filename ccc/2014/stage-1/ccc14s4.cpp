#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define db 1
#define lb(x) ((x)&(-x))
#define all(x) (x).begin(),(x).end()
#define needforspeed ios::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define pb push_back
#define mp make_pair
#define LL long long
using namespace std;


struct line{
    int x,id;
    int y1,y2;
    int tint,type;
    line(int _x,int _y1,int _y2,int _tint,int _id, int _type){
        x = _x;
        y1 = _y1,y2 = _y2;
        id = _id,tint = _tint, type = _type;
    }
    bool operator < (const line&rht)const{
       return x == rht.x ? type < rht.type:x < rht.x;
    }
};
struct point{
   int y,id;
   int tint,type;
   point(int _y,int _id,int _tint,int _type){
         y = _y,id = _id;
         tint = _tint, type = _type;
   }
   bool operator < (const point&rht)const{
       return y == rht.y ? type < rht.type:y < rht.y;
    }
};


const int START = 1,END = -1;
int N,T;
LL ANS;
vector<line> segments;

int main(){
    //freopen("Input/s4.1.in","r",stdin);
    needforspeed;
    cin >> N >> T;
    for(int i = 0,x1,y1,x2,y2,t,id = 0;i < N;i++){
        cin >> x1 >> y1 >> x2 >> y2 >> t;
        segments.pb( (line){x1,y1,y2,t,id,START});
        segments.pb( (line){x2,y1,y2,t,id,END});
        id++;
    }
    sort(all(segments));
    vector<point>y_axis;
    for(int i = 0;i < (int)segments.size();i++){
       if(i > 0){
          LL delta_x = abs(segments[i].x-segments[i-1].x);
          LL ctint = 0,delta_y = 0;
          for(int j = 0;j < (int)y_axis.size();j++){
              if(j > 0){
                delta_y = y_axis[j].y - y_axis[j-1].y;
                if(ctint >= T)
                   ANS += delta_x*delta_y;

                if(y_axis[j].type == START)
                   ctint += y_axis[j].tint;
                else
                   ctint -= y_axis[j].tint;
              }
              else
                 ctint+=y_axis[j].tint;

          }
          if(segments[i].type == START){
             y_axis.pb((point){segments[i].y1,segments[i].id,segments[i].tint,START});
             y_axis.pb((point){segments[i].y2,segments[i].id,segments[i].tint,END});
             sort(all(y_axis));
          }
          if(segments[i].type == END){
             for(int j = 0;j < (int)y_axis.size();j++){
                 if(segments[i].id == y_axis[j].id){
                    y_axis.erase(y_axis.begin()+j);
                    j--;
                 }
             }
          }
       }
       else{
         y_axis.pb((point){segments[i].y1,segments[i].id,segments[i].tint,START});
         y_axis.pb((point){segments[i].y2,segments[i].id,segments[i].tint,END});
         sort(all(y_axis));
       }
    }
    cout << ANS << endl;
    return 0;
}

